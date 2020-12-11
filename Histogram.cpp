//
// Created by Yu-Chung Chang on 11/26/20.
//

#include "Histogram.h"

Histogram::Histogram(){
}

Histogram::Histogram(int yearsize) :yearsize(yearsize)
{
    d = new DollarBill*[yearsize]; // allocating memory for the array of DollarBill pointers. d is pointing to an array of pointers.
   data = new int[yearsize];
    std::cout<< std::endl << "2d created" << std::endl;
    texture = new sf::Texture;
    if(!texture->loadFromFile("Dollar.png"))
    {
       // std::cout << "Error could not load dollar image" << std::endl;
        exit(1);
    }
}

void Histogram::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    for(int i =0; i< yearsize; i++)
    {
        for (int j = 0; j < data[i]; j++)  // data[i] is y value
        {
            window.draw(d[i][j]);
//            window.draw(dollar);
        }
    }
}

void Histogram::add(int bin, int y)
{
    data[bin] = y;
}

void Histogram::add(int bin)
{
    data[bin]++;
}

//void Histogram::update()
//{
//    int bot = 1080;
//    for (int i=0; i<10; i++)
//    {
//        d[i] = new DollarBill[data[i]];
//        for(int j = 0; j<data[i]; j++)
//        {
//            d[i][j].setPosition(d[i][j].getGlobalBounds().width*i, bot - d[i][j].getGlobalBounds().height * j / 4);
//        }
//
//    }
//}

void Histogram::update()
{
    int bottom = 1080;

    //d = new DollarBill*[yearsize];
    for (int i=0; i<yearsize; i++)
    {
        d[i] = new DollarBill[data[i]];
        for(int j = 0; j<data[i]; j++)
        {
            d[i][j].setTexture(texture);
//            d[i][j].setPosition(50+d[i][j].getGlobalBounds().width*i, -100+bottom - d[i][j].getGlobalBounds().height * j / 4);
            d[i][j].setPosition(50+d[i][j].getGlobalBounds().width*i, -100+bottom - d[i][j].getGlobalBounds().height * j / 2);
        }

    }
}

Histogram::Histogram(const Histogram& h)  : yearsize(h.yearsize)         //copy ctor
{
    int *data; //y value
    DollarBill **d;// 2d ar
    d = new DollarBill*[yearsize];
    for (int i=0; i<yearsize; i++)
    {
        d[i] = new DollarBill[data[i]];
        for(int j = 0; j<data[i]; j++)
        {
            d[i][j] = h.d[i][j];
        }
    }


}

//Histogram a(3);
//Histogram h = a;          //calls copy ctor (constructing while copying)


//Histogram b(3);
//Histogram c(10);
//b = c                   //calls assignment operator
Histogram& Histogram::operator=(const Histogram& h) //assignment operator
{
    if (&h == this) {
        return *this;
    } else {
        ///////////////////// deallocate //////////////////////////////////////////
        //deallocate data (this.data) and d (this.d) [same code as in destructor below]
        delete[] data;
        for (int i = 0; i < yearsize; i++)
        {
            delete[] d[i];
        }
        delete[] d; //we have to first delete d[i] for each i, then delete d.
                    //If we delete d first, we can not access d[i]

        //////////////////// Assignment //////////////////////////////////////////////
        //assigning [the same code as in copy ctor above]
        int *data; //y value
        DollarBill **d;// 2d ar
        d = new DollarBill *[yearsize];
        for (int i = 0; i < yearsize; i++) {
            d[i] = new DollarBill[data[i]];
            for (int j = 0; j < data[i]; j++) {
                d[i][j] = h.d[i][j];
            }
        }
    }
    return *this;
}

Histogram::~Histogram()
{
    delete[] data;
    for (int i = 0; i < yearsize; i++)
    {
        delete[] d[i];
    }
    delete[] d;

}

//Histogram::SFMLLegendDraw()
//{
//
//}