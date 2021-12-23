#ifndef ENTITIES_AGREEMENT_HPP_
#define ENTITIES_AGREEMENT_HPP_


#include <iostream>
#include "Client.hpp"
#include "Broker.hpp"
#include <Day.hpp>
#include <MoneyAmount.hpp>

class Agreement{
public:
    Agreement(int id,
        Client* client,
        Broker* broker,
        Day* valueDate,
        MoneyAmount* boughtStocksValue){
            this->id = id;
            this->client = client;
            this->broker = broker;
            this->valueDate = valueDate;
            this->boughtStocksValue = boughtStocksValue;
        };

    int getId();
    Client* getClient();
    Broker* getBroker();
    Day* getValueDate();
    MoneyAmount* getBoughtStocksValue();


private:
    int id;
    Client* client;
    Broker* broker;
    Day* valueDate;
    MoneyAmount* boughtStocksValue;

};

#endif