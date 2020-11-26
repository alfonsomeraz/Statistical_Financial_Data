//
// Created by Dave Smith on 11/25/20.
//

#include "LineChart.h"

LineChart::LineChart(){}
LineChart::LineChart(const ChartData& stock, sf::Vector2i size, int binSize) :
lines(sf::LineStrip, stock.size()), binSize(binSize), size(size)
{
    xAxis.setFillColor(sf::Color::White);
    xAxis.setPosition(0,size.y-binSize);

    yAxis.setFillColor(sf::Color::White);
    yAxis.setPosition(0,0);
    setSize(size);
    setData(stock);
}

void LineChart::setSize(sf::Vector2i size)
{
    yAxis.setSize(sf::Vector2f(binSize, size.y));
    xAxis.setSize(sf::Vector2f(size.x, binSize));

}
void LineChart::setData(const ChartData& stock)
{
    int width = 50;
    int interval = (size.x - binSize) / stock.size();
    for(int i = 0; i < stock.size(); i++)
    {
        lines[i].position = sf::Vector2f(binSize, size.y - (stock.getPoint(i) * 5));
        binSize += interval;
    }
}

void LineChart::setBinSize(int size)
{
    binSize = size;
}

void LineChart::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(lines);
    window.draw(yAxis);
    window.draw(xAxis);
}

