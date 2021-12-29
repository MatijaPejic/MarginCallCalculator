#ifndef ENTITIES_AGREEMENT_HPP_
#define ENTITIES_AGREEMENT_HPP_

#include <iostream>
#include "Client.hpp"
#include "Broker.hpp"
#include <Day.hpp>
#include <MoneyAmount.hpp>

class Agreement
{
public:
    Agreement(int id, Day *valueDate, MoneyAmount *clientValue)
    {
        this->id = id;
        this->valueDate = valueDate;
        this->currentValueOfClientOnMarket = clientValue;
    };

    int getId();
    Day *getValueDate();
    MoneyAmount *getCurrentValueOfClientOnMarket();

private:
    int id;
    Day *valueDate;
    MoneyAmount *currentValueOfClientOnMarket;
};

#endif