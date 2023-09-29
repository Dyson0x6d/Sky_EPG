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

    RewardsEntryItem getRewardEntryAt(uint idx) const;    // to enable debug

signals:
    void        requestAccountEligibility(AccountNum);
    void        sendRewardsResponse(RewardsList);

public slots:
    void        handleRewardsRequest(UserObject);

    // NOTE: the model seems to suggest that the eligibility response is always for the last account sent
    //       suggestion, return the account number WITH the eligibility response
    //       e.g. void handleEligibilityResponse(AccountNum, EligibilityServiceType);

    void        handleEligibilityResponse(EligibilityServiceType);

private:
    explicit RewardsServiceObject(QObject *parent = nullptr);

    RewardsEntryList rewardsEntries;
    QList<UserObject> inFlightUserRequests;
};

#endif // REWARDSSERVICEOBJECT_H
