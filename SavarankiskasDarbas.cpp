#include <iostream>
#include <vector>
#include <iomanip>
#include "student.h"

int main() {
    std::vector<Student> studentai;
    int Studsk;

    std::cout << "Iveskite studentu skaiciu ";
    std::cin >> Studsk;

    for (int i = 0; i < Studsk; ++i) {
        Student s;
        s.enterData();
        s.calculateFinalGrade();
        studentai.push_back(s);
    }


    std::cout << "Pavardė\tVardas\tGalutinis\n";
    std::cout << "--------------------------\n";
    for (const auto& s : studentai) {
        s.displayData();
    }

    return 0;
}
