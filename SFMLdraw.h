//
// Created by Yu-Chung Chang on 12/3/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_SFMLDRAW_H
#define STATISTICAL_FINANCIAL_DATA_SFMLDRAW_H


#include "ReportDay.h"

class SFMLdraw : public ReportDay, public sf::Drawable, public sf::Transformable{

private:
    sf::Text occasion;
    sf::Font font;

    sf::Text description, fullDescription, summary;


public:
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    SFMLdraw();
};

#endif //STATISTICAL_FINANCIAL_DATA_SFMLDRAW_H
