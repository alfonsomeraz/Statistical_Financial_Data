//
// Created by Alfonso Meraz on 12/6/20.
//

#include "TextBox.h"

TextBox::TextBox() {
    setBox();
    setText();
}

void TextBox::setState(states state) {
    this->state = state;
}

void TextBox::addEvent(sf::RenderWindow& window, sf::Event event) {
    sf::Vector2f mpos = (sf::Vector2f)sf::Mouse::getPosition(window);
    if(getTickerBoxBounds().contains(mpos) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {

        state = TYPETEXTENABLED;
        //std::cout << "state is " << state << std::endl;
    }
    if(event.text.unicode == sf::Keyboard::Return)
    {
        state = TYPETEXTDISABLED;
    }
}

void TextBox::update(sf::RenderWindow& window, sf::Event event) {
    //std::cout << "Now state is " << state << std::endl;
    if(state == TYPETEXTENABLED)
    {
        //std::cout << "here" << std::endl;
        input = text.getString();
        if (event.type == sf::Event::TextEntered)
        {
            std::cout << std::string(input).substr(0, input.getSize()-1) << std::endl;
            if(event.text.unicode == sf::Keyboard::BackSpace){
//                input = std::string(input).substr(0, input.getSize() - 1);
                input.erase(input.getSize() - 1,1);
            }
            else
                input += event.text.unicode;
            text.setString(input);
        }
    }
}

void TextBox::draw(sf::RenderTarget &window, sf::RenderStates state) const {
    window.draw(tickerBox);
    window.draw(text);
}

states TextBox::getState() {
    return state;
}

void TextBox::setBox() {
    tickerBox.setFillColor(sf::Color::White);
    tickerBox.setSize({1050, 50});
    tickerBox.setPosition(180, 20);
}

void TextBox::setText() {
    if(!font.loadFromFile("OpenSans-Bold.ttf"))
    {
        std::cout << "not loading." << std::endl;
        exit(1);
    }
    text.setFont(font);
    text.setFillColor(sf::Color::Blue);
    text.setPosition(180,20);
    text.setCharacterSize(30);
}

sf::FloatRect TextBox::getTickerBoxBounds() {
    return tickerBox.getGlobalBounds();
}