//
// Created by Alfonso Meraz on 11/23/20.
//

#include "MainMenu.h"

MainMenu::MainMenu()
{
    setScreen();
}


void MainMenu::setTitles() {
    if(!font.loadFromFile("OpenSans-Bold.ttf"))
    {
        std::cout << "Font did not load.\n";
        exit(1);
    }
    else{
        stockTicker.setFont(font);
        stockTicker.setString("Ticker:");
        stockTicker.setFillColor(sf::Color::White);
        stockTicker.setPosition(50, 20);
        currentPortfolio.setFont(font);
        currentPortfolio.setString("Current Portfolio:");
        currentPortfolio.setFillColor(sf::Color::White);
        currentPortfolio.setPosition(50, 300);
    }
}

void MainMenu::setScreen() {
    setTitles();
    setClickBoxes();
}

void MainMenu::setClickBoxes() {
    portfolioBackground.setFillColor(sf::Color::White);
    portfolioBackground.setSize({1200, 600});
    portfolioBackground.setPosition(50, 350);
}

void MainMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(stockTicker);
    window.draw(currentPortfolio);
    window.draw(portfolioBackground);
    window.draw(inputBox);
}

//sf::FloatRect MainMenu::getInputBoxBounds() {
//    return inputBox.getTickerBoxBounds();
//}

void MainMenu::addEvent(sf::RenderWindow &window, sf::Event event) {
    inputBox.addEvent(window, event);
}

void MainMenu::update(sf::RenderWindow &window, sf::Event event) {
    inputBox.update(window, event);
}



