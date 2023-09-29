#include <qdebug.h>
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

void    UserObject::sendUserObjectRequest()
{
    emit requestAvailableRewards(userData);
}

void    UserObject::handleRewardsResponse(RewardsList rewardsList)
{
    if( rewardsList.size() > 0)
    {
        qDebug() << QObject::tr("Account Number : ") << userData.getAccountNumber() << " has " << rewardsList.size() <<  " rewards";
        for( auto reward = rewardsList.begin(); reward != rewardsList.end(); ++reward)
        {
            if( *reward != QObject::tr("N/A"))
            {
                qDebug()  << *reward;
            }
        }
    }
    else
    {
        qDebug()  << QObject::tr("Sorry no rewards for account num: ") << userData.getAccountNumber();
    }
}
