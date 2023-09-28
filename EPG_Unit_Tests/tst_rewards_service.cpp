#include <QtTest>

// add necessary includes here
#include "RewardsServiceObject.h"
#include "ChannelObject.h"

class rewards_service_test : public QObject
{
    Q_OBJECT

public:
    rewards_service_test() {};
    ~rewards_service_test() {};

private slots:
    void initTestCase() {};
    void cleanupTestCase() {};

};

//========================================================================

class channel_object_test : public QObject
{
    Q_OBJECT

public:
    channel_object_test() {};
    ~channel_object_test() {};

private slots:
    void initTestCase() {};
    void cleanupTestCase() {};
    // my tests here
    void testChannelObjectConstructor();
};

void channel_object_test::testChannelObjectConstructor()
{
    QString name = "SPORTS";
    ChannelObject channel(name);
    QCOMPARE_EQ( channel.getChannelName(), name);
    QCOMPARE_NE( channel.getChannelName(), "");
}

int main(int argc, char *argv[])
{
    int status = 0;
    //status |= QTest::qExec(new rewards_service_test, argc, argv);
    status |= QTest::qExec(new channel_object_test, argc, argv);
    // status |= QTest::qExec(new ..., argc, argv);

    return status;
}

#include "tst_rewards_service.moc"
