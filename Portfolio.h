//
// Created by Alfonso Meraz on 11/19/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_PORTFOLIO_H
#define STATISTICAL_FINANCIAL_DATA_PORTFOLIO_H
#include <string>
#include <vector>
#include "Stock.h"

class Portfolio {
public:
    Portfolio();

private:
    std::vector<Stock> stocks;
};


#endif //STATISTICAL_FINANCIAL_DATA_PORTFOLIO_H
