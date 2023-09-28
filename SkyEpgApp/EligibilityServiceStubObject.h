#ifndef ELIGIBILITYSERVICESTUBOBJECT_H
#define ELIGIBILITYSERVICESTUBOBJECT_H

#include <QObject>
#include "EpgAppTypes.h"

class EligibilityServiceStubObject : public QObject
{
    Q_OBJECT
public:
    explicit EligibilityServiceStubObject(QObject *parent = nullptr);

signals:
    EligibilityServiceType      sendEligibility();

public slots:
    void                        handleEligibility(AccountNum);
};

#endif // ELIGIBILITYSERVICESTUBOBJECT_H
