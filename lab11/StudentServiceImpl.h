//
// Created by Macilaci on 12/6/2023.
//

#ifndef CPP_2022_STUDENTSERVICEIMPL_H
#define CPP_2022_STUDENTSERVICEIMPL_H
#include "StudentService.h"
#include "GraduationDao.h"

class StudentServiceImpl : public StudentService{
    GraduationDao *dao;
public:
    explicit StudentServiceImpl(GraduationDao *dao) : dao(dao) {}
    virtual bool isEnrolled(int id) const override;
    vector<string> getSubjects(int id) const override;
    double getResultBySubject(int id, const string& subject) const override;
    double getAverage(int id) const override;
    bool isPassed(int id) const override;
};
#endif //CPP_2022_STUDENTSERVICEIMPL_H
