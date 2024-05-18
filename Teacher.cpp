#include "TeacherHeader.h"
#include "StudentHeader.h"

vector<std::pair<double, double>>* Teacher::readAnswersFromFile(std::string const& AnswersFileDir)
{
    vector<std::pair<double, double>>* ans = new vector<std::pair<double, double>>;
    std::ifstream AnswersFile(AnswersFileDir);

    if (!AnswersFile.is_open()) {
        std::cerr << "Error opening input file\n";
        return nullptr;
    }

    while (!AnswersFile.eof()) {
        std::pair<double, double> solution;
        AnswersFile >> solution.first >> solution.second;
        ans->push_back(solution);
    }
    AnswersFile.close();
    return ans;
}

void Teacher:: publishPerformanceTable() {
    std::cout << "Performance Table:\n";
    for (auto const& entry : *performanceTable) {
        std::cout << "Student: " << entry.first << ", Correct Solutions: " << entry.second << "\n";
    }
}


std::vector<std::pair<std::string, int>>* Teacher::verifyStudentsAnswers(vector<Student> stds) {
    vector<std::pair<std::string, int>>* perfTable = new vector<std::pair<std::string, int>>;
    for (auto const& student : stds) {

        vector<std::pair<double, double>> ::iterator it;
        int CorrectSolutions = 0;

        it = this->answers->begin();
        for (auto ans : *(student._ans))
        {

            if (ans == *it)
                CorrectSolutions++;

            it++;
        }
        perfTable->push_back(std::make_pair(student._name, CorrectSolutions));
    }
    return perfTable;
}

