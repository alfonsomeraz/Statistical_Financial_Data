//
// Created by Alfonso Meraz on 11/25/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_CHARTDATA_H
#define STATISTICAL_FINANCIAL_DATA_CHARTDATA_H


class ChartData {

public:
    virtual double getPoint(int index) const = 0;
    virtual int size() const = 0;
};


#endif //STATISTICAL_FINANCIAL_DATA_CHARTDATA_H
