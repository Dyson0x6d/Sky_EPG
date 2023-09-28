#ifndef USEROBJECT_H
#define USEROBJECT_H

#include <QObject>
#include "EpgAppTypes.h"

class UserObject : public QObject
{
    Q_OBJECT
public:
    explicit UserObject(AccountNum accountNumber = 0, QObject *parent = nullptr);

    AccountNum  getAccountNumber() const;
    ChannelList getSubscribedChannels() const;

    void     addChannelSubscription(const ChannelObject & chan);
signals:

    void    requestAvailableRewards();

private:
    static AccountNum  nextAvailableAccountNumber;

    AccountNum  userAccountNumber;
    ChannelList subscribedChannels;
};

#endif // USEROBJECT_H
