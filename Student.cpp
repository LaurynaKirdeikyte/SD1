#include "student.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>


void random_generavimas_studentu(const std::string& filename, int num_students) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    srand(time(0));
    for (int i = 0; i < num_students; ++i) {
        file << "Vardas" << i + 1 << " Pavarde" << i + 1 << " "
            << (rand() % 100) / 10.0 + 1.0 << "\n";
    }
}


void skaityti_studentus_is_failo(const std::string& filename, std::vector<Student>& students) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream stream(line);
        Student student;
        stream >> student.name >> student.surname >> student.grade;
        students.push_back(student);
    }
}


void stud_skirstymas(const std::vector<Student>& students,
    std::vector<Student>& poor_students,
    std::vector<Student>& good_students) {
    for (const auto& student : students) {
        if (student.grade < 5.0)
            poor_students.push_back(student);
        else
            good_students.push_back(student);
    }
}


void stud_failas(const std::string& filename, const std::vector<Student>& students) {
    std::ofstream file(filename);
    for (const auto& student : students) {
        file << student.name << " " << student.surname << " " << student.grade << "\n";
    }
}
