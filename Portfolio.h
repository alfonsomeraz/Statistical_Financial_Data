//
// Created by Alfonso Meraz on 11/19/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_PORTFOLIO_H
#define STATISTICAL_FINANCIAL_DATA_PORTFOLIO_H
#include <string>
#include <vector>
#include "Stock.h"
#include <stack>

class Portfolio {
public:
    Portfolio();
    void addStock(std::string ticker);
    int portfolioSize();
    bool checkEmpty();
    void getPortfolio();
    void setPortfolio();
    double getAvgPortfolioReturns();
    double getReturnsOf(std::string ticker);
    void remove(std::string ticker);
    void portfolioInterface();
private:
    std::vector<Stock> portfolio;
};


#endif //STATISTICAL_FINANCIAL_DATA_PORTFOLIO_H
