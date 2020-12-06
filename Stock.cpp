//
// Created by Alfonso Meraz on 11/19/20.
//

#include "Stock.h"

Stock::Stock() : Stock("AAPL") {

}

Stock::Stock(std::string ticker) : Quotes(ticker), stockTicker(ticker) {

}

double Stock::getYTDReturns() {
    return stockYTD.getReturns();
}

double Stock::getMonthReturns() {
    return stockMonth.getReturns();
}

double Stock::getYearReturns() {
    return stockYears.getReturns();
}

bool operator==(const Stock& first, const Stock& second)
{
    return (first.stockTicker == second.stockTicker);
}

bool operator!=(const Stock& first, const Stock& second)
{
    return (first.stockTicker != second.stockTicker);
}