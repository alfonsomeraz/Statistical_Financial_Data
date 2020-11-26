//
// Created by Alfonso Meraz on 11/23/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_CHARTS_H
#define STATISTICAL_FINANCIAL_DATA_CHARTS_H
#include <SFML/Graphics.hpp>


class Charts : public sf::Drawable, public sf::Transformable{
public:
    Charts();
    Charts(std::string ticker, sf::RenderWindow& window);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
private:
};


#endif //STATISTICAL_FINANCIAL_DATA_CHARTS_H
