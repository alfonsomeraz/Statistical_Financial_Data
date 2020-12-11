//
// Created by Alfonso Meraz on 12/6/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_TEXTBOX_H
#define STATISTICAL_FINANCIAL_DATA_TEXTBOX_H
#include "SFML/Graphics.hpp"
#include "States.h"
#include <iostream>

class TextBox : public sf::Drawable, public sf::Transformable{
public:
    TextBox();
private:
    sf::Text text;
    sf::String input;
    sf::RectangleShape tickerBox;
    sf::Font font;
    states state;
    void setBox();
    void setText();
public:
    void setState(states state);
    sf::FloatRect getTickerBoxBounds();
    states getState();
    void addEvent(sf::RenderWindow& window, sf::Event event);
    void update(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;
};


#endif //STATISTICAL_FINANCIAL_DATA_TEXTBOX_H
