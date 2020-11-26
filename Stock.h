//
// Created by Alfonso Meraz on 11/19/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_STOCK_H
#define STATISTICAL_FINANCIAL_DATA_STOCK_H
#include <string>
#include "PriceHistory.h"
#include "FundamentalsCalc.h"
#include "Quotes.h"

class Stock : public PriceHistory, public Quotes{
public:
    Stock();
    Stock(std::string ticker);
private:
    PriceHistory stockTicker;
    Quotes stockQuote;
};


#endif //STATISTICAL_FINANCIAL_DATA_STOCK_H
