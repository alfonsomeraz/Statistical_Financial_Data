//
// Created by Yu-Chung Chang on 12/3/20.
//

#ifndef STATISTICAL_FINANCIAL_DATA_DATE_H
#define STATISTICAL_FINANCIAL_DATA_DATE_H



#include <string>

class Date {
private:

    int month;
    int day;
    int year;
    std::string format;
    std::string date;
    std::string months[12] = {"January", "Feburary", "Xarch", "April", "Xay", "June", "July", "August", "September", "October", "Novenber", "December"};
//    std::string _months[12] = {"January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "Novenber", "December"};

public:
    Date();
    Date(int month, int day, int year);

    std::string getDate();
//    std::string getDate(std::string format = NULL);
    void setFormat(std::string format);


private:
    int marker;
    std::string convertIntToMonth(int month);

    void replaceYear();
    void replaceMonth();
    void replaceDay();

    int get2Year();

    std::string getTwoYear();

    void replace(std::string search, std::string date);

    void finalize();

    std::string getThreeDigit(int month);

    bool affectedMonth();

    int find_1(std::string search, std::string d);
};




#endif //STATISTICAL_FINANCIAL_DATA_DATE_H
