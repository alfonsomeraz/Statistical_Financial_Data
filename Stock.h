//
// Created by Alfonso Meraz on 11/19/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_STOCK_H
#define STATISTICAL_FINANCIAL_DATA_STOCK_H
#include <string>
#include "PriceHistoryOneMonth.h"
#include "PriceHistoryYTD.h"
#include "PriceHistoryTwoYears.h"
#include "Quotes.h"

class Stock : public Quotes{
public:
    Stock();
    Stock(std::string ticker);
    double getYTDReturns();
    double getMonthReturns();
    double getYearReturns();
    friend bool operator==(const Stock& first, const Stock& second);
    friend bool operator!=(const Stock& first, const Stock& second);
private:
    PriceHistoryOneMonth stockMonth;
    PriceHistoryYTD stockYTD;
    PriceHistoryTwoYears stockYears;
    Quotes stockQuote;
    std::string stockTicker;
};


#endif //STATISTICAL_FINANCIAL_DATA_STOCK_H
