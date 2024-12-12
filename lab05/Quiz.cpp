//
// Created by Macilaci on 12/14/2023.
//
#include "Quiz.h"
#include <fstream>
#include <sstream>

using namespace std;

Quiz::Quiz(const string& name) : name(name) {}

string Quiz::getName() const {
    return name;
}

const vector<Question>& Quiz::getQuestions() const {
    return questions;
}

bool Quiz::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        if (line[0] == 'Q') {
            string questionText = line.substr(2);
            vector<Answer> answers;
            while (getline(file, line) && line[0] == 'A') {
                answers.emplace_back(line.substr(2), false);
            }
            istringstream iss(line);
            int correctIndex;
            while (iss >> correctIndex) {
                if (correctIndex >= 1 && correctIndex <= answers.size()) {
                    answers[correctIndex - 1] = Answer(answers[correctIndex - 1].getText(), true);
                }
            }
            questions.emplace_back(questionText, answers);
        }
    }
    return true;
}


