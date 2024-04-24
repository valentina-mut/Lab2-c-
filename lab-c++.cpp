#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct QuadraticEquation {
    std::string equation;
    double solution;
    std::string studentName;
};

class Teacher {
private:
    std::vector<QuadraticEquation> queue;
    std::vector<std::pair<std::string, int>> performanceTable;

public:
    void addToQueue(const QuadraticEquation& equation) {
        queue.push_back(equation);
    }

    void verifyQueue() {
        for (const QuadraticEquation& eq : queue) {
            bool isCorrect = false;
            if (eq.solution == 0) {
                isCorrect = true;
            }
            if (isCorrect) {
                for (auto& entry : performanceTable) {
                    if (entry.first == eq.studentName) {
                        entry.second++;
                        isCorrect = false;
                        break;
                    }
                }
                if (isCorrect) {
                    performanceTable.push_back(std::make_pair(eq.studentName, 1));
                }
            }
        }
        queue.clear();
    }

    void publishPerformanceTable() {
        std::cout << "Performance Table:\n";
        for (const auto& entry : performanceTable) {
            std::cout << "Student: " << entry.first << ", Correct Solutions: " << entry.second << "\n";
        }
    }
};

void readEquationsFromFile(const std::string& filename, Teacher& teacher) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening input file\n";
        return;
    }

    QuadraticEquation eq;
    while (file >> eq.equation >> eq.solution >> eq.studentName) {
        teacher.addToQueue(eq);
    }

    file.close();
}

int main() {
    Teacher teacher;
    readEquationsFromFile("input.txt", teacher);

    teacher.verifyQueue();
    teacher.publishPerformanceTable();
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cmath>

    using namespace std;

    class Student {
    private:
        string name;
        char mark;
        vector<double> ans;

    public:
        Student(const string& _name, const int number) {
            name = _name;
            Get_Mark();
            Get_ans(number);
        }

        void Get_Mark() {
            srand(time(0));
            int score = rand() % 3 + 3;
            if (score == 3)
                mark = 'C';
            else if (score == 4)
                mark = 'B';
            else
                mark = 'A';
        }

        void Get_ans(const int number) {
            ans.resize(2);
            if (mark == 'A') {
                FindRoots(number);
            }
            else if (mark == 'C') {
                ans[0] = 0.0;
                ans.resize(1);
            }
            else if (mark == 'B') {
                int chance = rand() % 20 + 1;
                if (chance <= 11)
                    FindRoots(number);
                else
                    ans[0] = 0.0;
            }
        }

        void InputData(double& a, double& b, double& c, const int number) {
            ifstream file("input.txt");
            string s;
            for (int i = 1; i < number; i++) {
                getline(file, s);
            }
            file >> a >> b >> c;
        }

        void Roots(const double a, const double b, const double c, double& x1, double& x2) {
            double D = b * b - 4 * a * c;
            if (D < 0) {
                x1 = x2 = NULL;
            }
            else {
                x1 = (-b + sqrt(D)) / (2 * a);
                x2 = (-b - sqrt(D)) / (2 * a);
            }
        }

        void FindRoots(const int number) {
            double a, b, c;
            InputData(a, b, c, number);
            double x1, x2;
            Roots(a, b, c, x1, x2);
            ans[0] = x1;
            ans[1] = x2;
        }

        void PrintResult(const int number) {
            cout << "Number: " << number << endl;
            cout << "Name: " << name << endl;
            if (ans[0] == NULL) {
                cout << "There are no roots." << endl;
            }
            else {
                for (int i = 0; i < ans.size(); i++) {
                    cout << "Root " << i + 1 << ": " << ans[i] << endl;
                }
            }
        }
    };

    int main();
    {
        char another_attempt;
        do {
            string name;
            int number;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter assignment's number: ";
            cin >> number;
            Student* a = new Student(name, number);
            a->PrintResult(number);
            cout << "Do you want to try another student/number? (y/n): ";
            cin >> another_attempt;
        } while (another_attempt == 'y');

        return 0;
    }

    return 0;
}
