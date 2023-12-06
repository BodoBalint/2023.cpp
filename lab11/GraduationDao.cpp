//
// Created by Macilaci on 12/6/2023.
//
#include "GraduationDao.h"
#include <fstream>
#include <sstream>
#include "Student.h"

void GraduationDao::enrollStudents(const string &filename) {
    ifstream infile(filename);
    if (!infile) {
        throw runtime_error("Unable to open file");
    }
    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        int id;
        string firstName;
        string lastName;
        ss >> id >> firstName >> lastName;
        Student student(id, firstName, lastName);
        students.insert(pair(id, student));
    }
    infile.close();
}

void GraduationDao::saveGradesForSubject(const string &subject, const string &filename) {
    ifstream infile(filename);
    if (!infile) {
        throw runtime_error("Unable to open file");
    }
    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        int id;
        double grade;
        ss >> id >> grade;
        try{
            students.at(id).addGrade(subject, grade);
        }
        catch(exception &e){
            cout << e.what() << endl;
        }
    }
}

void GraduationDao::computeAverage() {
    for (auto &[id,student] : students) {
        student.computeAverage();
    }
}

int GraduationDao::numEnrolled() const {
    return students.size();
}

int GraduationDao::numPassed() const {
    int count = 0;
    for (auto &[id,student] : students) {
        if (student.getAverage()>=6){
            count++;
        }
    }
    return count;
}

Student GraduationDao::findById(int id) const {
    return students.at(id);
}

double GraduationDao::getAverageBySubject(const string &subject) const {
    double sum = 0.0;
    for (auto const &[id,student] : students) {
        sum += student.getGrade(subject);
    }
    return sum / students.size();
}





