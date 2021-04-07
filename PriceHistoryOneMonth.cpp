//
// Created by Alfonso Meraz on 11/19/20.
//

#include "PriceHistoryOneMonth.h"

PriceHistoryOneMonth::PriceHistoryOneMonth() : PriceHistoryOneMonth("AAPL")
{

}

PriceHistoryOneMonth::PriceHistoryOneMonth(std::string ticker) {
    std::string url;
    url = setURL(ticker);
    http.connectURL(url);
    http.addParam("apikey", "");
    http.addParam("periodType", "month");
    http.addParam("period", "1");
    http.addParam("frequencyType" , "daily");
    http.addParam("frequency", "1");
    fillData();
}

std::string PriceHistoryOneMonth::setURL(std::string ticker){
    std::string url;
    url = "https://api.tdameritrade.com/v1/marketdata/" + ticker + "/pricehistory";
    return url;
}

void PriceHistoryOneMonth::getVolume(){
    for(int i = 0; i < j["candles"].size(); i++)
    {
        std::cout << "Day " << (i+1) << " Volume: "
            << (static_cast<int>(j["candles"][i]["volume"])) << std::endl;
    }
}
void PriceHistoryOneMonth::getClose(){
    for(int i = 0; i < j["candles"].size(); i++)
    {
        std::cout << "Day " << (i+1) << " Close: "
                  << (static_cast<double>(j["candles"][i]["close"])) << std::endl;
    }
}
void PriceHistoryOneMonth::getOpen(){
    for(int i = 0; i < j["candles"].size(); i++)
    {
        std::cout << "Day " << (i+1) << " Open: "
                  << (static_cast<double>(j["candles"][i]["open"])) << std::endl;
    }
}

int PriceHistoryOneMonth::getVolumeAt(int n) {
    return volume.at(n);
}

double PriceHistoryOneMonth::getCloseAt(int n) const{
    return close.at(n);
}

double PriceHistoryOneMonth::getPoint(int n) const
{
    return getCloseAt(n);
}

double PriceHistoryOneMonth::getOpenAt(int n) {
    return open.at(n);
}

int PriceHistoryOneMonth::size() const {
    return (j["candles"].size());
}

void PriceHistoryOneMonth::fillData() {
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

void PriceHistoryOneMonth::getData() {
    j = http.getURLJson();
}


double PriceHistoryOneMonth::calculateReturn(double initial, double final) {
    double percent;
    percent = ((final - initial) / initial) * 100;
    return percent;
}


double PriceHistoryOneMonth::getReturns() {
    fillData();
    double percent = calculateReturn(getCloseAt(0), getCloseAt(size() - 1));
    return percent;
}
PriceHistoryOneMonth::PriceHistoryOneMonth(const PriceHistoryOneMonth& priceHistory)
{
    *this = priceHistory;
}

double PriceHistoryOneMonth::getReturnAt(int n) {
    double percent;
    percent = ((getOpenAt(n) - getCloseAt(n)) / getOpenAt(n)) * 100;
    return percent;
}
