#include "Student.h"
#include <iostream>
#include <numeric>
#include <algorithm>

Student::Student() : firstName(""), lastName(""), examGrade(0), finalGrade(0.0) {}

Student::Student(std::string fName, std::string lName, std::vector<int> hwGrades, int exam)
    : firstName(fName), lastName(lName), homeworkGrades(hwGrades), examGrade(exam), finalGrade(0.0) {}

Student::Student(const Student& other) {
    firstName = other.firstName;
    lastName = other.lastName;
    homeworkGrades = other.homeworkGrades;
    examGrade = other.examGrade;
    finalGrade = other.finalGrade;
}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        firstName = other.firstName;
        lastName = other.lastName;
        homeworkGrades = other.homeworkGrades;
        examGrade = other.examGrade;
        finalGrade = other.finalGrade;
    }
    return *this;
}

Student::~Student() {}

void Student::enterData() {
    std::cout << "Iveskite varda: ";
    std::cin >> firstName;
    std::cout << "Iveskite pavarde: ";
    std::cin >> lastName;


    homeworkGrades.clear();
        int grade;
        std::cout << "Iveskite namu darbu ivertinima: ";
        std::cin >> grade;
        homeworkGrades.push_back(grade);

    std::cout << "Iveskite egzamino ivertinima: ";
    std::cin >> examGrade;
}

void Student::calculateFinalGrade() {
    double avgHomework = std::accumulate(homeworkGrades.begin(), homeworkGrades.end(), 0.0) / homeworkGrades.size();
    finalGrade = 0.4 * avgHomework + 0.6 * examGrade;
}

void Student::displayData() const {
    std::cout << lastName << "\t" << firstName << "\t" << finalGrade << std::endl;
}
