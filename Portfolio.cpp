//
// Created by Alfonso Meraz on 11/19/20.
//

#include "Portfolio.h"

Portfolio::Portfolio() {

}

void Portfolio::addStock(std::string ticker) {
    Stock temp(ticker);
    portfolio.push(temp);
}

int Portfolio::portfolioSize() {
    return portfolio.size();
}

bool Portfolio::checkEmpty() {
    return portfolio.empty();
}

void Portfolio::getPortfolio() {
    std::cout << "Portfolio:\n";
    while(!portfolio.empty())
    {
        std::cout << portfolio.top().getSymbol() << std::endl;
        portfolio.pop();
    }
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
