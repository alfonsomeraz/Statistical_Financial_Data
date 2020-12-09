//
// Created by Yu-Chung Chang on 12/3/20.
//

#include "SFMLdraw.h"


SFMLdraw::SFMLdraw()
{
    //setOccasion("This is the occasion");
    setOccasion("Annual Financial Portfolio Report");
    if (!font.loadFromFile("Open-Sans-Bold.ttf"))
        exit(1);
    occasion.setFont(font);
    occasion.setPosition({250, 200});
    occasion.setString(getOccasion().getText());
    occasion.setFillColor(sf::Color(255, 165, 0));
    occasion.setCharacterSize(90);

    setSummary("Alfonso Morez\n& Yu-Chung Chang-Hou\n"
               "Course:CS 3A\n"
               "CRN: 77058\n"
               "Fall 2020");

//    setDescription("Respond to rapidly evolving markets with a global approach.\n"
//                   "    Domestic: \n"
//                   "    International: \n"
//                   "    Challenges: \n"
//                   "    Strategy:");

    setDescription("Statistical Financial Data\n");



    description.setFont(font);
    summary.setFont(font);
    summary.setString(getSummary().getText());
    summary.setPosition({900, 400});
    summary.setFillColor(sf::Color::Green);
    summary.setCharacterSize(60);

    description.setString(getDescription());
    description.setPosition({900, 850});
    description.setFillColor(sf::Color::White);
    description.setCharacterSize(50);


    setImage("StockImage.png");

//    sf::Image image;
//    if (!(image.loadFromFile("Happy_Thanksgiving_Decoration_PNG_Clipart_Image.png")))
//        exit(9);
//
//    sf::Texture texture;
//    texture.loadFromImage(image);
//
//    sf::Sprite sprite;
//    sprite.setTexture(texture);

    image.setScale(0.9, 0.9);
//    image.setString(getSummary().getText());
    image.setPosition(150, 150);
//    image.setFillColor(sf::Color::White);
//    image.setCharacterSize(48);


//    sf::RectangleShape square;



}

void SFMLdraw::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(image);
    window.draw(occasion);
    window.draw(description);
    window.draw(summary);
    //  window.draw(square);

}

