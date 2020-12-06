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
    for(int i = 0; i < portfolioSize(); i++)
    {
        if(ticker == portfolio[i].getSymbol())
        {
            return portfolio[i].getReturnYTD();
        }
    }
}

void Portfolio::remove(std::string ticker) {
    for(int i = 0; i < portfolioSize(); i++)
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

void Portfolio::portfolioInterface() {
    int ans;
    bool end = true;
    std::string ticker;
    std::cout << "Current portfolio:\n";
    while(end != false){
        if(checkEmpty())
        {
            std::cout << "Portfolio is empty.\n";
        }
        std::cout << "What would you like to do:\n";
        std::cout << "1) Set portfolio.\n";
        std::cout << "2) Add stock.\n";
        std::cout << "3) Get portfolio average returns.\n";
        std::cout << "4) Get returns of single stock from portfolio.\n";
        std::cout << "5) Remove stock.\n";
        std::cout << "6) Get portfolio.\n";
        std::cout << "7) End.\n";
        std::cout << ">> ";
        std::cin >> ans;
        switch(ans)
        {
            case 1:
                setPortfolio();
                break;
            case 2:
                std::cout << "Enter stock ticker: ";
                std::cin >> ticker;
                addStock(ticker);
                std::cout << std::endl;
                break;
            case 3:
                std::cout << "Average portfolio returns: " << getAvgPortfolioReturns() << "%" << std::endl;
                break;
            case 4:
                std::cout << "Enter stock ticker: ";
                std::cin >> ticker;
                std::cout << ticker << " returns: " << getReturnsOf(ticker) << "%" << std::endl;
                break;
            case 5:
                std::cout << "Enter stock ticker to remove: ";
                std::cin >> ticker;
                remove(ticker);
                break;
            case 6:
                getPortfolio();
                break;
            case 7:
                end = false;
                break;
        }
    }
}
