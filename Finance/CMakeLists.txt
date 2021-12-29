cmake_minimum_required(VERSION 3.22)
project(MarginCallMain)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_subdirectory(CommonTypes)
add_subdirectory(Entities)
add_library(Calculator src/marginCallCalculator.hpp src/marginCallCalculator.cpp)
add_executable(test src/marginCallCalculatorTest.cpp)

target_link_libraries(Calculator PRIVATE Client)
target_link_libraries(Calculator PRIVATE Agreement)
target_link_libraries(Calculator PRIVATE Broker)
target_link_libraries(Calculator PRIVATE Day)

target_link_libraries(test PRIVATE Currency)
target_link_libraries(test PRIVATE CurrencyTypes)
target_link_libraries(test PRIVATE Day)
target_link_libraries(test PRIVATE Logger)
target_link_libraries(test PRIVATE MoneyAmount)
target_link_libraries(test PRIVATE PercentRate)
target_link_libraries(test PRIVATE Client)
target_link_libraries(test PRIVATE Agreement)
target_link_libraries(test PRIVATE Broker)
target_link_libraries(test PRIVATE Calculator)

target_link_libraries(Client PRIVATE MoneyAmount)
target_link_libraries(Client PRIVATE Currency)
target_link_libraries(Broker PRIVATE PercentRate)
target_link_libraries(Agreement PRIVATE Day)
target_link_libraries(Agreement PRIVATE MoneyAmount)
target_link_libraries(Agreement PRIVATE CurrencyTypes)
message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})
 



