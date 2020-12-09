//
// Created by Alfonso Meraz on 12/9/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_FUNDAMENTALSLIST_H
#define STATISTICAL_FINANCIAL_DATA_FUNDAMENTALSLIST_H

#include "Quotes.h"
#include "SFML/Graphics.hpp"
#include "Stock.h"

class FundamentalsList : public Stock{
public:
    FundamentalsList();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
private:
    sf::Text assetType, symbol, description, lastPrice,
    openPrice, highPrice, lowPrice, closePrice, netChange,
    totalVolume, volatility, weekHigh52, weekLow52, pERatio,
    divAmount, divYield;
    sf::Font font;
    Quotes quote;
    void setPositions();
    void setFonts();
    void setStrings();
    void setColors();
    void setText();
};


#endif //STATISTICAL_FINANCIAL_DATA_FUNDAMENTALSLIST_H
