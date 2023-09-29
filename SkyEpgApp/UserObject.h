#ifndef USEROBJECT_H
#define USEROBJECT_H

#include <QObject>

#include "EpgAppTypes.h"

class UserData
{
public:
    explicit UserData(AccountNum accountNumber = 0);

    AccountNum  getAccountNumber() const;
    ChannelList getSubscribedChannels() const;

    void     addChannelSubscription(const ChannelObject & chan);

    bool    operator==(const UserData & rhs) const
    {
        return (userAccountNumber==rhs.getAccountNumber());
    }


private:
    static AccountNum  nextAvailableAccountNumber;

    AccountNum  userAccountNumber;
    ChannelList subscribedChannels;
};

class UserObject : public QObject
{
    Q_OBJECT
public:
    explicit UserObject(const UserData & user, QObject *parent = nullptr);
    virtual ~UserObject() {}

signals:
    void    requestAvailableRewards(UserData);

public slots:
    void    handleRewardsResponse(RewardsList);

private:
    UserData userData;
};

#endif // USEROBJECT_H
