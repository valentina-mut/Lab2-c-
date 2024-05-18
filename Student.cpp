#include "TeacherHeader.h"
#include "StudentHeader.h"
#include "sstream"

void Student::Set_Type() {
    
    int score = rand() % 3 + 3;
    if (score == 3)
        _type = "Good";
    else if (score == 4)
        _type = "Average";
    else
        _type = "Bad";
}

std::vector<QuadraticEquation>* Student::GetEquations(std::string const& EquationsFileDir)
{
    std::ifstream EquationsFile(EquationsFileDir);
    vector<QuadraticEquation>* eqs = new vector<QuadraticEquation>;

    if (!EquationsFile.is_open()) {
        std::cerr << "Error opening input file\n";
        return nullptr;
    }

    QuadraticEquation eq;
    while (!EquationsFile.eof()) {
        QuadraticEquation eq;
        string equation;
        getline(EquationsFile, equation);
        eq.equation = equation;
        eqs->push_back(eq);
    }

    EquationsFile.close();
    return eqs;
}

std::pair<double, double>* Student::Compute(double const a, double const b, double const c) {
    double D = b * b - 4 * a * c;
    double x1, x2;
    if (D < 0) {
        x1 = x2 = NULL;
    }
    else {
        x1 = (-b - sqrt(D)) / (2 * a);
        x2 = (-b + sqrt(D)) / (2 * a);
    }
    return new std::pair<double, double>(x1, x2);
}

void Student:: GetCoefsFromString(double& a, double& b, double& c, string const& equation)
{
    std::istringstream is(equation);
    is >> a;
    is >> b;
    is >> c;
}

std::pair<double, double>* Student::FindRoots(QuadraticEquation& eq) {

    double a, b, c;
    GetCoefsFromString(a, b, c, eq.equation);
    return Compute(a, b, c);
}

void Student:: Solve_Equations() {
    for (auto& Equation : *_EquationsTable) {
        if (_type == "Good") {
            _ans->push_back(*FindRoots(Equation));
        }
        else if (_type == "Bad") {
            _ans->push_back(std::make_pair(0, 0));
        }
        else if (_type == "Average") {
            int chance = rand() % 20 + 1;
            if (chance <= 11)
                _ans->push_back(*FindRoots(Equation));
            else
                _ans->push_back(std::make_pair(0, 0));
        }
    }
}