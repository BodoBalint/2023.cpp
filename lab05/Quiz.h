//
// Created by Macilaci on 12/14/2023.
//

#ifndef QUIZ_H
#define QUIZ_H
#include "Question.h"
#include <vector>
#include <string>

using namespace std;

class Quiz {
private:
    string name;
    vector<Question> questions;
public:
    Quiz(const string& name);
    string getName() const;
    const vector<Question>& getQuestions() const;
    bool loadFromFile(const std::string& filename);
};

#endif

