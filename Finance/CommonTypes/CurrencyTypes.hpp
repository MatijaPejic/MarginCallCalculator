/*
 * Currencies.hpp
 *
 *  Created on: 18 Dec 2021
 *      Author: Matke
 */

#ifndef COMMONTYPES_CURRENCYTYPES_HPP_
#define COMMONTYPES_CURRENCYTYPES_HPP_
#include <iostream>
#include <vector>
#include "Currency.hpp"


class CurrencyTypes {
private:
	Currency* CHF = new Currency("CHF", 1.08, 0.92);
	Currency* USD = new Currency("USD", 1, 1);
	Currency* EUR = new Currency("EUR", 1.12, 0.89);
	Currency* RS = new Currency("RS", 0.0096, 104.61);
	Currency* RUB = new Currency("RUB", 0.013, 74.17);

	std::vector<Currency*> allBaseCurrencies { CHF, USD, EUR, RS, RUB};


public:
	Currency* getCHF();
	Currency* getUSD();
	Currency* getEUR();
	Currency* getRS();
	Currency* getRUB();
	Currency* getByName(std::string currencyName);

};



#endif /* COMMONTYPES_CURRENCYTYPES_HPP_ */
