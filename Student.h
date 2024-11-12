#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>

class Student {
private:
    std::string firstName;
    std::string lastName;
    std::vector<int> homeworkGrades;
    int examGrade;
    double finalGrade;

public:
    // Constructors
    Student();
    Student(std::string fName, std::string lName, std::vector<int> hwGrades, int exam);
    Student(const Student& other);  // Copy Constructor
    Student& operator=(const Student& other);  // Copy Assignment Operator
    ~Student();

    // Methods
    void enterData();
    void calculateFinalGrade();
    void displayData() const;

    double getFinalGrade() const { return finalGrade; }
};

#endif
