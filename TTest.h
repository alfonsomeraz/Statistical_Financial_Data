//
// Created by Yu-Chung Chang on 12/1/20.
//
// receive 24 months mean earnings
// use t test
//

#ifndef STATISTICAL_FINANCIAL_DATA_TTEST_H
#define STATISTICAL_FINANCIAL_DATA_TTEST_H

#include <SFML/Graphics.hpp>
#include "PriceHistoryTwoYears.h"

class TTest : public sf::Drawable, public sf::Transformable{

private:



public:
    double mean(const ChartData& stock);
    double std(const ChartData& stock, double mean);
    double stdSampleMean(const ChartData& stock,double std);
    double stat(double sampleMean, double mean, double stdSampleMean);

    double critVal(const ChartData& stock, double sigLevel);
    double stdSampleMean(double std);
    double pVal();

    void setSize(sf::Vector2i size);
    void setData(const ChartData& data);
    void setBinSize(int size); //pixel
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
//    LineChart(const ChartData& stock, sf::Vector2i size, int binSize);
//    LineChart();
};



#endif //STATISTICAL_FINANCIAL_DATA_TTEST_H
