cmake_minimum_required(VERSION 3.22)
project(MarginCallMain)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra")
add_subdirectory(CommonTypes)
add_subdirectory(Entities)
add_executable(MarginCallCalculator src/main.cpp)
target_link_libraries(MarginCallCalculator PRIVATE Currency)
target_link_libraries(MarginCallCalculator PRIVATE CurrencyTypes)
target_link_libraries(MarginCallCalculator PRIVATE Day)
target_link_libraries(MarginCallCalculator PRIVATE Logger)
target_link_libraries(MarginCallCalculator PRIVATE MoneyAmount)
target_link_libraries(MarginCallCalculator PRIVATE PercentRate)

target_link_libraries(MarginCallCalculator PRIVATE Client)
target_link_libraries(MarginCallCalculator PRIVATE Agreement)
target_link_libraries(MarginCallCalculator PRIVATE Broker)
target_link_libraries(Client PRIVATE MoneyAmount)
target_link_libraries(Client PRIVATE Currency)
target_link_libraries(Broker PRIVATE PercentRate)
target_link_libraries(Agreement PRIVATE Day)
target_link_libraries(Agreement PRIVATE MoneyAmount)
message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})
 



