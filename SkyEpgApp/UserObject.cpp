#include <qtextstream.h>
#include "UserObject.h"

AccountNum UserData::nextAvailableAccountNumber = 255;

UserData::UserData(AccountNum accountNumber)
    :userAccountNumber(accountNumber)
{
    if(accountNumber==0)
    {
        userAccountNumber = nextAvailableAccountNumber++;
    }
}

AccountNum  UserData::getAccountNumber() const
{
    return userAccountNumber;
}

ChannelList UserData::getSubscribedChannels() const
{
    return subscribedChannels;
}

void     UserData::addChannelSubscription(const ChannelObject & chan)
{
    subscribedChannels.append(chan);
}

//========================================================================

UserObject::UserObject(const UserData & user, QObject *parent )
    : QObject{parent},
    userData(user)
{

}

void    UserObject::handleRewardsResponse(RewardsList rewardsList)
{
    QTextStream ts( stdout );

    if( rewardsList.size() > 0)
    {
        ts << QObject::tr("Account Number : ") << userData.getAccountNumber() << " has rewards";
        for( auto reward = rewardsList.begin(); reward != rewardsList.end(); reward)
        {
            if( *reward != QObject::tr("N/A"))
            {
                ts << *reward;
            }
        }
    }
    else
    {
        ts << QObject::tr("Sorry no rewards for account num: ") << userData.getAccountNumber();
    }
}
