//
// Created by Macilaci on 12/14/2023.
//
#include <string>
#include <vector>
#include "Question.h"

using namespace std;


void addAnswer(const std::string& answerText, bool isCorrect) {
    Answer answer;
    answer.text = answerText;
    answer.correct = isCorrect;
}