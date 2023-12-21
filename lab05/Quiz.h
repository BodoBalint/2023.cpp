//
// Created by Macilaci on 12/14/2023.
//

#ifndef CPP_2022_QUIZ_H
#define CPP_2022_QUIZ_H

#include <vector>
#include <string>
#include "Question.h"

using namespace std;

class Quiz {
public:
    string name;
    vector<Question> questions;
    void readFromFile(const string& filename);
};

#endif // CPP_2022_QUIZ_H
