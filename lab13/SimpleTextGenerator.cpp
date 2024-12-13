//
// Created by Macilaci on 12/20/2023.
//

#include "simpletextgenerator.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <random>

using namespace std;

vector<string> SimpleTextGenerator::splitWords(const string &text) {
    istringstream stream(text);
    vector<string> words;

    string word;
    while (stream >> word) {
        // Remove punctuation and convert to lowercase
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
        words.push_back(toLowerCase(word));
    }

    return words;
}

string SimpleTextGenerator::joinWords(const vector<string> &words, int start, int count) {
    ostringstream result;
    for (int i = 0; i < count; ++i) {
        if (i > 0) result << " ";
        result << words[start + i];
    }
    return result.str();
}

string SimpleTextGenerator::getRandomPostfix(const vector<string> &postfixes) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, postfixes.size() - 1);
    return postfixes[dist(gen)];
}

string SimpleTextGenerator::toLowerCase(const string &str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

void SimpleTextGenerator::trainFromText(string trainingText) {
    vector<string> words = splitWords(trainingText);
    if (words.size() < 2) return;

    for (size_t i = 0; i < words.size() - 2; ++i) {
        string prefix = joinWords(words, i, 2);
        string postfix = words[i + 2];
        auto &postfixList = data[prefix];
        if (find(postfixList.begin(), postfixList.end(), postfix) == postfixList.end()) {
            postfixList.push_back(postfix);
        }
    }
    for (size_t i = 0; i < words.size() - 1; ++i) {
        string prefix = joinWords(words, i, 2);
        if (data.find(prefix) == data.end()) {
            data[prefix] = {};
        }
    }
}

void SimpleTextGenerator::trainFromFile(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }
    stringstream buffer;
    buffer << file.rdbuf();
    trainFromText(buffer.str());
}

string SimpleTextGenerator::generate(string startWords, int numWords) {
    vector<string> result = splitWords(startWords);
    if (result.size() < 2) return startWords;

    string prefix = joinWords(result, result.size() - 2, 2);
    prefix = toLowerCase(prefix);

    for (int i = 0; i < numWords; ++i) {
        if (data.find(prefix) == data.end() || data[prefix].empty()) {
            break;
        }

        const vector<string> &postfixes = data[prefix];
        string nextWord = getRandomPostfix(postfixes);
        result.push_back(nextWord);

        prefix = joinWords(result, result.size() - 2, 2);
        prefix = toLowerCase(prefix);
    }

    return joinWords(result, 0, result.size());
}

void SimpleTextGenerator::printData() const {
    for (const auto &entry : data) {
        cout << "Prefix: " << entry.first << " -> Postfixes: ";
        if (entry.second.empty()) {
            cout << "(none)";
        } else {
            for (const string &postfix : entry.second) {
                cout << postfix << " ";
            }
        }
        cout << endl;
    }
}