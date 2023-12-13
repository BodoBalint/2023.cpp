//
// Created by Macilaci on 12/13/2023.
//

#ifndef CPP_2022_SETTLEMENTSTATISTICS_H
#define CPP_2022_SETTLEMENTSTATISTICS_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "Settlement.h"


using namespace std;

struct SettlementStatistics {
    virtual int numSettlements() const = 0;

    virtual int numCounties() const = 0;

    virtual int numSettlementsByCounty(const string &county) const = 0;

    virtual vector <Settlement> findSettlementsByCounty(
            const string &county) const = 0;

    virtual Settlement findSettlementsByNameAndCounty(
            const string &name, const string &county) const = 0;

    virtual Settlement maxPopulation() const = 0;

    virtual Settlement minPopulation() const = 0;

    virtual vector <Settlement> findSettlementsByName(
            const string &name) = 0;
};


#endif //CPP_2022_SETTLEMENTSTATISTICS_H
