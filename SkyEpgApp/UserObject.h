#ifndef USEROBJECT_H
#define USEROBJECT_H

#include <QObject>

#include "EpgAppTypes.h"

class UserObject
{
public:
    explicit UserObject(AccountNum accountNumber = 0);

    AccountNum  getAccountNumber() const;
    ChannelList getSubscribedChannels() const;

    void     addChannelSubscription(const ChannelObject & chan);

    bool    operator==(const UserObject & rhs) const
    {
        return (userAccountNumber==rhs.getAccountNumber());
    }

signals:

    void    requestAvailableRewards();

private:
    static AccountNum  nextAvailableAccountNumber;

    AccountNum  userAccountNumber;
    ChannelList subscribedChannels;
};

#endif // USEROBJECT_H
