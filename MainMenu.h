//
// Created by Alfonso Meraz on 11/23/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_MAINMENU_H
#define STATISTICAL_FINANCIAL_DATA_MAINMENU_H
#include "SFML/Graphics.hpp"
#include <string>

class MainMenu : public sf::RectangleShape {
public:
    MainMenu();
    MainMenu(sf::Vector2f window);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
private:
    sf::RectangleShape button;
    sf::Text title;
    float x;
    float y;
    void createTitle();
};


#endif //STATISTICAL_FINANCIAL_DATA_MAINMENU_H
