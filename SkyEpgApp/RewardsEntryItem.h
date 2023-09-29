#ifndef REWARDSENTRYITEM_H
#define REWARDSENTRYITEM_H

#include <QObject>
#include <QVector>
#include <QPair>

extern QString staticStringList[5][2];

class RewardsEntryItem
{
public:
    explicit RewardsEntryItem(const QString& chan, const QString reward);

    QString    getChannelName() const;
    QString    getNamedReward() const;

    RewardsEntryItem &operator =(const RewardsEntryItem & rhs)
    {
        channelName = rhs.channelName;
        namedReward = rhs.namedReward;
        return *this;
    }

private:
    QString           channelName;
    QString           namedReward;
};

#endif // REWARDSENTRYITEM_H
