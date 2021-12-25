#include <iostream>
#include "Logger.hpp"

void Logger::log(std::string errorMsg)
{
	std::cerr << errorMsg << std::endl;
}
