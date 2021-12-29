#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "marginCallCalculator.hpp"
#include <CurrencyTypes.hpp>
using namespace std;

void separator()
{
    cout << "-" << endl;
}

class TestDataContainer
{
public:
    TestDataContainer() {}
    Client *client;
    Broker *broker;
    Agreement *agreement;
    Day *calcDate;
    void populateClient(string name, MoneyAmount *ownMoney, MoneyAmount *borrowedMoney, int agreementId)
    {
        client = new Client(name, ownMoney, borrowedMoney, agreementId);
    };
    void populateBroker(string name, PercentRate *rate, int agreementId, PercentRate *interest)
    {
        broker = new Broker(name, rate, agreementId, interest);
    };
    void populateAreement(int id, Day *calcDate, MoneyAmount *clientValue)
    {
        agreement = new Agreement(id, calcDate, clientValue);
    };

    void setCalcDate(Day *day)
    {
        calcDate = day;
    };
};

TEST_CASE("Margin Call date validation tests")
{
    //given
    TestDataContainer *testData = new TestDataContainer();
    CurrencyTypes *currencies = new CurrencyTypes();
    MoneyAmount *testMoney = new MoneyAmount(currencies->getUSD(), 10000);
    Day *someDay = new Day(1, 1, 2021);
    testData->populateClient("test", testMoney, testMoney, 1);
    testData->populateAreement(1, someDay, testMoney);
    //

    SECTION("Calculating a Margin Call for a future date should result in an error!")
    {
        //when
        separator();
        Day *today = someDay->getBusinessDay();
        today->incrementDay(1);
        Day *testDay = new Day(today->getDay(), today->getMonth(), today->getYear());
        testData->setCalcDate(testDay);
        //then
        double result = calculateMarginCall(testData->client, testData->agreement, testData->broker, testData->calcDate);
        REQUIRE(result == -1);
    };

    SECTION("Calculating a Margin Call on date before agreement value date should result in an error!")
    {
        separator();
        Day *testCalcDay = new Day(1, 1, 2021);
        testData->agreement->getValueDate()->incrementDay(2);
        double result = calculateMarginCall(testData->client, testData->agreement, testData->broker, testCalcDay);
        REQUIRE(result == -1);
    };
    SECTION("Calculation Margin Calls on weekend day's should result in an error")
    {
        //when
        separator();
        Day *testDate = new Day(26, 12, 2021);
        testData->setCalcDate(testDate);
        //then
        double result = calculateMarginCall(testData->client, testData->agreement, testData->broker, testData->calcDate);
        REQUIRE(result == -1);
    };
};

TEST_CASE("Entity Validation")
{
    TestDataContainer *testData = new TestDataContainer();
    CurrencyTypes *currencies = new CurrencyTypes();
    MoneyAmount *testMoney = new MoneyAmount(currencies->getUSD(), 10000);
    Day *someDay = new Day(1, 1, 2021);
    Day *calcDate = new Day(4, 1, 2021);
    testData->populateClient("test", testMoney, testMoney, 1);
    testData->populateAreement(1, someDay, testMoney);
    testData->setCalcDate(calcDate);
    SECTION("Broker Maintanance Rate test")
    {
        separator();
        PercentRate *interest = new PercentRate(12);
        PercentRate *maintance = new PercentRate(50);
        testData->populateBroker("testBroker", maintance, 1, interest);
        double result = calculateMarginCall(testData->client, testData->agreement, testData->broker, testData->calcDate);
        REQUIRE(result == -1);
    };
    SECTION("Broker interest rate test")
    {
        separator();
        PercentRate *interest = new PercentRate(50);
        PercentRate *maintance = new PercentRate(35);
        testData->populateBroker("testBroker", maintance, 1, interest);
        double result = calculateMarginCall(testData->client, testData->agreement, testData->broker, testData->calcDate);
        REQUIRE(result == -1);
    };
    SECTION("Same agreement id test")
    {
        separator();
        PercentRate *interest = new PercentRate(12);
        PercentRate *maintance = new PercentRate(35);
        testData->populateBroker("testBroker", maintance, 2, interest);
        double result = calculateMarginCall(testData->client, testData->agreement, testData->broker, testData->calcDate);
        REQUIRE(result == -1);
    };
    SECTION("Client must invest 50 percent of total amount")
    {
        separator();
        PercentRate *interest = new PercentRate(12);
        PercentRate *maintance = new PercentRate(35);
        testData->populateBroker("testBroker", maintance, 1, interest);
        MoneyAmount *testAmount = new MoneyAmount(currencies->getUSD(), 1000);
        testData->populateClient("test", testAmount, testMoney, 1);
        double result = calculateMarginCall(testData->client, testData->agreement, testData->broker, testData->calcDate);
        REQUIRE(result == -1);
    };
    SECTION("Client cannot invest negative amount")
    {
        separator();
        PercentRate *interest = new PercentRate(12);
        PercentRate *maintance = new PercentRate(35);
        testData->populateBroker("testBroker", maintance, 1, interest);
        MoneyAmount *testAmount = new MoneyAmount(currencies->getUSD(), -1000);
        testData->populateClient("test", testAmount, testMoney, 1);
        double result = calculateMarginCall(testData->client, testData->agreement, testData->broker, testData->calcDate);
        REQUIRE(result == -1);
    };
};

TEST_CASE("Margin Call Calculation result test")
{
    SECTION("Valid input test")
    {
        separator();
        TestDataContainer *testData = new TestDataContainer();
        CurrencyTypes *currencies = new CurrencyTypes();
        MoneyAmount *testMoney = new MoneyAmount(currencies->getUSD(), 50000);
        Day *someDay = new Day(1, 1, 2021);
        Day *calcDate = new Day(4, 1, 2021);
        PercentRate *interest = new PercentRate(12);
        PercentRate *maintance = new PercentRate(35);
        testData->populateClient("test", testMoney, testMoney, 1);
        testData->populateAreement(1, someDay, testMoney);
        testData->populateBroker("testBroker", maintance, 1, interest);
        testData->setCalcDate(calcDate);
        double result = calculateMarginCall(testData->client, testData->agreement, testData->broker, testData->calcDate);
        REQUIRE(std::round(result) == 23500);
    };
};