#include "EligibilityServiceStubObject.h"

EligibilityServiceStubObject::EligibilityServiceStubObject(QObject *parent)
    : QObject{parent}
{

}

void EligibilityServiceStubObject::checkAccountEligibility(AccountNum accountNum)
{
    // some arbitrary and deliberately incorrect logic here
    switch(accountNum % 3)
    {
    case 0: // Eligible
        emit sendEligibility(CUSTOMER_ELIGIBLE);
        break;
    case 1: // Ineligible
        emit sendEligibility(CUSTOMER_INELIGIBLE);
        break;
    case 2:
    default:
        emit sendEligibility(TECHNICAL_FAILURE);
    }
}
