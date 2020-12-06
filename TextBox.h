//
// Created by Alfonso Meraz on 12/6/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_TEXTBOX_H
#define STATISTICAL_FINANCIAL_DATA_TEXTBOX_H
#include "SFML/Graphics.hpp"
#include "States.h"

class TextBox : public sf::Drawable, public sf::Transformable{
public:
    TextBox();
private:
    sf::Text label;
    sf::RectangleShape inputBox;
    states state;
public:
    void setState(states state);
    void addEvent();
    void update();
    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;
};


#endif //STATISTICAL_FINANCIAL_DATA_TEXTBOX_H
