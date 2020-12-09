//
// Created by Yu-Chung Chang on 12/3/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_REPORTDAY_H
#define STATISTICAL_FINANCIAL_DATA_REPORTDAY_H



#include "Date.h"
#include "Title.h"
#include "Description.h"
#include "Image.h"
#include"Colors.h"

//#include <SFML/Graphics.hpp>

class ReportDay : public Date{


public:
    ReportDay();
    void setOccasion(std::string occasion);
//    std::string getOccasion();
    void setOccasion(Title occasion);
    Title getOccasion();

    void setSummary(std::string summary);
    Summary getSummary();

    std::string getDescription();
    void setDescription(std::string description);
//    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void setImage(std::string filepath) ;
    void setImageScale(float x, float y);
    void addColor(sf::Color color);


protected:
    Title occasion;
    Description description;
    Image image;
    Colors colors;

//    sf::Text text;
//    sf::Font font;
//



};



#endif //STATISTICAL_FINANCIAL_DATA_REPORTDAY_H
