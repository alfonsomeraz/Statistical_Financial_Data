//
// Created by Yu-Chung Chang on 12/3/20.
//

#include "Title.h"

std::string Title::getText()
{
    return text;
}
void Title::setText(std::string title)
{
    this->text = title;
    setupText();

}
Title::Title() : Title("")
{

}
Title::Title(std::string text) : text(text)
{
    setupText();

}

void Title::setupText()
{
    if(!font.loadFromFile("OpenSans-Bold-1.ttf"))
        exit(5);

    sfml_text.setFont(font);
    sfml_text.setCharacterSize(96);
    sfml_text.setFillColor(sf::Color::White);
    sfml_text.setString(text);
}
void Title::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(sfml_text);
}