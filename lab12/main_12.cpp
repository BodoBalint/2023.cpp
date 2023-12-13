#include <iostream>
#include "SettlementStatisticsImpl.h"

int main() {
    SettlementStatistics *stats = new SettlementStatisticsImpl("telepulesek.csv");
    vector<Settlement> megyek = stats->findSettlementsByCounty("AB");
    for (int i = 0; i < megyek.size(); i++) {
        cout << megyek[i].getName() << endl;
    }
    cout << "size :" << megyek.size() << endl;

    int num = stats->numSettlements();
    cout << "num :" << num << endl;

    int counties = stats->numCounties();
    cout << "counties :" << counties << endl;

    int settlementsByCounty = stats->numSettlementsByCounty("AB");
    cout << "settlementsByCounty :" << settlementsByCounty << endl;

    Settlement maxPopulation = stats->maxPopulation();
    Settlement minPopulation = stats->minPopulation();

    cout << "maxPopulation :" << maxPopulation.getName() << endl;
    cout << "minPopulation :" << minPopulation.getName() << endl;

    vector<Settlement> varosnevek = stats->findSettlementsByName("Slobozia");
    for (int i = 0; i < varosnevek.size(); i++) {
        cout << varosnevek[i].getName() << endl;
    }
    cout << "size :" << varosnevek.size() << endl;


    delete stats;
    return 0;
}