#include <iostream>
#include "MoneyAmount.hpp"

#include "CurrencyTypes.hpp"
#include "Logger.hpp"

MoneyAmount *MoneyAmount::convertToDollar()
{
	if (!currency->getCurrencyName().compare("USD") == 0)
	{
		CurrencyTypes *currencies = new CurrencyTypes();
		Currency *usdCurrency = currencies->getUSD();
		return new MoneyAmount(usdCurrency, quantity * currency->getToDollarRate());
	}

	return this;
}
MoneyAmount *MoneyAmount::convertFromDollar(std::string toCurrencyName)
{
	Logger logger;
	if (currency->getCurrencyName().compare("USD") == 0)
	{
		CurrencyTypes *currencies = new CurrencyTypes();
		Currency *targetCurrency = currencies->getByName(toCurrencyName);
		return new MoneyAmount(targetCurrency, quantity * targetCurrency->getFromDollarRate());
	}

	logger.log("Couldn't convert from USD, origin currency is not USD, returning this");
	return this;
}

double MoneyAmount::getQuantity()
{
	return quantity;
}
Currency *MoneyAmount::getCurrency()
{
	return currency;
}
