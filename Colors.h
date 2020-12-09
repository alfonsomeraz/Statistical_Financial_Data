//
// Created by Yu-Chung Chang on 12/3/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_COLORS_H
#define STATISTICAL_FINANCIAL_DATA_COLORS_H


#include <vector>
#include <SFML/Graphics.hpp>
class Colors : public std::vector<sf::Color>, public sf::Drawable{
public:
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

};



#endif //STATISTICAL_FINANCIAL_DATA_COLORS_H
