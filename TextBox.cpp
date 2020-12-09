//
// Created by Alfonso Meraz on 12/6/20.
//

#include "TextBox.h"

TextBox::TextBox() {

}

void TextBox::setState(states state) {
    this->state = state;
}

void TextBox::addEvent() {

}

void TextBox::update() {

}

void TextBox::draw(sf::RenderTarget &window, sf::RenderStates state) const {
//    switch(this->state)
//    {
//        case STOCK:
//
//    }
}

states TextBox::getState() {
    return state;
}
