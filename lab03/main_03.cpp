//
// Created by Macilaci on 12/21/2023.
//

#include <iostream>
#include "List.h"

using namespace std;

int main() {
    List myList;
    myList.insertFirst(3);
    myList.insertFirst(7);
    myList.insertFirst(5);
    myList.insertFirst(1);
    cout << "Lista elemei: ";
    myList.print();
    cout << "Lista merete: " << myList.size() << endl;
    cout << "Ures a lista? " << (myList.empty() ? "Igen" : "Nem") << endl;
    int valueToFind = 7;
    cout << "Ez az ertek  " << valueToFind << " benne van a listaban? " << (myList.exists(valueToFind) ? "Igen" : "Nem") << endl;
    int removedValue = myList.removeFirst();
    cout << "Torolt elem: " << removedValue << endl;
    cout << "A lista torles utan: ";
    myList.print();
    myList.remove(5, List::DeleteFlag::EQUAL);
    cout << "A lista miutan lett torolve az 5 belole (EQUAL-al): ";
    myList.print();
    return 0;
}
