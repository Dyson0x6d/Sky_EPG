#include <QtTest>

// add necessary includes here
#include "RewardsServiceObject.h"
#include "ChannelObject.h"
#include "EligibilityServiceStubObject.h"

//========================================================================

class rewards_service_test : public QObject
{
    Q_OBJECT

public:
    rewards_service_test() {};
    ~rewards_service_test() {};

private slots:
    void initTestCase() {};
    void cleanupTestCase() {};

    void testHandleRewardsRequest();
    void testAddSingleRewardsItem();
    void testAddMultipleRewardsItems();
    // what is a failing test here?
};


void rewards_service_test::testHandleRewardsRequest()
{
    qRegisterMetaType<UserObject>();
    qRegisterMetaType<AccountNum>();

    QSignalSpy spy(&(RewardsServiceObject::GetInstance()),
                   SIGNAL(requestAccountEligibility(AccountNum)) );

    AccountNum accountNumber = 300;
    UserObject user1(accountNumber);

    RewardsServiceObject::GetInstance().handleRewardsRequest(user1);

    QCOMPARE(spy.count(), 1);
    AccountNum recievedAccountNum = qvariant_cast<AccountNum>(spy.at(0).at(0));
    QVERIFY( recievedAccountNum == accountNumber );
}

void rewards_service_test::testAddSingleRewardsItem()
{
    RewardsEntryItem item1(staticStringList[1][0], staticStringList[1][1]);
    // check the functions?!

    RewardsServiceObject::GetInstance().clearRewardsEntries();
    RewardsServiceObject::GetInstance().addRewardsEntry(item1);

    RewardsEntryItem resultItem = RewardsServiceObject::GetInstance().getRewardEntryAt(0);
    QVERIFY(resultItem.getChannelName()!="");
    QVERIFY(resultItem.getNamedReward()!="");
    QVERIFY(resultItem==item1);
}

void rewards_service_test::testAddMultipleRewardsItems()
{
    RewardsEntryList entryList;
    uint userChannelSelection[3] = {0,2,3};
    for( auto usrChanel : userChannelSelection )
    {
        entryList.append( RewardsEntryItem(staticStringList[usrChanel][0], staticStringList[usrChanel][1]));
    }

    RewardsServiceObject::GetInstance().clearRewardsEntries();
    uint counter =0;
    for( auto entryItem = entryList.begin(); entryItem != entryList.end(); ++entryItem, counter++)
    {
        RewardsServiceObject::GetInstance().addRewardsEntry(*entryItem);

        RewardsEntryItem resultItem = RewardsServiceObject::GetInstance().getRewardEntryAt(counter);
        QVERIFY(resultItem==(*entryItem));
    }

}


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


//========================================================================

class eligibility_service_test : public QObject
{
    Q_OBJECT
public:
    eligibility_service_test() {}
    ~eligibility_service_test() {}

private slots:
    void initTestCase() {};
    void cleanupTestCase() {};

    void testValidAccountNumber();
    void testInvalidAccountNumber();
    void testTechnicalFailureAccountNumber();

};

void eligibility_service_test::testValidAccountNumber()
{
    qRegisterMetaType<EligibilityServiceType>();
    QSignalSpy spy(&(EligibilityServiceStubObject::GetInstance()),
                  SIGNAL( sendEligibility(EligibilityServiceType) ) );

    EligibilityServiceStubObject::GetInstance().checkAccountEligibility(300);

    QCOMPARE(spy.count(), 1);
    EligibilityServiceType estReturn = qvariant_cast<EligibilityServiceType>(spy.at(0).at(0));

    QVERIFY(estReturn == CUSTOMER_ELIGIBLE);
}

void eligibility_service_test::testInvalidAccountNumber()
{
    qRegisterMetaType<EligibilityServiceType>();
    QSignalSpy spy(&(EligibilityServiceStubObject::GetInstance()),
                   SIGNAL( sendEligibility(EligibilityServiceType) ) );

    EligibilityServiceStubObject::GetInstance().checkAccountEligibility(301);

    QCOMPARE(spy.count(), 1);
    EligibilityServiceType estReturn = qvariant_cast<EligibilityServiceType>(spy.at(0).at(0));

    QVERIFY(estReturn == CUSTOMER_INELIGIBLE);
}

void eligibility_service_test::testTechnicalFailureAccountNumber()
{
    qRegisterMetaType<EligibilityServiceType>();
    QSignalSpy spy(&(EligibilityServiceStubObject::GetInstance()),
                   SIGNAL( sendEligibility(EligibilityServiceType) ) );

    EligibilityServiceStubObject::GetInstance().checkAccountEligibility(302);

    QCOMPARE(spy.count(), 1);
    EligibilityServiceType estReturn = qvariant_cast<EligibilityServiceType>(spy.at(0).at(0));

    QVERIFY(estReturn == TECHNICAL_FAILURE);
}


//========================================================================

int main(int argc, char *argv[])
{
    int status = 0;
    status |= QTest::qExec(new rewards_service_test, argc, argv);
    status |= QTest::qExec(new channel_object_test, argc, argv);
    status |= QTest::qExec(new eligibility_service_test, argc, argv);
    // status |= QTest::qExec(new ..., argc, argv);

    return status;
}

#include "tst_rewards_service.moc"
