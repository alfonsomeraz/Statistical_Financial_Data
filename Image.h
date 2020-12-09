//
// Created by Yu-Chung Chang on 12/3/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_IMAGE_H
#define STATISTICAL_FINANCIAL_DATA_IMAGE_H


#include "Title.h"
#include <SFML/Graphics.hpp>
class Image : public Title{
//class Image{

private:
    sf::Texture texture;
    sf::Sprite sprite;
    std::string filepath;
    //   sf::RectangleShape square;


public:
    void setFilepath(std::string filepath);
    std::string getFilepath();
    void setSprite();
    Image(std::string filepath);
    Image();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setTexture();
    void setScale(float x, float y);
    void setPosition(float x, float y);

//    void setSize({float x, float y});
//    void setFillColor(sf::Color::White);
    // void setPosition({float x, float y});
};



#endif //STATISTICAL_FINANCIAL_DATA_IMAGE_H
