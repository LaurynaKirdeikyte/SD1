#include "student.h"
#include <fstream>
#include <sstream>

void skait(const std::string& filename, std::vector<Student>& stud) {
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name;
        int grade;
        ss >> name >> grade;
        stud.push_back(Student(name, grade));
    }
}

void rasym(const std::string& filename, const std::vector<Student>& stud) {
    std::ofstream file(filename);
    for (const auto& student : stud) {
        file << student.name << " " << student.grade << "\n";
    }
}

void dalint(const std::vector<Student>& visi_studentai, std::vector<Student>& geri_studentai, std::vector<Student>& blogi_studentai) {
    for (const auto& student : visi_studentai) {
        if (student.grade >= 50) {
            geri_studentai.push_back(student);
        }
        else {
            blogi_studentai.push_back(student);
        }
    }
}
