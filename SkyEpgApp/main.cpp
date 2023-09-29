#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include <QTime>
#include <list>

#include "RewardsServiceObject.h"
#include "ChannelObject.h"
#include "EligibilityServiceStubObject.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "SkyEpgApp_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    // add the rewards to the rewards service
    uint userChannelSelection[5] = {0,1,2,3,4};
    for( auto usrChanel : userChannelSelection )
    {
        RewardsServiceObject::GetInstance().addRewardsEntry(RewardsEntryItem(staticStringList[usrChanel][0], staticStringList[usrChanel][1]));
    }

    // connect the rewards service to the eligibility service
    RewardsServiceObject::GetInstance().connectToEligibilityService();

    // create a UserData and a UserObject
    UserData user1(0);   // will count as valid
    std::list<uint> userOneList( &userChannelSelection[0], &userChannelSelection[2]);
    for( auto channelPick : userOneList)
    {
        user1.addChannelSubscription(ChannelObject(staticStringList[channelPick][0]));
    }
    UserObject usrObj1(user1);

    // connect the user to the
    RewardsServiceObject::GetInstance().connectUserForRequest(&usrObj1);

    // send the user object request
    usrObj1.sendUserObjectRequest();

    UserData user2(0); //will be invalid,
    UserObject usrObj2(user2);
    RewardsServiceObject::GetInstance().connectUserForRequest(&usrObj2);
    usrObj2.sendUserObjectRequest();

    UserData user3(258); // valid again
    std::list<uint> userThreeList( &userChannelSelection[0], &userChannelSelection[4]);
    for( auto channelPick : userThreeList)
    {
        user3.addChannelSubscription(ChannelObject(staticStringList[channelPick][0]));
    }
    UserObject usrObj3(user3);
    RewardsServiceObject::GetInstance().connectUserForRequest(&usrObj3);
    usrObj3.sendUserObjectRequest();



    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
    {
        a.processEvents(QEventLoop::AllEvents, 1000);
    }
    return a.exec();
}
