#ifndef ENTITIES_CLIENT_HPP_
#define ENTITIES_CLIENT_HPP_

#include <iostream>
#include "Broker.hpp"
#include <MoneyAmount.hpp>
#include <Agreement.hpp>
using namespace std;
class Client
{
public:
    Client(std::string name,
           MoneyAmount *ownMoneyInvested,
           MoneyAmount *moneyBorrowed,
           int agreementId)
    {
        this->name = name;
        this->ownMoneyInvested = ownMoneyInvested;
        this->moneyBorrowed = moneyBorrowed;
        this->totalBalance = calcTotalBalance();
        this->agreementId = agreementId;
    }

    std::string getName();
    MoneyAmount *getOwnMoneyInvested();
    MoneyAmount *getMoneyBorrowed();
    MoneyAmount *getTotal();
    int getAgreementId();

private:
    std::string name;
    MoneyAmount *ownMoneyInvested;
    MoneyAmount *moneyBorrowed;
    MoneyAmount *totalBalance;
    MoneyAmount *calcTotalBalance();
    int agreementId;
};

#endif