//
// Created by Alfonso Meraz on 12/6/20.
//

#include "PriceHistoryYTD.h"

PriceHistoryYTD::PriceHistoryYTD() : PriceHistoryYTD("AAPL") {

}

PriceHistoryYTD::PriceHistoryYTD(std::string ticker) {
    std::string url;
    url = setURL(ticker);
    http.connectURL(url);
    http.addParam("apikey", "");
    http.addParam("periodType", "month");
    http.addParam("period", "1");
    fillData();
}

PriceHistoryYTD::PriceHistoryYTD(const PriceHistoryYTD &priceHistory) {
    *this = priceHistory;
}

void PriceHistoryYTD::getVolume() {
    for(int i = 0; i < j["candles"].size(); i++)
    {
        std::cout << "Day " << (i+1) << " Volume: "
                  << (static_cast<int>(j["candles"][i]["volume"])) << std::endl;
    }
}

void PriceHistoryYTD::getClose() {
    for(int i = 0; i < j["candles"].size(); i++)
    {
        std::cout << "Day " << (i+1) << " Close: "
                  << (static_cast<double>(j["candles"][i]["close"])) << std::endl;
    }
}

void PriceHistoryYTD::getOpen() {
    for(int i = 0; i < j["candles"].size(); i++)
    {
        std::cout << "Day " << (i+1) << " Open: "
                  << (static_cast<double>(j["candles"][i]["open"])) << std::endl;
    }
}

int PriceHistoryYTD::getVolumeAt(int n) {
    return volume.at(n);
}

double PriceHistoryYTD::getCloseAt(int n) const {
    return close.at(n);
}

double PriceHistoryYTD::getOpenAt(int n) {
    return open.at(n);
}

int PriceHistoryYTD::size() const {
    return (j["candles"].size());
}

void PriceHistoryYTD::fillData() {
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

double PriceHistoryYTD::getReturns() {
    fillData();
    double percent = calculateReturn(getCloseAt(0), getCloseAt(size()-1));
    return percent;
}

double PriceHistoryYTD::getPoint(int n) const {
    return getCloseAt(n);
}

std::string PriceHistoryYTD::setURL(std::string ticker) {
    std::string url;
    url = "https://api.tdameritrade.com/v1/marketdata/" + ticker + "/pricehistory";
    return url;
}

void PriceHistoryYTD::getData() {
    j = http.getURLJson();
}

double PriceHistoryYTD::calculateReturn(double initial, double final) {
    double percent;
    percent = ((final - initial) / initial) * 100;
    return percent;
}

double PriceHistoryYTD::getReturnAt(int n) {
    double percent;
    percent = ((getOpenAt(n) - getCloseAt(n)) / getOpenAt(n)) * 100;
    return percent;
}
