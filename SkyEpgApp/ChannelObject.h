#ifndef CHANNELOBJECT_H
#define CHANNELOBJECT_H

#include <QObject>

class ChannelObject
{
public:
    explicit ChannelObject(QString name);

    QString     getChannelName() const;
private:
    QString     channelName;
    // QUUId for channelUUID ?
};

#endif // CHANNELOBJECT_H
