//
// Created by Macilaci on 12/14/2023.
//
#include "Quiz.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void Quiz::readFromFile(const std::string &filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Could not open file" << endl;
        }
        string line;
        while (getline(file, line)) {
            Question q;
            stringstream ss(line);
            string azonosito, valasz;
            getline(ss, azonosito, ' ');
            getline(ss, valasz);
            if (azonosito == "Q") {
                q.text = valasz;
                for (int i = 1; i < 5; ++i) {
                    Answer a;
                    getline(ss, azonosito, ' ');
                    getline(ss, valasz);
                    a.text = valasz;
                    a.correct = true;
                    q.answers.push_back(a);
                }
            }
            getline(ss, azonosito, ' ');
            getline(ss, valasz);
        }
        file.close();
    }

