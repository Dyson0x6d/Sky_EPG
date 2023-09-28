#ifndef EPGAPPTYPES_H
#define EPGAPPTYPES_H

#include "qlist.h"
#include "channelobject.h"
#include "rewardsentryitem.h"

typedef quint32 AccountNum;

typedef QList<ChannelObject> ChannelList;

typedef QList<RewardsEntryItem> RewardsEntryList;

typedef QList<QString> RewardsList;

enum EligibilityServiceType
{
    CUSTOMER_ELIGIBLE = 0,
    CUSTOMER_INELIGIBLE,
    TECHNICAL_FAILURE
};


#endif // EPGAPPTYPES_H
