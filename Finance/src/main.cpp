#include <Client.hpp>
#include <Broker.hpp>
#include <Agreement.hpp>
#include <MoneyAmount.hpp>
#include <CurrencyTypes.hpp>
#include <Currency.hpp>
#include <Logger.hpp>
#include <iomanip>
using namespace std;

double calculateAmountToMaintenanceRate(double currentClientMoneyOnAccount, double totalMoneyOnAccount, PercentRate* maintenanceRate){
    return totalMoneyOnAccount*maintenanceRate->getRate() - currentClientMoneyOnAccount;
};

bool underMaintenanceRate(double currentClientMoneyOnAccount, double totalMoneyOnAccount, PercentRate* marginMaintenanceRate){
    return currentClientMoneyOnAccount/totalMoneyOnAccount < marginMaintenanceRate->getRate();
};

int validateAgreement(Client *client, Agreement* agreement, Broker* broker, Logger logger){
    if( !(client->getAgreementId() == agreement->getId() && agreement->getId() == broker->getAgreementId())){
        logger.log(std::to_string(agreement->getId()) + " Invalid agreement between client and broker, cannot calculate margin call!");
        return -1;
    }

    return 0;
}

int validateClient(Client *client, Logger logger){

    if(client->getOwnMoneyInvested()->getQuantity() < 0){
        logger.log(client->getName() + " Negative invested amount!");
        return -1;
    }

    if(client->getOwnMoneyInvested()->getQuantity() < client->getTotal()->getQuantity() * 0.5){
        logger.log("Client " + client->getName() + " must invest 50 percent of total balance to qualify for a margin position!");
        logger.log("Client total: " + std::to_string(client->getTotal()->getQuantity()) +", client's invested: "+ std::to_string(client->getOwnMoneyInvested()->getQuantity()));
        return -1;
    }


    return 0;
}

int validateBroker(Broker *broker, Logger logger){
    if(broker->getPercentRate()->getRate() > 0.35 || broker->getPercentRate()->getRate() < 0.25){
        logger.log(broker->getName() + " Invalid margin maintenance rate");
        return -1;
    }

    if(broker->getBrokerInterest()->getRate() > 0.15 || broker->getBrokerInterest()->getRate() < 0 ){
        logger.log(broker->getName() + " Invalid broker interest rate");
        return -1;
    }

    return 0;
}

bool isBefore(Day* today, Day* calcDate){
    if(today->getYear() > calcDate->getYear())
        return true;
    if(today->getMonth() > calcDate->getMonth())
        return true;
    if(today->getDay() > calcDate->getDay())
        return true;
    return false;
    
}

int validateCalculationDate(Day *calculationDate, Logger logger){
    if(calculationDate->getWeekdayStr().compare("Saturday") == 0 || 
       calculationDate->getWeekdayStr().compare("Sunday") == 0 ){
           logger.log("Cannot calculate margin call on weekend");
           return -1;
       }

    if(!isBefore(calculationDate->getBusinessDay(), calculationDate)){
        logger.log("Cannot calculate margin call for future dates");
           return -1;
    }

    return 0;
}

int validateEntities(Client *client, Agreement* agreement, Broker* broker, Logger logger){
    if(validateAgreement(client, agreement, broker, logger) == -1)
        return -1;
    if(validateClient(client, logger) == -1)
        return -1;
    if(validateBroker(broker, logger) == -1)
        return -1;
    return 0;
}


