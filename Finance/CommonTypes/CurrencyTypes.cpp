/*
 * Currencies.cpp
 *
 *  Created on: 18 Dec 2021
 *      Author: Matke
 */

#include "CurrencyTypes.hpp"

#include "Logger.hpp"
#include <cstdlib>

Currency* CurrencyTypes::getCHF(){
	return CHF;
}
Currency* CurrencyTypes::getUSD(){
	return USD;
}
Currency* CurrencyTypes::getEUR(){
	return EUR;
}
Currency* CurrencyTypes::getRS(){
	return RS;
}
Currency* CurrencyTypes::getRUB(){
	return RUB;
}

Currency* CurrencyTypes::getByName(std::string currencyName){
	Logger logger;
	for(Currency* e : allBaseCurrencies){
		if(e->getCurrencyName().compare(currencyName) == 0){
			return e;
		}
	}
	logger.log("Unknown base currency");
	return nullptr;
}


