//
// Created by Macilaci on 12/14/2023.
//
#include "Question.h"
using namespace std;

Question::Question(const string& text, const vector<Answer>& answers) : text(text), answers(answers) {};

string Question::getText() const {
    return text;
}

const vector<Answer>& Question::getAnswers() const {
    return answers;
}
