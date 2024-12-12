//
// Created by Macilaci on 12/14/2023.
//
#include "Quiz.h"
#include "QuizGame.h"
#include <iostream>

using namespace std;

int main() {
    Quiz quiz("Programozasi alapismeretek kviz");
    if (!quiz.loadFromFile("quiz.txt")) {
        cout << "Nem sikerult betolteni a kvizt." << endl;
        return 1;
    }
    QuizGame game(quiz);
    game.run();
    return 0;
}
