//
// Created by Macilaci on 12/20/2023.
//

#ifndef SIMPLETEXTGENERATOR_H
#define SIMPLETEXTGENERATOR_H

#include "textgenerator.h"
#include <map>
#include <vector>
#include <algorithm>

class SimpleTextGenerator : public TextGenerator {
    map<string, vector<string>> data;
    vector<string> splitWords(const string &text);
    string joinWords(const vector<string> &words, int start, int count);
    string getRandomPostfix(const vector<string> &postfixes);
    string toLowerCase(const string &str);
public:
    virtual void trainFromText(string trainingText) override;
    virtual void trainFromFile(string filename) override;
    virtual string generate(string startWords, int numWords = 6) override;
    void printData() const;
};

#endif // SIMPLETEXTGENERATOR_H
