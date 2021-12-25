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
    Agreement(int id, Day *valueDate)
    {
        this->id = id;
        this->valueDate = valueDate;
    };

    int getId();
    Day *getValueDate();
    MoneyAmount *getCurrentValueOfClientOnMarket();

private:
    int id;
    Day *valueDate;
};

#endif