double calculateMarginCall(Client *client, Agreement* agreement, Broker* broker, Day* currentDay){
    cout << "Starting Margin Call calculation for Client: " + client->getName() << " " << currentDay->toStringDate() << endl;
    Logger logger;
    if(validateCalculationDate(currentDay, logger) == -1){
        return -1;
    }
    if(validateEntities(client, agreement, broker, logger) == -1)
        return -1;
    PercentRate* marginMaintenanceRate = broker->getPercentRate();
    double currentValueOfClientOnMarket = agreement->getCurrentValueOfClientOnMarket()->convertToDollar()->getQuantity();
    double totalClientInvestment = client->getTotal()->convertToDollar()->getQuantity();
    if(currentValueOfClientOnMarket < totalClientInvestment){
        double currentClientAmount = currentValueOfClientOnMarket - client->getMoneyBorrowed()->convertToDollar()->getQuantity()
                                     - currentValueOfClientOnMarket * broker->getBrokerInterest()->getRate();
        if(currentClientAmount < 0){
            return -currentClientAmount + calculateAmountToMaintenanceRate(0,currentValueOfClientOnMarket ,marginMaintenanceRate);
        }else{
            if(underMaintenanceRate(currentClientAmount, currentValueOfClientOnMarket, marginMaintenanceRate)){
                return calculateAmountToMaintenanceRate(currentClientAmount, currentValueOfClientOnMarket, marginMaintenanceRate);
            }
        }
    }

    return 0;
};

int parseOutput(Client* client, Agreement *agreement,Broker* broker ,double result){
    Logger logger;
    if(result == -1){
        logger.log("Errors occured, margin call calculation failed");
        return -1;
    }
    if(result == 0){
        cout << client->getName() << " is above the margin maintenance rate of " << std::to_string(broker->getPercentRate()->getPercetRate()) << 
        " issued by broker " << broker->getName() << endl;
        cout << "Total initial investement: " << std::to_string(client->getTotal()->getQuantity()) << " " << client->getTotal()->getCurrency()->getCurrencyName()
        <<" ( Own money invested: " << client->getOwnMoneyInvested()->getQuantity() <<", money borrowed from broker: "<< client->getMoneyBorrowed()->getQuantity() <<" )"<< endl;
        cout<< "Current value on the stock: " << std::to_string(agreement->getCurrentValueOfClientOnMarket()->getQuantity()) << " " << agreement->getCurrentValueOfClientOnMarket()->getCurrency()->getCurrencyName() << endl;
        cout << "Profit (without broker interest): " << 
        std::to_string(agreement->getCurrentValueOfClientOnMarket()->getQuantity() - client->getTotal()->getQuantity()) << " "<<
        client->getTotal()->getCurrency()->getCurrencyName()
         << endl;
    }else{
    cout << client->getName() << " is NOT above the margin maintenance rate of " << std::to_string(broker->getPercentRate()->getPercetRate()) << 
        " issued by broker " << broker->getName() << " \nDeposit needed to stay above margin maintenance rate: " << std::to_string(result) << " " << client->getTotal()->getCurrency()->getCurrencyName() << endl;
        cout << "Total initial investement: " << std::to_string(client->getTotal()->getQuantity()) << " " << client->getTotal()->getCurrency()->getCurrencyName() 
        <<" ( Own money invested: " << client->getOwnMoneyInvested()->getQuantity() <<", money borrowed from broker: "<< client->getMoneyBorrowed()->getQuantity() <<" )"<< endl;
        cout<< "Current value on the stock: " << std::to_string(agreement->getCurrentValueOfClientOnMarket()->getQuantity()) << " " << agreement->getCurrentValueOfClientOnMarket()->getCurrency()->getCurrencyName() << endl;
        cout << "Loss (without broker interest): " << 
        std::to_string(agreement->getCurrentValueOfClientOnMarket()->getQuantity() - client->getTotal()->getQuantity()) << " "<<
        client->getTotal()->getCurrency()->getCurrencyName()
         << endl;

    }
    cout << "________________________________________________________________" << endl;
    cin.ignore();
    return 0;
}


int main(){
CurrencyTypes* currencies = new CurrencyTypes();
Agreement* agreement = new Agreement(1,
                                         new Day(1,1,2021)
);
Client * client = new Client("client13",
                                new MoneyAmount(currencies->getUSD(), 5000),
                                new MoneyAmount(currencies->getUSD(), 5000),
                                1             
);
Broker* broker = new Broker("broker13",
                             new PercentRate(35),
                             1,
                             new PercentRate(0)
);

Day* calcDate = new Day(23,12,2021);
double result = calculateMarginCall(client, agreement, broker, calcDate);
return parseOutput(client, agreement, broker, result);
}


