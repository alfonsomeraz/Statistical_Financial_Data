//
// Created by Yu-Chung Chang on 12/3/20.
//

#include <iostream>
#include "Date.h"

Date::Date() {}

Date::Date(int month, int day, int year):month(month), day(day), year(year)
{

}



std::string Date::getDate()
{
    const bool debug = true;

    date = format;
    replaceYear();
    replaceMonth();
    replaceDay();
    replace("Xar", "Mar");
    //replace("Xarch","March");
    replace("Xay", "May");

    return date;

}

void Date::setFormat(std::string format)
{
    this->format = format;
}

void Date::replaceYear()
{
    replace("YY", std::to_string(year));
    replace("Y", std::to_string(get2Year()));
}

void Date::replaceMonth()
{
    replace("m", std::to_string(month));
    replace("MM", months[month-1]);
    replace("M", getThreeDigit(month));

}

void Date::replaceDay()
{
    replace("d", std::to_string(day));

}

void Date::replace(std::string search, std::string d)
{
    int index = date.find(search);//look for the substring
    const bool debug = true;
    if (debug)
        std::cout << "index = " << index << std::endl;
    while (index !=std::string::npos) // it found the substring! npos = max value for integers
    {
//        if(index != std::string::npos)
//        {
//            date.replace(index, search.size(), d);
//        }
        date.replace(index, search.size(), d);
        index = date.find(search);
    }
}

std::string Date::getThreeDigit(int month)
{
    std::string month_name[12] = {"Jan", "Feb", "Xar", "Apr","Xay", "Jun",
                                  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    return month_name[month-1];

}

int Date::get2Year()
{
    if (year>=2000)
        return year-2000;
    else
        return year-1900;
}
