//
// Created by Alfonso Meraz on 12/5/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_INTERFACES_H
#define STATISTICAL_FINANCIAL_DATA_INTERFACES_H
#include "SFML/Graphics.hpp"
#include "SingleStockAnalysis.h"
#include "MainMenu.h"
#include "Stock.h"
#include "States.h"

class Interfaces {
public:
    Interfaces();
    sf::RenderWindow window;
    void run();
private:
    MainMenu menu;
    Stock stock;
    LineChart chart;
    states state;
};


#endif //STATISTICAL_FINANCIAL_DATA_INTERFACES_H
