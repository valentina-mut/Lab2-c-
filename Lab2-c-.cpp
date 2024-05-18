#include "TeacherHeader.h"
#include "StudentHeader.h"


int main() {
    srand(time(0));
    vector <Student> stds = {*new Student("Mutalimova"),*new Student("Bobrov"),*new Student("Malinin"),*new Student("Kruglov")};

    for (auto& std : stds)
        std.Solve_Equations();
    

    Teacher teacher("QuadraticEquations.txt", "Answers.txt", stds);
    teacher.publishPerformanceTable();
    
    return 0;
}
