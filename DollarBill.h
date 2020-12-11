//
// Created by Yu-Chung Chang on 11/26/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_DOLLARBILL_H
#define STATISTICAL_FINANCIAL_DATA_DOLLARBILL_H
#include <SFML/Graphics.hpp>

class DollarBill : public sf::RectangleShape{

public:
    DollarBill();
    void setTexture(sf::Texture *texture);

};


//class DollarBill : public sf::RectangleShape {
//private:
//    sf::Texture texture;
//    sf::Sprite dollarImage;
//public:
//    DollarBill();
////    virtual void draw(sf::RenderTarget& window, sf::RenderStates state) const;
//};


#endif //STATISTICAL_FINANCIAL_DATA_DOLLARBILL_H
