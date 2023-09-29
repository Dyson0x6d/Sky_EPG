#include "RewardsServiceObject.h"
#include "EligibilityServiceStubObject.h"

RewardsServiceObject::RewardsServiceObject(QObject *parent)
    : QObject{parent}
{

}

void    RewardsServiceObject::addRewardsEntry(const RewardsEntryItem& rewardItem)
{
    rewardsEntries.append(rewardItem);
}

RewardsEntryItem RewardsServiceObject::getRewardEntryAt(uint idx) const
{
    if(idx < rewardsEntries.size())
    {
        return rewardsEntries.at(idx);
    }
    else
    {
        return RewardsEntryItem("","");
    }
}

void RewardsServiceObject::addUserDataToInflight(const UserData userData)
{
    inFlightUserRequests.append(userData);
}

void RewardsServiceObject::handleRewardsRequest(UserData userData)
{
    addUserDataToInflight(userData);
    emit requestAccountEligibility(userData.getAccountNumber());
}

bool RewardsServiceObject::isUserDataInflight(const UserData userData)
{
    return inFlightUserRequests.contains(userData);
    return true;
}

void RewardsServiceObject::handleEligibilityResponse(EligibilityServiceType eligibility)
{
    // NOTE: the model seems to suggest that the eligibility response is always for the last account sent
    //       suggestion, return the account number WITH the eligibility response
    //       Instead of a pop, we would find by AccountNum
    UserData latestUser = inFlightUserRequests.last();
    inFlightUserRequests.removeLast();
    RewardsList rewardsForCurrentUser;

    if (eligibility == CUSTOMER_ELIGIBLE)
    {
        for( auto usersChannel : latestUser.getSubscribedChannels())
        {
            for( auto rewardEntry = rewardsEntries.begin(); rewardEntry != rewardsEntries.end(); ++rewardEntry)
            {
                if( rewardEntry->getChannelName() == usersChannel.getChannelName())
                {
                    // TODO check for repeated rewards to eliminate duplicate N/A, etc
                    rewardsForCurrentUser.append(rewardEntry->getNamedReward());
                }
            }
        }
    }
    emit sendRewardsResponse(rewardsForCurrentUser);
}

void RewardsServiceObject::connectUserForRequest(UserObject * user)
{
    QObject::connect(user,
                     SIGNAL(requestAvailableRewards(UserData)),
                     &GetInstance(),
                     SLOT(handleRewardsRequest(UserData))
                     );

    QObject::connect(&GetInstance(),
                     SIGNAL(sendRewardsResponse(RewardsList)),
                     user,
                     SLOT(handleRewardsResponse(RewardsList))
                     );
}

void RewardsServiceObject::connectToEligibilityService()
{
    QObject::connect(&GetInstance(),
                     SIGNAL(requestAccountEligibility(AccountNum)),
                     &(EligibilityServiceStubObject::GetInstance()),
                     SLOT(checkAccountEligibility(AccountNum))
                    );

    QObject::connect(&(EligibilityServiceStubObject::GetInstance()),
                     SIGNAL(sendEligibility(EligibilityServiceType)),
                     &GetInstance(),
                     SLOT(handleEligibilityResponse(EligibilityServiceType))
                     );
}
