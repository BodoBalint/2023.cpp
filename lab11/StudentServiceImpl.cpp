//
// Created by Macilaci on 12/6/2023.
//

#include "StudentServiceImpl.h"

bool StudentServiceImpl::isEnrolled(int id) const {
    try{
        return dao->findById(id).getId()==id;
    }
    catch(exception &e){
        return false;
    }
}

vector<string> StudentServiceImpl::getSubjects(int id) const {
    vector<string> result;
    for (auto &[subject, grade]: dao->findById(id).getGrades()) {
        result.push_back(subject);
    }
    return result;
}

double StudentServiceImpl::getResultBySubject(int id, const string &subject) const {
    return dao->findById(id).getGrade(subject);
}

double StudentServiceImpl::getAverage(int id) const {
    return dao->findById(id).getAverage();
}

bool StudentServiceImpl::isPassed(int id) const {
    return dao->findById(id).getAverage()>=6;
}



