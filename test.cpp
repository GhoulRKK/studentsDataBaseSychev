#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <sstream>

#include "test.h"
#include "database.h"



// Тест 1: Проверка создания структуры Student
void testStudentCreation() {
    std::cout << "Тест 1: Проверка создания структуры Student... ";
    
    Student student;
    student.name = "Иван Иванов";
    student.age = 20;
    student.major = "Информатика";
    student.gpa = 4.5;
    
    assert(student.name == "Иван Иванов");
    assert(student.age == 20);
    assert(student.major == "Информатика");
    assert(student.gpa == 4.5);
    
    std::cout << "Пройден\n";
}

// Тест 2: Проверка работы с вектором студентов
void testStudentVector() {
    std::cout << "Тест 2: Проверка работы с вектором студентов... ";
    
    std::vector<Student> database;
    
    Student s1 = {"Анна Петрова", 21, "Математика", 4.7};
    Student s2 = {"Петр Сидоров", 22, "Физика", 4.3};
    
    database.push_back(s1);
    database.push_back(s2);
    
    assert(database.size() == 2);
    assert(database[0].name == "Анна Петрова");
    assert(database[1].major == "Физика");
    
    std::cout << "Пройден\n";
}

// Тест 3: Проверка отображения пустой базы данных
void testEmptyDatabaseDisplay() {
    std::cout << "Тест 3: Проверка отображения пустой базы данных... ";
    
    std::vector<Student> emptyDatabase;
    
    std::stringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    
    displayStudents(emptyDatabase);
    
    std::cout.rdbuf(oldCoutBuffer);
    std::string result = output.str();
    
    assert(!result.empty());
    std::cout << "Пройден\n";
}

// Тест 4: Проверка отображения базы с данными
void testDatabaseWithDataDisplay() {
    std::cout << "Тест 4: Проверка отображения базы с данными... ";
    
    std::vector<Student> database;
    database.push_back({"Мария", 19, "Химия", 4.8});
    database.push_back({"Алексей", 20, "Биология", 4.2});
    
    std::stringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    
    displayStudents(database);
    
    std::cout.rdbuf(oldCoutBuffer);
    std::string result = output.str();
    
    assert(!result.empty());
    std::cout << "Пройден\n";
}

// Тест 5: Проверка редактирования данных
void testDataEditing() {
    std::cout << "Тест 5: Проверка редактирования данных... ";
    
    std::vector<Student> database;
    database.push_back({"Иван", 20, "Информатика", 4.0});
    
    database[0].name = "Иван Петров";
    database[0].age = 21;
    database[0].major = "Программирование";
    database[0].gpa = 4.5;
    
    assert(database[0].name == "Иван Петров");
    assert(database[0].age == 21);
    assert(database[0].major == "Программирование");
    assert(database[0].gpa == 4.5);
    
    std::cout << "Пройден\n";
}

// Основная функция запуска тестов
void runTests() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    std::cout << "\n=== Запуск тестов ===\n";
    
    testStudentCreation();
    testStudentVector();
    testEmptyDatabaseDisplay();
    testDatabaseWithDataDisplay();
    testDataEditing();
    
    std::cout << "=== Все тесты пройдены ===\n\n";
}
