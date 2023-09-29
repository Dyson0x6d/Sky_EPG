#include "RewardsServiceObject.h"


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

void RewardsServiceObject::handleRewardsRequest(UserObject userObj)
{
    inFlightUserRequests.append(userObj);
    emit requestAccountEligibility(userObj.getAccountNumber());
}

bool RewardsServiceObject::isUserObjectInflight(const UserObject userObject)
{
    return inFlightUserRequests.contains(userObject);
    return true;
}

void RewardsServiceObject::handleEligibilityResponse(EligibilityServiceType eligibility)
{
    // NOTE: the model seems to suggest that the eligibility response is always for the last account sent
    //       suggestion, return the account number WITH the eligibility response


    // if eligibility == CUSTOMER_ELIGIBLE
    //  build the list of rewards from the users account num
    // remove the account num from the inflight requests
    // inFlightUserRequests.pop_front();
}
