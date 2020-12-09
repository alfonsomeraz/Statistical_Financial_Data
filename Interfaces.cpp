//
// Created by Alfonso Meraz on 12/5/20.
//

#include "Interfaces.h"

Interfaces::Interfaces() : window({1920, 1080, 32}, "Statistical Financial Data") {
    setButtons();
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
                sf::FloatRect startBounds = startButton.getGlobalBounds();
                sf::FloatRect menuBounds = mainMenuButton.getGlobalBounds();
                switch(state)
                {
                    case SPLASH:
                        if(startBounds.contains(mpos))
                        {
                            state = MAINMENU;
                        }
                        break;
                    case MAINMENU:
                        if(menuBounds.contains(mpos))
                        {
                            state = MAINMENU;
                        }
                        if(menu.getTickerBoxBounds().contains(mpos))
                        {
                            state = STOCK;
                        }
                        break;
                    case STOCK:
                        if(menuBounds.contains(mpos))
                        {
                            state = MAINMENU;
                        }
                        break;
                }
            }
        }
        window.clear();
        switch(state)
        {
            case SPLASH:
                window.draw(splashPage);
                window.draw(startButton);
                break;
            case MAINMENU:
                window.draw(menu);
                window.draw(mainMenuButton);
                window.draw(mainMenu);
                break;
            case PORTFOLIO:
                break;
            case STOCK:
                window.draw(stockPage);
                window.draw(mainMenuButton);
                window.draw(mainMenu);
                break;
            default:
                std::cout << "State error occurred" << std::endl;
                break;
        }
        window.display();
    }
}

void Interfaces::setButtons() {
    setStartButton();
    setMainMenuButton();
}

void Interfaces::setStartButton() {
    startButton.setSize({100, 100});
    startButton.setFillColor(sf::Color::Cyan);
    startButton.setPosition({1650, 750});
    startButton.setOutlineColor(sf::Color::Red);
    startButton.setOutlineThickness(1.0f);
}

void Interfaces::setMainMenuButton() {
    mainMenuButton.setSize({200, 50});
    mainMenuButton.setFillColor(sf::Color::Blue);
    mainMenuButton.setPosition({1600, 20});
    mainMenuButton.setOutlineColor(sf::Color::White);
    mainMenuButton.setOutlineThickness(1.0f);
    font.loadFromFile("OpenSans-Bold.ttf");
    mainMenu.setFont(font);
    mainMenu.setString("Main Menu");
    mainMenu.setFillColor(sf::Color::White);
    mainMenu.setPosition({1620, 25});
}

