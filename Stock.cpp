//
// Created by Alfonso Meraz on 11/19/20.
//

#include "Stock.h"

Stock::Stock() : Quotes("AAPL") {

}

Stock::Stock(std::string ticker) : PriceHistory(ticker),  Quotes(ticker) {

}

