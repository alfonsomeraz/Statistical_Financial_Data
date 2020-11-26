//
// Created by Alfonso Meraz on 11/19/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_PRICEHISTORY_H
#define STATISTICAL_FINANCIAL_DATA_PRICEHISTORY_H
#include "HTTPRequest.h"
#include "JSON.h"
#include "ChartData.h"
#include <string>
#include <vector>

class PriceHistory : public HTTPRequest, public ChartData{
public:
    PriceHistory();
    PriceHistory(std::string ticker, std::string periodType, std::string frequencyType);
    PriceHistory(std::string ticker);
    PriceHistory(const PriceHistory& priceHistory);
    void setPeriodType(std::string periodType);
    void setPeriod(std::string period);
    void setFrequencyType(std::string frequencyType);
    void setFrequency(std::string frequency);
    void setAPIkey(std::string key);
    std::string getPeriodType();
    std::string getPeriod();
    std::string getFrequencyType();
    std::string getFrequency();
    std::string getAPIkey();
    void totalVolume();
    void totalClose();
    void totalOpen();
    int getVolume(int n);
    double getClose(int n) const;
    double getOpen(int n);
    virtual int size() const;
    void fillData();
    double getReturnYTD();
    double getReturnMonth();
    virtual double getPoint(int n) const;
private:
    json j;
    HTTPRequest http;
    std::vector<int> volume;
    std::vector<double> open;
    std::vector<double> close;
    std::string setURL(std::string ticker);
    // Hiding HTTPRequest public functions
    using HTTPRequest::connectURL;
    using HTTPRequest::getURLJson;
    using HTTPRequest::addParam;
    using HTTPRequest::getParam;
    void getData();
    double calculateReturn(double initial, double final);
};


#endif //STATISTICAL_FINANCIAL_DATA_PRICEHISTORY_H
