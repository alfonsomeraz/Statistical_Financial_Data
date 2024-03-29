//
// Created by Alfonso Meraz on 11/13/20.
//

#ifndef EQUITIES_FUNDAMENTALSCALC_H
#define EQUITIES_FUNDAMENTALSCALC_H
#include <string>

class FundamentalsCalculator {
public:
    FundamentalsCalculator(const std::string &ticker, double price, double dividend);
    ~FundamentalsCalculator();
    FundamentalsCalculator(const FundamentalsCalculator &);
    FundamentalsCalculator &operator=(const FundamentalsCalculator&);
    void setNumOfShares(int n);
    void setEarnings(double val);
    void setExpectedEarnings(double val);
    void setBookValue(double val);
    void setAssets(double val);
    void setLiabilitiesAndIntangibles(double val);
    void setEpsGrowth(double val);
    void setNetIncome(double val);
    void setShareHoldersEquity(double val);
    double PE();
    double forwardPE();
    double bookValue();
    double priceToBookRatio();
    double priceEarningsToGrowth();
    double returnOnEquity();
    double getDividend();
private:
    std::string m_ticker;
    double m_price;
    double m_dividend;
    double m_earningsEstimate;
    int m_numShares;
    double m_earnings;
    double m_bookValue;
    double m_assets;
    double m_liabilitiesAndIntangibles;
    double m_epsGrowth;
    double m_netIncome;
    double m_shareholdersEquity;
};


#endif //EQUITIES_FUNDAMENTALSCALC_H
