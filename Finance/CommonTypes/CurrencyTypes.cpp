#include "CurrencyTypes.hpp"
#include "Currency.hpp"
#include "Logger.hpp"
Currency *CurrencyTypes::getCHF()
{
	return CHF;
}
Currency *CurrencyTypes::getUSD()
{
	return USD;
}
Currency *CurrencyTypes::getEUR()
{
	return EUR;
}
Currency *CurrencyTypes::getRS()
{
	return RS;
}
Currency *CurrencyTypes::getRUB()
{
	return RUB;
}

Currency *CurrencyTypes::getByName(std::string currencyName)
{
	Logger logger;
	for (auto e : allBaseCurrencies)
	{
		if (e->getCurrencyName().compare(currencyName) == 0)
		{
			return e;
		}
	}
	logger.log("Unknown base currency");
	return nullptr;
}
