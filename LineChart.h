//
// Created by Dave Smith on 11/25/20.
//

#ifndef MA_CHART_CHART_H
#define MA_CHART_CHART_H
#include <SFML/Graphics.hpp>
#include "PriceHistory.h"
class LineChart : public sf::Drawable, public sf::Transformable{

private:
    sf::RectangleShape yAxis, xAxis;
    sf::VertexArray lines;
    sf::Vector2i size;
    int binSize;
public:
    void setSize(sf::Vector2i size);
    void setData(const ChartData& data);
    void setBinSize(int size);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    LineChart(const ChartData& stock, sf::Vector2i size, int binSize);
    LineChart();
};


#endif //MA_CHART_CHART_H

