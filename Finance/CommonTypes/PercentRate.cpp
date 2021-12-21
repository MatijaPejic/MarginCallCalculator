#include "MoneyAmount.hpp"
#include "PercentRate.hpp"


MoneyAmount* PercentRate::multiply(MoneyAmount* amount){
    return new MoneyAmount(amount->getCurrency(), amount->getQuantity() * rate);
}
float PercentRate::getRate(){
    return rate;
}
double PercentRate::getPercetRate(){
    return percentRate;
}
