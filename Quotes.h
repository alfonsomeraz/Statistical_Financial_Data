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
    std::string getLastPrice();
    std::string getOpenPrice();
    std::string getHighPrice();
    std::string getLowPrice();
    std::string getClosePrice();
    std::string getNetChange();
    std::string getTotalVolume();
    std::string getVolatility();
    std::string get52WkHigh();
    std::string get52WkLow();
    std::string getPEratio();
    std::string getDivAmount();
    std::string getDivYield();
private:
    HTTPRequest http;
    std::string stockTicker;
    json j;
    std::string setURL(std::string ticker);
};


#endif //STATISTICAL_FINANCIAL_DATA_QUOTES_H
