//
// Created by Alfonso Meraz on 11/19/20.
//

#include "Stock.h"

Stock::Stock() : Stock("AAPL") {
//    setChart();
    setReturnStrings();
}

Stock::Stock(std::string ticker) : Quotes(ticker), stockTicker(ticker) {

}

std::string Stock::getYTDReturnsString() {
    return std::to_string(stockYTD.getReturns());
}

std::string Stock::getMonthReturnsString() {
    return std::to_string(stockMonth.getReturns());
}

std::string Stock::getYearReturnsString() {
    return std::to_string(stockYears.getReturns());
}

bool operator==(const Stock& first, const Stock& second)
{
    return (first.stockTicker == second.stockTicker);
}

bool operator!=(const Stock& first, const Stock& second)
{
    return (first.stockTicker != second.stockTicker);
}

void Stock::draw(sf::RenderTarget &window, sf::RenderStates states) const {
//    window.draw(chart);
    window.draw(ytdReturns);
    window.draw(monthReturns);
    window.draw(yearReturns);
}

void Stock::setChart() {
    chart.setSize(window);
    chart.setData(stockYTD);
}

void Stock::setReturnStrings() {
    font.loadFromFile("OpenSans-Bold.ttf");
    ytdReturns.setFont(font);
    monthReturns.setFont(font);
    yearReturns.setFont(font);
    ytdReturns.setString("Year To Date Returns: " + getYTDReturnsString());
    monthReturns.setString("Month Returns: " + getMonthReturnsString());
    yearReturns.setString("Two Years Returns: " + getYearReturnsString());
    ytdReturns.setFillColor(sf::Color::White);
    monthReturns.setFillColor(sf::Color::White);
    yearReturns.setFillColor(sf::Color::White);
    ytdReturns.setPosition(1400,180);
    monthReturns.setPosition(1400,220);
    yearReturns.setPosition(1400,260);
}

double Stock::getYTDReturns() {
    return stockYTD.getReturns();
}

double Stock::getMonthReturns() {
    return stockMonth.getReturns();
}

double Stock::getYearReturns() {
    return stockYears.getReturns();
}
