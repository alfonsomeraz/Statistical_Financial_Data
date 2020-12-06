//
// Created by Alfonso Meraz on 12/6/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_PRICEHISTORYYTD_H
#define STATISTICAL_FINANCIAL_DATA_PRICEHISTORYYTD_H
#include "HTTPRequest.h"
#include "JSON.h"
#include "ChartData.h"
#include <string>
#include <vector>

class PriceHistoryYTD : public HTTPRequest, public ChartData{
public:
    PriceHistoryYTD();
    PriceHistoryYTD(std::string ticker);
    PriceHistoryYTD(const PriceHistoryYTD& priceHistory);
    void getVolume();
    void getClose();
    void getOpen();
    int getVolumeAt(int n);
    double getCloseAt(int n) const;
    double getOpenAt(int n);
    virtual int size() const;
    void fillData();
    double getReturns();
    double getReturnAt(int n);
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


#endif //STATISTICAL_FINANCIAL_DATA_PRICEHISTORYYTD_H
