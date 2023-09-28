#include "RewardsEntryItem.h"

RewardsEntryItem::RewardsEntryItem(const QString& chan, const QString reward, QObject *parent)
    : QObject{parent},
    channelName(chan),
    namedReward(reward)
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
