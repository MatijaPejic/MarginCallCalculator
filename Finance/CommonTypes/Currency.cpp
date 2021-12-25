#include "Currency.hpp"

std::string Currency::getCurrencyName()
{
	return currency;
}
float Currency::getToDollarRate()
{
	return toDollarConversionRate;
}
float Currency::getFromDollarRate()
{
	return fromDollarConversionRate;
}
