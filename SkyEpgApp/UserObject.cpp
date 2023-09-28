#include "UserObject.h"

AccountNum UserObject::nextAvailableAccountNumber = 255;

UserObject::UserObject(AccountNum accountNumber)
    :userAccountNumber(accountNumber)
{
    if(accountNumber==0)
    {
        userAccountNumber = nextAvailableAccountNumber++;
    }
}

AccountNum  UserObject::getAccountNumber() const
{
    return userAccountNumber;
}

ChannelList UserObject::getSubscribedChannels() const
{
    return subscribedChannels;
}

void     UserObject::addChannelSubscription(const ChannelObject & chan)
{
    // check then insert chan into subscribedChannels
}
