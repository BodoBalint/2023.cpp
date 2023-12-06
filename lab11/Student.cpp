//
// Created by Macilaci on 12/6/2023.
//
#include "Student.h"

Student::Student(int id, const string &firstName, const string &lastName) {
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
}

int Student::getId() const {
    return id;
}

void Student::setId(int id) {
    this->id = id;
}

const string &Student::getFirstName() const {
    return firstName;
}

const string &Student::getLastName() const {
    return lastName;
}

void Student::addGrade(const string &subject, double grade) {
    grades.insert(pair(subject, grade));
}

double Student::getGrade(const string &subject) const{
    return grades.at(subject);
}

const map<string, double> &Student::getGrades() const {
    return grades;
}

void Student::computeAverage() {
    double sum = 0.0;
    for (const auto [subject, grade] : grades) {
        if (grade<5){
            return;
        }
        sum += grade;
    }
    average = sum / grades.size();
}

double Student::getAverage() const {
    return average;
}

ostream &operator<<(ostream &os, const Student &student) {
    os << student.id << " " << student.firstName << " " << student.lastName << " " << student.average;
    for(const auto [subject, grade] : student.grades){
        os << " " << subject << " " << grade;
    }
    return os;
}





