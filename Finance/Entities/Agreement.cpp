#include <iostream>
#include "Client.hpp"
#include "Broker.hpp"
#include <Day.hpp>
#include <CurrencyTypes.hpp>
#include <MoneyAmount.hpp>

int Agreement::getId()
{
    return id;
}

Day *Agreement::getValueDate()
{
    return valueDate;
}
MoneyAmount *Agreement::getCurrentValueOfClientOnMarket()
{
    return currentValueOfClientOnMarket;
}