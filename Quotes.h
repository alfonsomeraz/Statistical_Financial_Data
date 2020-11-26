//
// Created by Alfonso Meraz on 11/20/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_QUOTES_H
#define STATISTICAL_FINANCIAL_DATA_QUOTES_H
#include <string>
#include "HTTPRequest.h"

class Quotes : public HTTPRequest {
public:
    Quotes();
    Quotes(std::string ticker);
    std::string getAssetType();
    std::string getSymbol();
    std::string getDescription();
    double getLastPrice();
    double getOpenPrice();
    double getHighPrice();
    double getLowPrice();
    double getClosePrice();
    double getNetChange();
    int getTotalVolume();
    double getVolatility();
    double get52WkHigh();
    double get52WkLow();
    double getPEratio();
    double getDivAmount();
    double getDivYield();
private:
    HTTPRequest http;
    std::string stockTicker;
    json j;
    std::string setURL(std::string ticker);
};


#endif //STATISTICAL_FINANCIAL_DATA_QUOTES_H
