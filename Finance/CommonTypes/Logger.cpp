/*
 * Logger.cpp
 *
 *  Created on: 18 Dec 2021
 *      Author: Matke
 */
#include <iostream>
#include "Logger.hpp"

void Logger::log(std::string errorMsg){
		std::cerr << errorMsg << std::endl;
	}


