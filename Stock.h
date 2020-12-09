//
// Created by Alfonso Meraz on 11/19/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_STOCK_H
#define STATISTICAL_FINANCIAL_DATA_STOCK_H
#include <string>
#include "PriceHistoryOneMonth.h"
#include "PriceHistoryYTD.h"
#include "PriceHistoryTwoYears.h"
#include "Quotes.h"
#include "LineChart.h"

class Stock : public sf::Drawable, public sf::Transformable, public Quotes{
public:
    Stock();
    Stock(std::string ticker);
    std::string getYTDReturnsString();
    std::string getMonthReturnsString();
    std::string getYearReturnsString();
    double getYTDReturns();
    double getMonthReturns();
    double getYearReturns();
    friend bool operator==(const Stock& first, const Stock& second);
    friend bool operator!=(const Stock& first, const Stock& second);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
private:
    void setChart();
    void setReturnStrings();
    sf::Text ytdReturns, monthReturns, yearReturns;
    sf::Font font;
    sf::Vector2i window = {1920,1080};
    PriceHistoryOneMonth stockMonth;
    PriceHistoryYTD stockYTD;
    PriceHistoryTwoYears stockYears;
    LineChart chart;
    Quotes stockQuote;
    std::string stockTicker;
};


#endif //STATISTICAL_FINANCIAL_DATA_STOCK_H
