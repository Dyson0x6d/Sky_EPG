#include "RewardsServiceObject.h"

#include "qmap.h"

QMap<AccountNum, ChannelList> inFlightUserRequests;

RewardsServiceObject::RewardsServiceObject(QObject *parent)
    : QObject{parent}
{

}

void    RewardsServiceObject::addRewardsEntry(const RewardsEntryItem& rewardItem)
{
    // check for duplicates
    //rewardsEntries.append(rewardItem);
}


void RewardsServiceObject::handleRewardsRequest(UserObject& usrObj)
{
    // inFlightUserRequests.append (stuff);
    // emit     requestAccountEligibility(usrObj.getAccountNumber());
}

void RewardsServiceObject::handleEligibilityResponse(EligibilityServiceType eligibility)
{
    // if eligibility == CUSTOMER_ELIGIBLE
    //  build the list of rewards from the users account num
    // remove the account num from the inflight requests
}
