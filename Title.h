//
// Created by Yu-Chung Chang on 12/3/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_TITLE_H
#define STATISTICAL_FINANCIAL_DATA_TITLE_H


#include <SFML/Graphics.hpp>


class Title : public sf::Drawable, public sf::Transformable{

private:
    std::string text;
    sf::Text sfml_text;
    sf::Font font;

public:
    std::string getText();
    void setText(std::string text);
    Title();
    Title(std::string text);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void setupText();

};



#endif //STATISTICAL_FINANCIAL_DATA_TITLE_H
