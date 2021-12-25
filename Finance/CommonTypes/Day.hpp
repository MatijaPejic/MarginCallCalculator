#ifndef COMMONTYPES_DAY_HPP_
#define COMMONTYPES_DAY_HPP_

#include <iostream>
class Day
{
public:
	Day();
	Day(int day, int month, int year)
	{
		validateDate(day, month, year);
		this->day = day;
		this->month = month;
		this->year = year;
		this->weekday = calculateWeekday();
	};

	Day *getBusinessDay();
	int getYear();
	int getMonth();
	int getDay();
	int getWeekday();
	int calculateWeekday();
	std::string getWeekdayStr();
	void validateDate(int day, int month, int year);
	std::string toStringDate();

private:
	int year;
	int month;
	int day;
	int weekday;
};

#endif /* COMMONTYPES_DAY_HPP_ */
