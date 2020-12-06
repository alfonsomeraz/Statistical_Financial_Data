//
// Created by Alfonso Meraz on 11/19/20.
//

#include "Portfolio.h"

Portfolio::Portfolio() {

}

void Portfolio::addStock(std::string ticker) {
    Stock temp(ticker);
    portfolio.insert(temp);
}

int Portfolio::portfolioSize() {
    return portfolio.size();
}

bool Portfolio::checkEmpty() {
    return portfolio.checkEmpty();
}

void Portfolio::getPortfolio() {
    std::cout << "Portfolio:\n";
    for(int i = 0; i < portfolio.size(); i++)
        std::cout << portfolio.seek(i).getSymbol() << std::endl;
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

void Portfolio::remove(std::string ticker) {
    for(int i = 0; i < portfolioSize(); i++)
    {
        if(ticker == portfolio.seek(i).getSymbol())
        {
            portfolio.remove(portfolio.seek(i));
        }
    }
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
        std::cout << "3) Get yearly portfolio average returns.\n";
        std::cout << "4) Get year to date portfolio average returns.\n";
        std::cout << "5) Get month portfolio average returns.\n";
        std::cout << "6) Get yearly returns of single stock from portfolio.\n";
        std::cout << "7) Get month returns of single stock from portfolio.\n";
        std::cout << "8) Get year to date returns of single stock from portfolio.\n";
        std::cout << "9) Remove stock.\n";
        std::cout << "10) Get portfolio.\n";
        std::cout << "11) End.\n";
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
                std::cout << "Average portfolio returns: " << getAvgPortfolioReturnsYear() << "%" << std::endl;
                break;
            case 4:
                std::cout << "Average portfolio returns: " << getAvgPortfolioReturnsYTD() << "%" << std::endl;
                break;
            case 5:
                std::cout << "Average portfolio returns: " << getAvgPortfolioReturnsMonth() << "%" << std::endl;
                break;
            case 6:
                std::cout << "Enter stock ticker: ";
                std::cin >> ticker;
                std::cout << ticker << " returns: " << getYearReturnsOf(ticker) << "%" << std::endl;
                break;
            case 7:
                std::cout << "Enter stock ticker: ";
                std::cin >> ticker;
                std::cout << ticker << " returns: " << getMonthReturnsOf(ticker) << "%" << std::endl;
                break;
            case 8:
                std::cout << "Enter stock ticker: ";
                std::cin >> ticker;
                std::cout << ticker << " returns: " << getYTDReturnsOf(ticker) << "%" << std::endl;
                break;
            case 9:
                std::cout << "Enter stock ticker to remove: ";
                std::cin >> ticker;
                remove(ticker);
                break;
            case 10:
                getPortfolio();
                break;
            case 11:
                end = false;
                break;
        }
    }
}

double Portfolio::getMonthReturnsOf(std::string ticker) {
    for(int i = 0; i < portfolioSize(); i++)
    {
        if(ticker == portfolio.seek(i).getSymbol())
        {
            return portfolio.seek(i).getMonthReturns();
        }
    }
    return 0;
}

double Portfolio::getYearReturnsOf(std::string ticker) {
    for(int i = 0; i < portfolioSize(); i++)
    {
        if(ticker == portfolio.seek(i).getSymbol())
        {
            return portfolio.seek(i).getYearReturns();
        }
    }
    return 0;
}

double Portfolio::getYTDReturnsOf(std::string ticker) {
    for(int i = 0; i < portfolioSize(); i++)
    {
        if(ticker == portfolio.seek(i).getSymbol())
        {
            return portfolio.seek(i).getYTDReturns();
        }
    }
    return 0;
}

double Portfolio::getAvgPortfolioReturnsYear() {
    double sum = 0, avg;
    int stocks = portfolioSize();
    for(int i = 0; i < portfolio.size(); i++)
    {
        sum += portfolio.seek(i).getYearReturns();
    }
    avg = sum / stocks;
    return avg;
}

double Portfolio::getAvgPortfolioReturnsYTD() {
    double sum = 0, avg;
    int stocks = portfolioSize();
    for(int i = 0; i < portfolio.size(); i++)
    {
        sum += portfolio.seek(i).getYTDReturns();
    }
    avg = sum / stocks;
    return avg;
}

double Portfolio::getAvgPortfolioReturnsMonth() {
    double sum = 0, avg;
    int stocks = portfolioSize();
    for(int i = 0; i < portfolio.size(); i++)
    {
        sum += portfolio.seek(i).getMonthReturns();
    }
    avg = sum / stocks;
    return avg;
}
