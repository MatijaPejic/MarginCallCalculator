#include <iostream>
#include "Client.hpp"
#include "Broker.hpp"
#include <MoneyAmount.hpp>
#include <Agreement.hpp>
#include <CurrencyTypes.hpp>
using namespace std;

string Client::getName()
{
    return name;
};

MoneyAmount *Client::getOwnMoneyInvested()
{
    return ownMoneyInvested;
};
MoneyAmount *Client::getMoneyBorrowed()
{
    return moneyBorrowed;
};

MoneyAmount *Client::calcTotalBalance()
{
    double total = ownMoneyInvested->convertToDollar()->getQuantity() + moneyBorrowed->convertToDollar()->getQuantity();
    CurrencyTypes types;
    return new MoneyAmount(types.getUSD(), total);
};

MoneyAmount *Client::getTotal()
{
    return totalBalance;
};

int Client::getAgreementId()
{
    return agreementId;
}