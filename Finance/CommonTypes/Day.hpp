#ifndef COMMONTYPES_DAY_HPP_
#define COMMONTYPES_DAY_HPP_

#include <iostream>

// dodaj add days, incement i decrement , validacija dana
class Day{
public:
	Day();
	Day(int day, int month, int year){
		this->day = day;
		this->month = month;
		this->year = year;
		this->weekday = calculateWeekday();

	};

	Day* getBusinessDay();
	int getYear();
	int getMonth();
	int getDay();
	int getWeekday();
	int calculateWeekday();
	std::string getWeekdayStr();

private:
	int year;
	int month;
	int day;
	int weekday;
};

#endif /* COMMONTYPES_DAY_HPP_ */
