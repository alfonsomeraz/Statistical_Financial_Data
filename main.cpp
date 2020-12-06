#include <iostream>
#include "PriceHistoryOneMonth.h"
#include "PriceHistoryYTD.h"
#include "PriceHistoryTwoYears.h"
#include "Stock.h"
#include <SFML/Graphics.hpp>
#include "LineChart.h"
#include <vector>
#include "Portfolio.h"
#include "MainMenu.h"
#include "Interfaces.h"

int main() {
//    Portfolio portfolio;
//    portfolio.portfolioInterface();
//    Interfaces project;
//    project.run();
    PriceHistoryOneMonth stock("AAPL");
    PriceHistoryYTD stock1("AAPL");
    PriceHistoryTwoYears stock2("AAPL");
    std::cout << stock.getReturns() << ", " << stock1.getReturns() << ", " << stock2.getReturns() << std::endl;

    for(int i=0; i<stock.size();i++)
        std::cout << stock.getReturnAt(i) << std::endl;

    // Price History Guide
    // periodType: (The type of period to show)
    // day, month, year, ytd
    // period: (The number of periods to show)
    // day: 1, 2, 3, 4, 5, 10*
    // month: 1*, 2, 3, 6
    // year: 1*, 2, 3, 5, 10, 15, 20
    // ytd: 1*
    // frequencyType: (The type of frequency with which a new candle is formed)
    // day: minute
    // month: daily, weekly
    // year: daily, weekly, monthly
    // ytd: daily, weekly
    // frequency: (The number of the frequencyType to be included in each candle)
    // minute: 1*, 5, 10, 15, 30
    // daily: 1*
    // weekly: 1*
    // monthly: 1*
//    PriceHistoryOneMonth stock("AAPL", "year", "daily"),
//                 stock2("AMD", "year", "daily"),
//                 stock3("JD", "year", "daily");
//    for(int i = 0; i < stock.size(); i++)
//        std::cout << stock.getCloseAt(i) << " ";
//    std::cout << std::endl;
//    for(int i = 0; i < stock2.size(); i++)
//        std::cout << stock2.getCloseAt(i) << " ";
//    std::cout << std::endl;
//    for(int i = 0; i < stock3.size(); i++)
//        std::cout << stock3.getCloseAt(i) << " ";
//    std::cout << std::endl;


//    sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML window");
//
//    LineChart cd1(stock, (sf::Vector2i)window.getSize(), 50);
//    LineChart cd2(stock2, (sf::Vector2i)window.getSize(), 50);
//    LineChart cd3(stock3, (sf::Vector2i)window.getSize(), 50);
//
//    std::vector<LineChart> v;
//    v.push_back(cd1);
//    v.push_back(cd2);
//    v.push_back(cd3);
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            // Close window: exit
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//        window.clear();
//        for(auto i : v)
//            window.draw(i);
//        window.display();
//    }
    return 0;
}
