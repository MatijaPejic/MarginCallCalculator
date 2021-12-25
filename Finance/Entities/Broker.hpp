#ifndef ENTITIES_BROKER_HPP_
#define ENTITIES_BROKER_HPP_
#include <iostream>
#include <PercentRate.hpp>
using namespace std;

class Broker
{
public:
	Broker(string name, PercentRate *marginMaintenanceRate, int agreementId, PercentRate *brokerInterest)
	{
		this->name = name;
		this->marginMaintenanceRate = marginMaintenanceRate;
		this->agreementId = agreementId;
		this->brokerInterest = brokerInterest;
	}

	string getName();
	PercentRate *getPercentRate();
	PercentRate *getBrokerInterest();
	int getAgreementId();

private:
	string name;
	PercentRate *marginMaintenanceRate;
	int agreementId;
	PercentRate *brokerInterest;
};

#endif