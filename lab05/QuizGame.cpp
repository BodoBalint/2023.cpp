//
// Created by Macilaci on 12/14/2023.
//

#include "QuizGame.h"
#include <iostream>

using namespace std;

void QuizGame::startQuiz(const Quiz &quiz) {
    int score = 0;
    for (const auto &question : quiz.questions) {
        cout << question.text << "\n";
        int answerNum = 1;
        for (const auto &answer : question.answers) {
            cout << answerNum << ". " << answer.text << "\n";
            answerNum++;
        }
        int userAnswer;
        cout << "Your answer (enter the number of the correct answer): ";
        cin >> userAnswer;
        if (userAnswer <= question.answers.size() && question.answers[userAnswer - 1].correct) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Incorrect!\n";
        }
    }
    cout << "Quiz ended. Your score: " << score << "/" << quiz.questions.size() << "\n";
}

