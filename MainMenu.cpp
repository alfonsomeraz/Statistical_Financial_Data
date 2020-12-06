//
// Created by Alfonso Meraz on 11/23/20.
//

#include "MainMenu.h"

MainMenu::MainMenu() {

}

MainMenu::MainMenu(sf::Vector2f window) {
    x = window.x;
    y = window.y;
    createTitle();
    title.setPosition(x/2, y/2);
}

void MainMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(title);
}

void MainMenu::createTitle() {
    title.setString("Statistics for Financial Data");
    title.setFillColor(sf::Color::White);
}

