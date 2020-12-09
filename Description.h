//
// Created by Yu-Chung Chang on 12/3/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_DESCRIPTION_H
#define STATISTICAL_FINANCIAL_DATA_DESCRIPTION_H


#include "Summary.h"
#include "FullDescription.h"
#include <string>

class Description : public sf::Drawable, public sf::Transformable{

private:
    Summary summary;
    FullDescription description;
public:
    Description(std::string summary, std::string description);
    Description();//default constructor
    void setSummary(std::string summary);//can come back and make an overloaded setSummary later
    Summary getSummary();
    void setDescription(std::string description);
    FullDescription getDescription();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};

#endif //STATISTICAL_FINANCIAL_DATA_DESCRIPTION_H
