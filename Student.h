#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>


struct Student {
    std::string name;
    std::string surname;
    double grade;
};


void random_generavimas_studentu(const std::string& filename, int num_student);
void skaityti_studentus_is_failo(const std::string& filename, std::vector<Student>& student);
void stud_skirstymas(const std::vector<Student>& student,
    std::vector<Student>& blogi_studentai,
    std::vector<Student>& geri_studentai);
void stud_failas(const std::string& filename, const std::vector<Student>& student);

#endif // STUDENT_H
