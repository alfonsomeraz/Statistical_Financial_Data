//
// Created by Alfonso Meraz on 12/5/20.
//

#include "Interfaces.h"

Interfaces::Interfaces() : window({1920, 1080, 32}, "Statistical Financial Data") {

}

void Interfaces::run() {
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2f mpos = (sf::Vector2f)sf::Mouse::getPosition(window);
                sf::FloatRect
                switch(state)
                {
                    case SPLASH:
                        if()
                }
            }
        }
        window.clear();
        window.draw(menu);
        window.draw(chart);
        window.display();
    }
}

