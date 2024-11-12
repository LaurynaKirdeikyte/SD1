#include <iostream>
#include "student.h"

int main() {
    std::vector<Student> visi_studentai;
    std::vector<Student> geri_studentai;
    std::vector<Student> blogi_studentai;


    read_students_from_file("students.txt", visi_studentai);

    split_students(visi_studentai, geri_studentai, blogi_studentai);


    write_students_to_file("geri_studentai.txt", geri_studentai);
    write_students_to_file("blogi_studentai.txt", blogi_studentai);

    std::cout << "Studentu duomenys yra isskirstyti.\n";

    return 0;
}
