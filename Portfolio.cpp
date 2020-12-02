//
// Created by Alfonso Meraz on 11/19/20.
//

#include "Portfolio.h"

Portfolio::Portfolio() {

}

void Portfolio::addStock(std::string ticker) {
    Stock temp(ticker);
    portfolio.push_back(temp);
}

int Portfolio::portfolioSize() {
    return portfolio.size();
}

bool Portfolio::checkEmpty() {
    return portfolio.empty();
}

void Portfolio::getPortfolio() {
    std::cout << "Portfolio:\n";
    for(int i = 0; i < portfolio.size(); i++)
        std::cout << portfolio[i].getSymbol() << std::endl;
    int i = 0;
}

void Portfolio::setPortfolio() {
    char ans;
    bool check = false;
    std::string ticker;
    while(!check)
    {
        std::cout << "Enter the stock ticker:\n";
        std::cin >> ticker;
        addStock(ticker);
        std::cout << "Do you want to add more? (y/n)\n";
        std::cin >> ans;
        if((ans == 'n') || (ans == 'N'))
            check = true;
    }
}

double Portfolio::getReturnsOf(std::string ticker) {
    for(int i = 0; i < portfolio.size(); i++)
    {
        if(ticker == portfolio[i].getSymbol())
        {
            return portfolio[i].getReturnYTD();
        }
    }
}

void Portfolio::remove(std::string ticker) {
    for(int i = 0; i < portfolio.size(); i++)
    {
        if(ticker == portfolio[i].getSymbol())
        {
            portfolio.erase(portfolio.begin() + i);
        }
    }
}

double Portfolio::getAvgPortfolioReturns() {
    double sum = 0, avg;
    int stocks = portfolioSize();
    for(int i = 0; i < portfolio.size(); i++)
    {
        sum += portfolio[i].getReturnYTD();
    }
    avg = sum / stocks;
    return avg;
}
