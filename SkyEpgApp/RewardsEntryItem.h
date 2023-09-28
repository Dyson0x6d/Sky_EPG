#ifndef REWARDSENTRYITEM_H
#define REWARDSENTRYITEM_H

#include <QObject>

class RewardsEntryItem : public QObject
{
    Q_OBJECT
public:
    explicit RewardsEntryItem(const QString& chan, const QString reward, QObject *parent = nullptr);

    QString    getChannelName() const;
    QString    getNamedReward() const;
signals:

private:
    const QString           channelName;
    const QString           namedReward;
};

#endif // REWARDSENTRYITEM_H
