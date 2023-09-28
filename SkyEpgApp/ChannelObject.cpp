#include "ChannelObject.h"

ChannelObject::ChannelObject(QString name, QObject *parent)
    : QObject{parent},
    channelName(name)
{

}

QString     ChannelObject::getChannelName() const
{
    return channelName;
}
