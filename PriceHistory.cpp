//
// Created by Alfonso Meraz on 11/19/20.
//

#include "PriceHistory.h"

PriceHistory::PriceHistory() : PriceHistory("AAPL")
{

}

PriceHistory::PriceHistory(std::string ticker, std::string periodType, std::string frequencyType)
{
    // Changing the URL to work with user entered ticker and data required
    std::string url;
    url = setURL(ticker);
    // Setting the newly created URL in the HTTP Request
    http.connectURL(url); // Replaces HTTPRequest http(url);
    // Setting the parameters
    setAPIkey("4XO5FV6PAQ4VGG3JWQ7GPKQIRNLYJLXG");
    setPeriodType(periodType);
    setPeriod("1");
    setFrequencyType(frequencyType);
    setFrequency("1");
    fillData();
}
std::string PriceHistory::setURL(std::string ticker){
    std::string url;
    url = "https://api.tdameritrade.com/v1/marketdata/" + ticker + "/pricehistory";
    return url;
}

void PriceHistory::setPeriodType(std::string periodType){

    http.addParam("periodType", periodType);
}
void PriceHistory::setPeriod(std::string period){

    http.addParam("period", period);
}
void PriceHistory::setFrequencyType(std::string frequencyType){

    http.addParam("frequencyType" , frequencyType);
}
void PriceHistory::setFrequency(std::string frequency){

    http.addParam("frequency", frequency);
}
void PriceHistory::setAPIkey(std::string key){

    http.addParam("apikey", key);
}
std::string PriceHistory::getPeriodType(){
    return getParam("periodType");
}
std::string PriceHistory::getPeriod(){
    return getParam("period");
}
std::string PriceHistory::getFrequencyType(){
    return getParam("frequencyType");
}
std::string PriceHistory::getFrequency(){
    return getParam("frequency");
}
std::string PriceHistory::getAPIkey(){
    return getParam("apikey");
}

void PriceHistory::totalVolume(){
    for(int i = 0; i < j["candles"].size(); i++)
    {
        std::cout << "Day " << (i+1) << " Volume: "
            << (static_cast<int>(j["candles"][i]["volume"])) << std::endl;
    }
}
void PriceHistory::totalClose(){
    for(int i = 0; i < j["candles"].size(); i++)
    {
        std::cout << "Day " << (i+1) << " Close: "
                  << (static_cast<double>(j["candles"][i]["close"])) << std::endl;
    }
}
void PriceHistory::totalOpen(){
    for(int i = 0; i < j["candles"].size(); i++)
    {
        std::cout << "Day " << (i+1) << " Open: "
                  << (static_cast<double>(j["candles"][i]["open"])) << std::endl;
    }
}

int PriceHistory::getVolume(int n) {
    return volume.at(n);
}

double PriceHistory::getClose(int n) const{
    return close.at(n);
}

double PriceHistory::getPoint(int n) const
{
    return getClose(n);
}

double PriceHistory::getOpen(int n) {
    return open.at(n);
}

int PriceHistory::size() const {
    return (j["candles"].size());
}

void PriceHistory::fillData() {
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

void PriceHistory::getData() {
    j = http.getURLJson();
}

PriceHistory::PriceHistory(std::string ticker) : PriceHistory(ticker, "month", "daily") {

}

double PriceHistory::calculateReturn(double initial, double final) {
    double percent;
    percent = ((final - initial) / initial) * 100;
    return percent;
}

double PriceHistory::getReturnYTD() {
    setPeriodType("ytd");
    fillData();
    double percent = calculateReturn(getClose(0), getClose(size()-1));
    return percent;
}

double PriceHistory::getReturnMonth() {
    setPeriodType("month");
    fillData();
    double percent = calculateReturn(getClose(0), getClose(size()-1));
    return percent;
}
PriceHistory::PriceHistory(const PriceHistory& priceHistory)
{
    *this = priceHistory;
}
