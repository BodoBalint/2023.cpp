//
// Created by Macilaci on 12/14/2023.
//

#ifndef ANSWER_HPP
#define ANSWER_HPP
#include <string>

class Answer {
private:
    std::string text;
    bool correct;
public:
    Answer(const std::string& text, bool correct)
            : text(text), correct(correct) {};
    std::string getText() const {
        return text;
    };
    bool isCorrect() const {
        return correct;
    }
};

#endif

