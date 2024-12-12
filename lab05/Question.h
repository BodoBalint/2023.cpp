//
// Created by Macilaci on 12/14/2023.
//

#ifndef QUESTION_H
#define QUESTION_H
#include "Answer.h"
#include <vector>
#include <string>

using namespace std;

class Question {
private:
    string text;
    vector<Answer> answers;
public:
    Question(const string& text, const vector<Answer>& answers);
    string getText() const;
    const vector<Answer>& getAnswers() const;
};

#endif
