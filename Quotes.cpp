//
// Created by Alfonso Meraz on 11/20/20.
//

#include "Quotes.h"

Quotes::Quotes() : Quotes("AAPL"){

}

Quotes::Quotes(std::string ticker) : stockTicker(ticker) {
    std::string url;
    url = setURL(ticker);
    http.connectURL(url);
    http.addParam("apikey", "4XO5FV6PAQ4VGG3JWQ7GPKQIRNLYJLXG");
    j = http.getURLJson();
}

std::string Quotes::setURL(std::string ticker) {
    std::string url;
    url = "https://api.tdameritrade.com/v1/marketdata/" + ticker + "/quotes";
    return url;
}

std::string Quotes::getAssetType() {
    return j[stockTicker]["assetType"];
}

std::string Quotes::getSymbol() {
    return j[stockTicker]["symbol"];
}

std::string Quotes::getDescription() {
    return j[stockTicker]["description"];
}

double Quotes::getLastPrice() {
    return (static_cast<double>(j[stockTicker]["lastPrice"]));
}

double Quotes::getOpenPrice() {
    return (static_cast<double>(j[stockTicker]["openPrice"]));
}

double Quotes::getHighPrice() {
    return (static_cast<double>(j[stockTicker]["highPrice"]));
}

double Quotes::getLowPrice() {
    return (static_cast<double>(j[stockTicker]["lowPrice"]));
}

double Quotes::getClosePrice() {
    return (static_cast<double>(j[stockTicker]["closePrice"]));
}

double Quotes::getNetChange() {
    return (static_cast<double>(j[stockTicker]["netChange"]));
}

int Quotes::getTotalVolume() {
    return (static_cast<int>(j[stockTicker]["totalVolume"]));
}

double Quotes::getVolatility() {
    return (static_cast<double>(j[stockTicker]["volatility"]));
}

double Quotes::get52WkHigh() {
    return (static_cast<double>(j[stockTicker]["52WkHigh"]));
}

double Quotes::get52WkLow() {
    return (static_cast<double>(j[stockTicker]["52WkLow"]));
}

double Quotes::getPEratio() {
    return (static_cast<double>(j[stockTicker]["peRatio"]));
}

double Quotes::getDivAmount() {
    return (static_cast<double>(j[stockTicker]["divAmount"]));
}

double Quotes::getDivYield() {
    return (static_cast<double>(j[stockTicker]["divYield"]));
}
