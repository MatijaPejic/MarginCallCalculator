#ifndef COMMONTYPES_MONEYAMOUNT_HPP_
#define COMMONTYPES_MONEYAMOUNT_HPP_

#include <iostream>
#include "Currency.hpp"

class MoneyAmount
{
public:
	MoneyAmount(Currency *currency, double quantity)
	{
		this->currency = currency;
		this->quantity = quantity;
	}

	MoneyAmount *convertToDollar();
	MoneyAmount *convertFromDollar(std::string toCurrencyName);
	double getQuantity();
	Currency *getCurrency();

private:
	Currency *currency;
	double quantity;
};

#endif /* COMMONTYPES_MONEYAMOUNT_HPP_ */
