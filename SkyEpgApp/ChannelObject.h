#ifndef CHANNELOBJECT_H
#define CHANNELOBJECT_H

#include <QObject>

class ChannelObject : public QObject
{
    Q_OBJECT
public:
    explicit ChannelObject(QString name, QObject *parent = nullptr);

    QString     getChannelName() const;
signals:

private:
    QString     channelName;
    // QUUId for channelUUID;
};

#endif // CHANNELOBJECT_H
