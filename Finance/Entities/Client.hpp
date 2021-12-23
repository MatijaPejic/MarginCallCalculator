#ifndef ENTITIES_CLIENT_HPP_
#define ENTITIES_CLIENT_HPP_

#include <iostream>
#include "Broker.hpp"
#include <MoneyAmount.hpp>
#include <Agreement.hpp>
using namespace std;
class Client {
public:
	Client(std::string name,
	Broker* broker,
    Agreement* agreement,
	MoneyAmount* ownMoneyInvested,
    MoneyAmount* moneyBorrowed){
        this->name = name;
        this->broker = broker;
        this->agreement = agreement;
        this->ownMoneyInvested = ownMoneyInvested;
        this->moneyBorrowed = moneyBorrowed;
        this->totalBalance = calcTotalBalance();

    }

	std::string getName();
	Broker* getBroker();
    Agreement* getAgreement();
	MoneyAmount* getOwnMoneyInvested();
    MoneyAmount* getMoneyBorrowed();
    MoneyAmount* getTotal();

private:
	std::string name;
	Broker* broker;
    Agreement* agreement;
	MoneyAmount* ownMoneyInvested;
    MoneyAmount* moneyBorrowed;
    MoneyAmount* totalBalance;
    MoneyAmount* calcTotalBalance();

};

#endif