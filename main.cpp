#include <iostream>
#include "PriceHistory.h"
#include "Stock.h"
#include <SFML/Graphics.hpp>
#include "LineChart.h"

int main() {
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

    PriceHistory stock("AAPL", "ytd", "daily"),
                 stock2("AMD", "ytd", "daily"),
                 stock3("JD", "ytd", "daily");
    for(int i = 0; i < stock.size(); i++)
        std::cout << stock.getClose(i) << " ";
    std::cout << std::endl;
    for(int i = 0; i < stock2.size(); i++)
        std::cout << stock2.getClose(i) << " ";
    std::cout << std::endl;
    for(int i = 0; i < stock3.size(); i++)
        std::cout << stock3.getClose(i) << " ";
    std::cout << std::endl;


    int windowWidth = 1200;
    int windowHeight = 800;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML window");

    LineChart cd(stock, (sf::Vector2i)window.getSize(), 50);
    LineChart cd2(stock2, (sf::Vector2i)window.getSize(), 50);
    LineChart cd3(stock3, (sf::Vector2i)window.getSize(), 50);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(cd);
        window.draw(cd2);
        window.draw(cd3);
        window.display();
    }
    return 0;
}
