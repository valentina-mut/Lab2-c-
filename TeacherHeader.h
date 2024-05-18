#pragma once
#include "QuadraticEquation.h"



#ifndef TEACHER_HEADER_H
#define TEACHER_HEADER_H
class Student;

class Teacher {
private:
   
    std::vector<std::pair<std::string, int>>* performanceTable;
    vector<std::pair<double, double>>* answers;

    vector<std::pair<double, double>>* readAnswersFromFile(std::string const& AnswersFileDir);


public:
    std::vector<std::pair<std::string, int>>* verifyStudentsAnswers(vector<Student> stds);
    Teacher(std::string const& EquationsFile, std::string const& AnswersFile, vector<Student> stds)
    {
        answers = readAnswersFromFile(AnswersFile);
        performanceTable = verifyStudentsAnswers(stds);
    }

    
   
    void publishPerformanceTable();

};



#endif // !TEACHER_HEADER_H

