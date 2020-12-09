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

std::string Quotes::getLastPrice() {
    return std::to_string(static_cast<double>(j[stockTicker]["lastPrice"]));
}

std::string Quotes::getOpenPrice() {
    return std::to_string(static_cast<double>(j[stockTicker]["openPrice"]));
}

std::string Quotes::getHighPrice() {
    return std::to_string(static_cast<double>(j[stockTicker]["highPrice"]));
}

std::string Quotes::getLowPrice() {
    return std::to_string(static_cast<double>(j[stockTicker]["lowPrice"]));
}

std::string Quotes::getClosePrice() {
    return std::to_string(static_cast<double>(j[stockTicker]["closePrice"]));
}

std::string Quotes::getNetChange() {
    return std::to_string(static_cast<double>(j[stockTicker]["netChange"]));
}

std::string Quotes::getTotalVolume() {
    return std::to_string(static_cast<int>(j[stockTicker]["totalVolume"]));
}

std::string Quotes::getVolatility() {
    return std::to_string(static_cast<double>(j[stockTicker]["volatility"]));
}

std::string Quotes::get52WkHigh() {
    return std::to_string(static_cast<double>(j[stockTicker]["52WkHigh"]));
}

std::string Quotes::get52WkLow() {
    return std::to_string(static_cast<double>(j[stockTicker]["52WkLow"]));
}

std::string Quotes::getPEratio() {
    return std::to_string(static_cast<double>(j[stockTicker]["peRatio"]));
}

std::string Quotes::getDivAmount() {
    return std::to_string(static_cast<double>(j[stockTicker]["divAmount"]));
}

std::string Quotes::getDivYield() {
    return std::to_string(static_cast<double>(j[stockTicker]["divYield"]));
}
