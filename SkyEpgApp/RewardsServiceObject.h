#ifndef REWARDSSERVICEOBJECT_H
#define REWARDSSERVICEOBJECT_H

#include <QObject>
#include "EpgAppTypes.h"
#include "UserObject.h"

class RewardsServiceObject : public QObject
{
    Q_OBJECT
public:
    explicit RewardsServiceObject(QObject *parent = nullptr);

    void        addRewardsEntry(const RewardsEntryItem& rewardItem);
signals:
    void        requestAccountEligibility(AccountNum);
    RewardsList sendRewardsResponse();

public slots:
    void        handleRewardsRequest(UserObject&);
    void        handleEligibilityResponse(EligibilityServiceType);

private:
    RewardsEntryList rewardsEntries;
};

#endif // REWARDSSERVICEOBJECT_H
