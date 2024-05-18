#pragma once
#include "QuadraticEquation.h"



#ifndef STUDENT_HEADER_H
#define STUDENT_HEADER_H

class Teacher;

class Student {
private:

    string _type;
    std::vector<QuadraticEquation>* _EquationsTable;
    string _name;
    vector<std::pair<double, double>>* _ans;

    void Set_Type();
    std::vector<QuadraticEquation>* GetEquations(std::string const& EquationsFileDir);
    std::pair<double, double>* Compute(double const a, double const b, double const c);

    static void GetCoefsFromString(double& a, double& b, double& c, string const& equation);
   
    std::pair<double, double>* FindRoots(QuadraticEquation& eq);

public:

    friend std::vector<std::pair<std::string, int>>* Teacher::verifyStudentsAnswers(vector<Student> stds);

    Student(string const& name) {
        
        _ans = new vector<std::pair<double, double>>;
        _name = name;
        Set_Type();
        _EquationsTable = GetEquations("QuadraticEquations.txt");
    }

   
    void Solve_Equations();
    
};

#endif // !STUDENT_HEADER_H



