//
// Created by Macilaci on 12/13/2023.
//

#ifndef CPP_2022_SETTLEMENTSTATISTICSIMPL_H
#define CPP_2022_SETTLEMENTSTATISTICSIMPL_H

#include <vector>
#include "SettlementStatistics.h"
#include "Settlement.h"
#include <string>
#include <iostream>
#include <map>
#include <fstream>


using namespace std;

class SettlementStatisticsImpl : public SettlementStatistics
        {
        private:
            multimap<string, Settlement> settlements;
public:
    SettlementStatisticsImpl(const string& fileName);

    int numSettlements() const override;

    int numCounties() const override;

    int numSettlementsByCounty(const string &county) const override;

    vector <Settlement> findSettlementsByCounty(const string &county) const override;

    Settlement findSettlementsByNameAndCounty(const string &name, const string &county) const override;

    Settlement maxPopulation() const override;

    Settlement minPopulation() const override;

    vector <Settlement> findSettlementsByName(const string &name) override;

};


#endif //CPP_2022_SETTLEMENTSTATISTICSIMPL_H
