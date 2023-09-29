#include "RewardsEntryItem.h"

QString staticStringList[5][2] ={
    {QObject::tr("SPORTS"),QObject::tr("CHAMPIONS_LEAGUE_FINAL_TICKET")},
    {QObject::tr("KIDS"),QObject::tr("N/A")},
    {QObject::tr("MUSIC"),QObject::tr("KARAOKE_PRO_MICROPHONE")},
    {QObject::tr("NEWS"),QObject::tr("N/A")},
    {QObject::tr("MOVIES"),QObject::tr("PIRATES_OF_THE_CARIBBEAN_COLLECTION")},
};

RewardsEntryItem::RewardsEntryItem(const QString& chan, const QString reward)
    :channelName(chan), namedReward(reward)
{

}

QString    RewardsEntryItem::getChannelName() const
{
    return channelName;
}

QString    RewardsEntryItem::getNamedReward() const
{
    return namedReward;
}
