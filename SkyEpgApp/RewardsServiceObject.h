#ifndef REWARDSSERVICEOBJECT_H
#define REWARDSSERVICEOBJECT_H

#include <QObject>
#include "EpgAppTypes.h"
#include "UserObject.h"

class RewardsServiceObject : public QObject
{
    Q_OBJECT
public:
    virtual     ~RewardsServiceObject() {}

    // static getter
    static RewardsServiceObject & GetInstance()
    {
        static RewardsServiceObject instance;
        return instance;
    }

    void        addRewardsEntry(const RewardsEntryItem& rewardItem);

signals:
    void        requestAccountEligibility(AccountNum);
    RewardsList sendRewardsResponse();

public slots:
    void        handleRewardsRequest(UserObject&);
    void        handleEligibilityResponse(EligibilityServiceType);

private:
    explicit RewardsServiceObject(QObject *parent = nullptr);
    RewardsEntryList rewardsEntries;
};

#endif // REWARDSSERVICEOBJECT_H
