#ifndef COMMONTYPES_PERCENTRATE_HPP_
#define COMMONTYPES_PERCENTRATE_HPP_

#include "MoneyAmount.hpp"
class PercentRate {
public:
    PercentRate(double percentRate){
        this->percentRate = percentRate;
        this->rate = percentRate / 100;
    }

MoneyAmount* multiply(MoneyAmount* amount);
float getRate();
double getPercetRate();

private:
float rate;
double percentRate;
};



#endif /* COMMONTYPES_PERCENTRATE_HPP_ */
