//
// Created by Yu-Chung Chang on 11/26/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_HISTOGRAM_H
#define STATISTICAL_FINANCIAL_DATA_HISTOGRAM_H


#include <SFML/Graphics.hpp>
#include "DollarBill.h"
//#include "Constants.h"
#include <iostream>
class Histogram : public sf::Drawable, public sf::Transformable{

private:
    int *data; //y value
    DollarBill **d;// 2d array full of rectangles
    DollarBill dollar;
//    void update(); //position where the data should be in the screen

    sf::Texture *texture;
    sf::Sprite sprite;
    int yearsize;


    sf::Text legend;
    sf::Font font;

    sf::Text description, fullDescription, summary;

public:
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void add(int bin, int y);
    void add(int bin);
    Histogram();
    Histogram(int yearsize);
    void update(); //position where the data should be in the screen
    Histogram(const Histogram& h);          //copy ctor
    Histogram& operator=(const Histogram& h); //assignment operator
    ~Histogram();

//    SFMLLegendDraw();


};

#endif //STATISTICAL_FINANCIAL_DATA_HISTOGRAM_H
