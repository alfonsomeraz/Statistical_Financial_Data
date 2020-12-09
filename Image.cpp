//
// Created by Yu-Chung Chang on 12/3/20.
//

#include "Image.h"

void Image::setFilepath(std::string filepath)
{
    setText(filepath);
//    this -> filepath = filepath;
    setTexture();
    sprite.setTexture(texture);
}

std::string Image::getFilepath()
{
    return getText();
}

Image::Image(std::string filepath) : Title(filepath)
{
    setTexture();
    sprite.setTexture(texture);
}
Image::Image() : Title()
{

}

void Image::setSprite()
{
    sprite.setTexture(texture);
}

void Image::setTexture(){


    if(!texture.loadFromFile(Title::getText()))
        exit(1);
}

void Image::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(sprite);
}

void Image::setScale(float x, float y)
{
    sprite.setScale(x,y);
}
void Image::setPosition(float x, float y)
{
    sprite.setPosition({x,y});
}