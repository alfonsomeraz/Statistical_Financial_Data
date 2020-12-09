//
// Created by Yu-Chung Chang on 12/1/20.
//

#include "TTest.h"
#include <cmath>


double TTest::mean(const ChartData& stock)
{
//    int interval = (size.x - binSize) / stock.size();
    double sum = 0;
    for(int i = 0; i < stock.size(); i++)
    {
        sum += stock.getPoint(i);
    }
    return sum / stock.size();
}

double TTest::std(const ChartData& stock, double mean)
{
//    int interval = (size.x - binSize) / stock.size();
    double sum = 0;
    for(int i = 0; i < stock.size(); i++)
    {
        sum += pow((stock.getPoint(i) - mean), 2 );
    }
    return sqrt(sum / stock.size());
}

double TTest::stdSampleMean(const ChartData& stock,double std)
{
    return std / sqrt(stock.size());
}


double TTest::stat(double sampleMean, double mean, double stdSampleMean)
{
    return (sampleMean - mean) / stdSampleMean;
}

double TTest::critVal(const ChartData& stock, double sigLevel)
{
    double cTwo10[40]={6.314, 2.920, 2.353, 2.132, 2.015, 1.943, 1.895, 1.860, 1.833,1.812,
                       1.796, 1.782, 1.771, 1.761, 1.753, 1.746, 1.740, 1.734, 1.729, 1.725,
                       1.721, 1.717, 1.714, 1.711, 1.708, 1.706, 1.703, 1.701, 1.699, 1.697,
                       1.696, 1.694, 1.691, 1.688, 1.686, 1.684, 1.679, 1.676, 1.673, 1.671,};
    double cTwo05[40]={2.064};
    if(sigLevel == 0.10)
    {
        return cTwo10[stock.size()-1-1];
    }
    else if (sigLevel == 0.05)
    {
        return cTwo05[1];
    } else{

    }
}


double TTest::pVal()
{

}