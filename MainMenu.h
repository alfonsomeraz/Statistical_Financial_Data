//
// Created by Alfonso Meraz on 11/23/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_MAINMENU_H
#define STATISTICAL_FINANCIAL_DATA_MAINMENU_H
#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>
#include "TextBox.h"

class MainMenu : public sf::RectangleShape {
public:
    MainMenu();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    sf::FloatRect getTickerBoxBounds();
private:
    void setScreen();
    void setTitles();
    void setClickBoxes();
    sf::Text stockTicker, currentPortfolio;
    sf::Font font;
    sf::RectangleShape portfolioBackground, tickerBox;
    TextBox inputBox;
};


#endif //STATISTICAL_FINANCIAL_DATA_MAINMENU_H
