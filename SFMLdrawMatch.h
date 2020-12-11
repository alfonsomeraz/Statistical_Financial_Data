//
// Created by Yu-Chung Chang on 12/9/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_SFMLDRAWMATCH_H
#define STATISTICAL_FINANCIAL_DATA_SFMLDRAWMATCH_H


#include "ReportDay.h"

class SFMLdrawMatch : public ReportDay, public sf::Drawable, public sf::Transformable{

private:
    sf::Text occasion;
    sf::Font font;

    sf::Text description, fullDescription, summary;


public:
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    SFMLdrawMatch();
};


#endif //STATISTICAL_FINANCIAL_DATA_SFMLDRAWMATCH_H
