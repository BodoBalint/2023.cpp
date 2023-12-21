//
// Created by Macilaci on 12/14/2023.
//

#include "Quiz.h"
#include "QuizGame.h"

using namespace std;

int main() {
    Quiz myQuiz;
    myQuiz.name = "My Quiz";
    myQuiz.readFromFile("quiz.txt");
    QuizGame quizGame;
    quizGame.startQuiz(myQuiz);

    return 0;
}