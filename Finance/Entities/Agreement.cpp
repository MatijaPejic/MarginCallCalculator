#include <iostream>
#include "Client.hpp"
#include "Broker.hpp"
#include <Day.hpp>
#include <MoneyAmount.hpp>


int Agreement::getId(){
    return id;
}
Client* Agreement::getClient(){
    return client;
}
Broker* Agreement::getBroker(){
    return broker;
}
Day* Agreement::getValueDate(){
    return valueDate;
}
MoneyAmount* Agreement::getBoughtStocksValue(){
    return boughtStocksValue;
}