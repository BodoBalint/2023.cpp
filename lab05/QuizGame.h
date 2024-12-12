//
// Created by Macilaci on 12/14/2023.
//

#ifndef QUIZGAME_H
#define QUIZGAME_H
#include "Quiz.h"

class QuizGame {
private:
    const Quiz& quiz;
public:
    QuizGame(const Quiz& quiz);
    void run() const;
};

#endif

