#include "RewardsServiceObject.h"


RewardsServiceObject::RewardsServiceObject(QObject *parent)
    : QObject{parent}
{

}

void    RewardsServiceObject::addRewardsEntry(const RewardsEntryItem& rewardItem)
{
    // check for duplicates
    //rewardsEntries.append(rewardItem);
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
    // if eligibility == CUSTOMER_ELIGIBLE
    //  build the list of rewards from the users account num
    // remove the account num from the inflight requests
}
