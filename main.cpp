#include "student.h"
#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <deque>

template <typename Container>
void test_container(const std::string& filename) {
    std::vector<Student> students;


    auto start = std::chrono::high_resolution_clock::now();
    skaityti_studentus_is_failo(filename, students);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Laikas skirtas duomenu skaitymui: " << duration.count() << " ms\n";


    std::vector<Student> blogi_studentai, geri_studentai;
    start = std::chrono::high_resolution_clock::now();
    stud_skirstymas(students, blogi_studentai, geri_studentai);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Laikas skirtas studentui skirstymui: " << duration.count() << " ms\n";


    start = std::chrono::high_resolution_clock::now();
    stud_failas("blogi_studentai.txt", blogi_studentai);
    stud_failas("geri_studentai.txt", geri_studentai);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Laikas skirtas duomenu isvedimui: " << duration.count() << " ms\n";
}

int main() {

    random_generavimas_studentu("students_1000.txt", 1000);
    random_generavimas_studentu("students_10000.txt", 10000);
    random_generavimas_studentu("students_100000.txt", 100000);
    random_generavimas_studentu("students_1000000.txt", 1000000);
    random_generavimas_studentu("students_10000000.txt", 10000000);


    std::cout << "std::vector:\n";
    test_container<std::vector<Student>>("students_1000.txt");

    std::cout << "\nstd::list:\n";
    test_container<std::list<Student>>("students_1000.txt");

    std::cout << "\nstd::deque:\n";
    test_container<std::deque<Student>>("students_1000.txt");

    return 0;
}
