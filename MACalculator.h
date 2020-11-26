//
// Created by Alfonso Meraz on 11/17/20.
//

#ifndef EQUITIES_MACALCULATOR_H
#define EQUITIES_MACALCULATOR_H
#include <vector>
#include <iostream>

class MACalculator {
public:
    MACalculator(int period);
    MACalculator(const MACalculator &);
    MACalculator &operator = (const MACalculator &);
    ~MACalculator();
    void addPriceQuote(double close);
    std::vector<double>* calculateMA();
    std::vector<double> calculateEMA();
private:
    // number of periods used in the calculation
    int m_numPeriods;
    std::vector<double> m_prices;
};


#endif //EQUITIES_MACALCULATOR_H
