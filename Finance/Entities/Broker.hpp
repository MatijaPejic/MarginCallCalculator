#ifndef ENTITIES_BROKER_HPP_
#define ENTITIES_BROKER_HPP_
#include <iostream>
#include <PercentRate.hpp>
using namespace std;

class Broker {
public:
	Broker(string name, PercentRate* marginMaintenanceRate){
		this->name = name;
		this->marginMaintenanceRate =  marginMaintenanceRate;
	}

	string getName();
	PercentRate* getPercentRate();
private:
	string name;
	PercentRate* marginMaintenanceRate;
};


#endif