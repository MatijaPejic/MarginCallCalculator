cmake_minimum_required(VERSION 3.22)
project(MarginCall)

enable_testing()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra")
set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")


add_library(Currency Currency.hpp Currency.cpp)
add_library(CurrencyTypes CurrencyTypes.hpp CurrencyTypes.cpp)
add_library(Day Day.hpp Day.cpp)
add_library(Logger Logger.hpp Logger.cpp)
add_library(MoneyAmount MoneyAmount.hpp MoneyAmount.cpp)
add_library(PercentRate PercentRate.hpp PercentRate.cpp)
add_executable(CommonTypesTest runTests.cpp)

target_link_libraries(CommonTypesTest PRIVATE Currency)
target_link_libraries(CommonTypesTest PRIVATE CurrencyTypes)
target_link_libraries(CommonTypesTest PRIVATE Day)
target_link_libraries(CommonTypesTest PRIVATE PercentRate)
target_link_libraries(CommonTypesTest PRIVATE MoneyAmount)
target_link_libraries(CommonTypesTest PRIVATE Logger)
target_link_libraries(MoneyAmount PRIVATE Currency)

add_test(NAME CommonTypesTest COMMAND CommonTypesTest)


