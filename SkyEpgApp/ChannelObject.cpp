#include "ChannelObject.h"

ChannelObject::ChannelObject(QString name)
    :channelName(name)
{
}

QString     ChannelObject::getChannelName() const
{
    return channelName;
}
