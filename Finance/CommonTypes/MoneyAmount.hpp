/*
 * MoneyAmount.hpp
 *
 *  Created on: 18 Dec 2021
 *      Author: Matke
 */

#ifndef COMMONTYPES_MONEYAMOUNT_HPP_
#define COMMONTYPES_MONEYAMOUNT_HPP_

#include <iostream>
#include "Currency.hpp"

//TODO definicija polja i metoda
class MoneyAmount {
public:
	MoneyAmount(Currency *currency, float quantity){
		this->currency = currency;
		this->quantity = quantity;
	}

	MoneyAmount* convertToDollar();
	MoneyAmount* convertFromDollar(std::string toCurrencyName);
	float getQuantity();
	Currency* getCurrency();
private:
	Currency *currency;
	float quantity;


};

#endif /* COMMONTYPES_MONEYAMOUNT_HPP_ */
