//
// Created by Yu-Chung Chang on 12/3/20.
//

#include "ReportDay.h"
//ReportDay::ReportDay(): image("Happy_Thanksgiving_Decoration_PNG_Clipart_Image.png"){}
ReportDay::ReportDay(): image("StockImage.png"){}
void ReportDay::setOccasion(std::string occasion)
{
    this->occasion.setText(occasion);

}
void ReportDay::setOccasion(Title occasion)
{
    this->occasion = occasion;
//    if (!font.loadFromFile("OpenSans-Bold-1.ttf"))
//        exit(1);
//    text.setFont(font);
//    text.setString(occasion.getText());
//    text.setFillColor(sf::Color::Yellow);
//    text.setCharacterSize(96);
}
//std::string ReportDay::getOccasion()
//{
//    return occasion.getText();
//}
Title ReportDay::getOccasion()
{
    return occasion;
}
void ReportDay::setSummary(std::string summary)
{
    this->description.setSummary(summary);
}
Summary ReportDay::getSummary()
{
    return this->description.getSummary();
}
void ReportDay::setDescription(std::string description)
{
    this->description.setDescription(description);
}

//void ReportDay::draw(sf::RenderTarget& window, sf::RenderTarget states) const
//{
//    window.draw(text);
////   window.draw(occasion);
////   window.draw(description);
////   window.draw(image);
////   window.draw(colors);
//}

//void ReportDay::draw(sf::RenderTarget& , sf::RenderTarget ) const
//{}

void ReportDay::setImage(std::string filepath)
{
    image.setFilepath(filepath);//need to re-apply this image to my texture,
    // re-apply my texture to rectangular shape
    image.setTexture();
}
void ReportDay::addColor(sf::Color color)
{
    colors.push_back(color);
}

void ReportDay::setImageScale(float x, float y) {
    image.setScale(x,y);
}

std::string ReportDay::getDescription() {
    return description.getDescription().getText();
}

//void ReportDay::draw(sf::RenderTarget &window, sf::RenderStates states) const {
//    window.draw(text);
//}
