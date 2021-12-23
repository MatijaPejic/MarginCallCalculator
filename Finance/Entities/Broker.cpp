#include <PercentRate.hpp>
#include "Broker.hpp"
#include <iostream>
using namespace std;
string Broker::getName(){
    return name;
};
PercentRate* Broker::getPercentRate(){
    return marginMaintenanceRate;
};