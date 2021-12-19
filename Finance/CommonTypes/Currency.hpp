#ifndef COMMONTYPES_CURRENCY_HPP_
#define COMMONTYPES_CURRENCY_HPP_

#include <iostream>
class Currency {
public:
	Currency (std::string currency, float toDollar, float fromDollar){
		this->currency = currency;
		this->toDollarConversionRate = toDollar;
		this->fromDollarConversionRate = fromDollar;
	}

	std::string getCurrencyName();
	float getToDollarRate();
	float getFromDollarRate();

private:
	std::string currency;
	float toDollarConversionRate;
	float fromDollarConversionRate;
};





#endif /* COMMONTYPES_CURRENCY_HPP_ */
