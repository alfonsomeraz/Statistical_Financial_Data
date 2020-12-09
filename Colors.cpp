//
// Created by Yu-Chung Chang on 12/3/20.
//

#include "Colors.h"

void Colors::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    int x = 110;

    for(int i=0; i<size(); i++)
    {
        sf::RectangleShape c;
        c.setFillColor(at(i));
        c.setSize({100, 100});
        c.setPosition({(float)i*x, 200});
        window.draw(c);
        x += 110;
    }
}