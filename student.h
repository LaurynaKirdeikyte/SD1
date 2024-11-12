#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <list>
#include <deque>

class Student {
public:
    std::string name;
    int grade;

    Student(std::string n, int g) : name(n), grade(g) {}
};

void skait(const std::string& filename, std::vector<Student>& students);
void rasym(const std::string& filename, const std::vector<Student>& students);
void dalint(const std::vector<Student>& all_students, std::vector<Student>& pass_students, std::vector<Student>& fail_students);

#endif // STUDENT_H
