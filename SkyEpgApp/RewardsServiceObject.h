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
    bool        isUserObjectInflight(const UserObject userObject);

signals:
    void        requestAccountEligibility(AccountNum);
    void        sendRewardsResponse(RewardsList);

public slots:
    void        handleRewardsRequest(UserObject);
    void        handleEligibilityResponse(EligibilityServiceType);

private:
    explicit RewardsServiceObject(QObject *parent = nullptr);

    RewardsEntryList rewardsEntries;
    QList<UserObject> inFlightUserRequests;
};

#endif // REWARDSSERVICEOBJECT_H
