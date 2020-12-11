//
// Created by Yu-Chung Chang on 11/26/20.
//

#include "DollarBill.h"
#include <iostream>


DollarBill::DollarBill() : sf::RectangleShape()

{
//    setSize({8,25}); // setting a dimension of a rectangle (pix)
//    // 8 ~ window_width(1920) / # days; 25 ~ window_height(1080) / Max-vol
//    setFillColor(sf::Color::Green);
//    setOutlineColor(sf::Color::Red);
//    setOutlineThickness(1.0f);

///////////// reuse below///////////////////////////
//    std::cout<<std::endl<<"Here" << std::endl;
//    if(!texture.loadFromFile("Dollar.png"))
//    {
//        std::cout << "Error could not load dollar image" << std::endl;
//        exit(1);
//    }
/////////////////////////////////////////////////////////
//    dollarImage.setTexture(texture);
//    dollarImage.setScale({.2, .2});
//////////////////reuse below/////////////////////////////////
   // setTexture(&texture);//make a reference to our texture

//////////////////////////////////////////////////////////
//    setFillColor(sf::Color::Blue);
//    setOutlineColor(sf::Color::Red);
//    setOutlineThickness(1.0f);
}

void DollarBill::setTexture(sf::Texture *texture)
{
    sf::RectangleShape::setTexture(texture);
    setScale({2, 1});
    setSize({8,25});  // 1920 / 229 = 8.38; (1920-50=1870; 1870/229 = 8.16)
}