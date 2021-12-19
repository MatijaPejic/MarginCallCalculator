#include "Day.hpp"
#include "Logger.hpp"
#include <ctime>
#include <iostream>
using namespace std;


// implementacije iz day.hpp

int Day::getYear(){
	return year;
}

int Day::getMonth(){
	return month;
}

int Day::getDay(){
	return day;
}

int Day::getWeekday(){
	return weekday;
}

Day* Day::getBusinessDay(){
	time_t now = time(0);
	tm *ltm = localtime(&now);
	int year =  1900 + ltm->tm_year;
	int month =  1 + ltm->tm_mon;
	int day =  ltm->tm_mday;

	return new Day(day, month, year);

}

int Day::calculateWeekday(){
	std::tm time_in = { 0, 0, 0,
	      day, month - 1, year - 1900 };
	  std::time_t time_temp = std::mktime(&time_in);
	  const std::tm * time_out = std::localtime(&time_temp);
	  return time_out->tm_wday;
}

std::string Day::getWeekdayStr(){
	Logger LOGGER;
	switch(weekday){
	case 0:
		return "Sunday";
		break;
	case 1:
		return "Monday";
		break;
	case 2:
		return "Tuesday";
		break;
	case 3:
		return "Wednesday";
		break;
	case 4:
		return "Thursday";
		break;
	case 5:
		return "Friday";
		break;
	case 6:
		return "Saturday";
		break;
	default:
		LOGGER.log("getWeekdayStr -> index out of bounds, unknown weekday");
		return nullptr;

	}
}
