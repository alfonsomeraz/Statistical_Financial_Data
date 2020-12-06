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
        }
        window.clear();
        window.draw(menu);
        window.display();
    }
}


