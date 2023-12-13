//
// Created by Macilaci on 12/13/2023.
//

#ifndef CPP_2022_SETTLEMENT_H
#define CPP_2022_SETTLEMENT_H

#include <string>
#include <iostream>

using namespace std;

class Settlement {
    string name = "";
    string county = "";
    int population = 0;
// constructor, getters, setters, inserter operator
public:
    Settlement(const string &name, const string &county, int population);

    const string &getName() const;

    void setName(const string &name);

    const string &getCounty() const;

    void setCounty(const string &county);

    int getPopulation() const;

    void setPopulation(int population);

    friend ostream &operator<<(ostream &os, const Settlement &settlement);
};



#endif //CPP_2022_SETTLEMENT_H
