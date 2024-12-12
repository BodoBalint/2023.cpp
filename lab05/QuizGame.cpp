//
// Created by Macilaci on 12/14/2023.
//

#include "QuizGame.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

QuizGame::QuizGame(const Quiz& quiz) : quiz(quiz) {}

void QuizGame::run() const {
    cout << "Udvozlunk a \"" << quiz.getName() << "\" kvizben!\n";
    int score = 0;
    for (const auto& question : quiz.getQuestions()) {
        cout << question.getText() << "\n";
        const auto& answers = question.getAnswers();
        for (size_t i = 0; i < answers.size(); ++i) {
            cout << i + 1 << ". " << answers[i].getText() << "\n";
        }
        cout << "Ird be a helyes valasz(ok) szamat, szokozzel elvalasztva: ";
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> userAnswers;
        int num;
        while (iss >> num) {
            userAnswers.push_back(num - 1);
        }
        for (size_t i = 0; i < answers.size(); ++i) {
            if (answers[i].isCorrect() && find(userAnswers.begin(), userAnswers.end(), i) != userAnswers.end()) {
                score++;
            }
        }
    }
    cout << "A pontszamod: " << score << " / " << quiz.getQuestions().size() << "\n";
}

