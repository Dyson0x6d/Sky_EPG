#ifndef ELIGIBILITYSERVICESTUBOBJECT_H
#define ELIGIBILITYSERVICESTUBOBJECT_H

#include <QObject>
#include "EpgAppTypes.h"

class EligibilityServiceStubObject : public QObject
{
    Q_OBJECT
public:
    virtual ~EligibilityServiceStubObject() {}

    // static getter
    static EligibilityServiceStubObject & GetInstance()
    {
        static EligibilityServiceStubObject instance;
        return instance;
    }

signals:
    void        sendEligibility(EligibilityServiceType);

public slots:
    void        checkAccountEligibility(AccountNum);

private:
    explicit EligibilityServiceStubObject(QObject *parent = nullptr);
};

#endif // ELIGIBILITYSERVICESTUBOBJECT_H
