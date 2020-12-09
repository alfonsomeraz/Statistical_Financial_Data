//
// Created by Yu-Chung Chang on 12/3/20.
//

#include "Description.h"

Description::Description(std::string summary, std::string description) : summary(summary), description(description)
{}

void Description::setSummary(std::string summary)
{
    this->summary.setText(summary);
}
Summary Description::getSummary()
{
    return summary;
}
void Description::setDescription(std::string description)
{
    this->description.setText(description);
}
FullDescription Description::getDescription()
{
    return description;
}
void Description::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
//    sf::RectangleShape c;
//    c.setFillColor(at(i));
//    c.setSize({100, 100});
//    c.setPosition({(float)i*x, 200});
//    window.draw(c);
//    x += 110;

    //window.draw(summary);
    //description.setPosition({250, 100});
    window.draw(description);

}

Description::Description(){}
