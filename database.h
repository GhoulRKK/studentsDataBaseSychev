#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <string>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

void clearInputBuffer();
void addStudent(std::vector<Student>& database);
void displayStudents(const std::vector<Student>& database);
void editStudent(std::vector<Student>& database);

#endif
