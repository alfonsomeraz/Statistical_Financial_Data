//
// Created by Alfonso Meraz on 11/19/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_STOCK_H
#define STATISTICAL_FINANCIAL_DATA_STOCK_H
#include <string>
#include "PriceHistory.h"
#include "FundamentalsCalc.h"
#include "Quotes.h"
#include "LineChart.h"
#include <stack>

class Stock : public PriceHistory, public Quotes{
public:
    Stock();
    Stock(std::string ticker);
    void fillCharts();
private:
    PriceHistory stockTicker;
    Quotes stockQuote;
    std::stack<LineChart> priceCharts;
};


#endif //STATISTICAL_FINANCIAL_DATA_STOCK_H
