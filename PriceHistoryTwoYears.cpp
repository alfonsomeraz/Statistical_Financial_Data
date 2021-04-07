//
// Created by Alfonso Meraz on 12/6/20.
//

#include "PriceHistoryTwoYears.h"

PriceHistoryTwoYears::PriceHistoryTwoYears() : PriceHistoryTwoYears("AAPL") {

}

PriceHistoryTwoYears::PriceHistoryTwoYears(std::string ticker) {
    std::string url;
    url = setURL(ticker);
    http.connectURL(url);
    http.addParam("apikey", "");
    http.addParam("periodType", "year");
    http.addParam("period", "2");
    http.addParam("frequencyType", "daily");
    http.addParam("frequency", "1");
    fillData();
}

PriceHistoryTwoYears::PriceHistoryTwoYears(const PriceHistoryTwoYears &priceHistory) {
    *this = priceHistory;
}

void PriceHistoryTwoYears::getVolume() {
    for(int i = 0; i < j["candles"].size(); i++)
    {
        std::cout << "Day " << (i+1) << " Volume: "
                  << (static_cast<int>(j["candles"][i]["volume"])) << std::endl;
    }
}

void PriceHistoryTwoYears::getClose() {
    for(int i = 0; i < j["candles"].size(); i++)
    {
        std::cout << "Day " << (i+1) << " Close: "
                  << (static_cast<double>(j["candles"][i]["close"])) << std::endl;
    }
}

void PriceHistoryTwoYears::getOpen() {
    for(int i = 0; i < j["candles"].size(); i++)
    {
        std::cout << "Day " << (i+1) << " Open: "
                  << (static_cast<double>(j["candles"][i]["open"])) << std::endl;
    }
}

int PriceHistoryTwoYears::getVolumeAt(int n) {
    return volume.at(n);
}

double PriceHistoryTwoYears::getCloseAt(int n) const {
    return close.at(n);
}

double PriceHistoryTwoYears::getOpenAt(int n) {
    return open.at(n);
}

int PriceHistoryTwoYears::size() const {
    return (j["candles"].size());
}

void PriceHistoryTwoYears::fillData() {
    volume.clear();
    close.clear();
    open.clear();
    getData();
    for(int i = 0; i < j["candles"].size(); i++)
    {
        volume.push_back(static_cast<int>(j["candles"][i]["volume"]));
        close.push_back(static_cast<double>(j["candles"][i]["close"]));
        open.push_back(static_cast<double>(j["candles"][i]["open"]));
    }
}

double PriceHistoryTwoYears::getReturns() {
    fillData();
    double percent = calculateReturn(getCloseAt(0), getCloseAt(size()-1));
    return percent;
}

double PriceHistoryTwoYears::getPoint(int n) const {
    return getCloseAt(n);
}

std::string PriceHistoryTwoYears::setURL(std::string ticker) {
    std::string url;
    url = "https://api.tdameritrade.com/v1/marketdata/" + ticker + "/pricehistory";
    return url;
}

void PriceHistoryTwoYears::getData() {
    j = http.getURLJson();
}

double PriceHistoryTwoYears::calculateReturn(double initial, double final) {
    double percent;
    percent = ((final - initial) / initial) * 100;
    return percent;
}

double PriceHistoryTwoYears::getReturnAt(int n) {
    double percent;
    percent = ((getOpenAt(n) - getCloseAt(n)) / getOpenAt(n)) * 100;
    return percent;
}
