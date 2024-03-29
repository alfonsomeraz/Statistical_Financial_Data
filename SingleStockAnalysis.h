//
// Created by Alfonso Meraz on 12/5/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_SINGLESTOCKANALYSIS_H
#define STATISTICAL_FINANCIAL_DATA_SINGLESTOCKANALYSIS_H
#include "SFML/Graphics.hpp"
#include "LineChart.h"
#include "Quotes.h"
#include "Stock.h"
#include "FundamentalsList.h"

class SingleStockAnalysis : public sf::Drawable, public sf::Transformable {
public:
    SingleStockAnalysis();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
private:
    Stock stock;
    FundamentalsList fundamentals;
    sf::Font font;
};


#endif //STATISTICAL_FINANCIAL_DATA_SINGLESTOCKANALYSIS_H
