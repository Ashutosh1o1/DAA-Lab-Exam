#include <iostream>
#include <string>

// Class responsible for handling student grades
class Grade
{
public:
    std::string grade;
    Grade(std::string g) : grade(g) {}
};

// Class responsible for displaying information (separate responsibility)
class GradeDisplay
{
public:
    void displayGrade(const Grade &g)
    {
        std::cout << "Student grade: " << g.grade << std::endl;
    }
};

int main()
{
    Grade studentGrade("AA");
    GradeDisplay display;
    display.displayGrade(studentGrade);
    return 0;
}