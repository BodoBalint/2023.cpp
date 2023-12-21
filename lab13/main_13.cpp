#include <iostream>
#include "SimpleTextGenerator.h"

using namespace std;

int main() {
    TextGenerator *generator = new SimpleTextGenerator();
    //SimpleTextGenerator generator;
    //generator.trainFromText("Now is not the time for sleep, now is the time for party!");
    generator->trainFromFile("bible.txt");
    //generator.trainFromFile("bible.txt");
    //generator.printData();
    for (int i = 0; i < 10; ++i) {
        // cout << generator.generate("god said") << endl;
        cout << generator->generate("god said") << endl;
    }
    return 0;
}