#include "database.h"
#include <iostream>
#include <limits>

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void addStudent(std::vector<Student>& database) {
    Student student;
    
    std::cout << "Введите имя студента: ";
    std::getline(std::cin, student.name);
    
    std::cout << "Введите возраст студента: ";
    std::cin >> student.age;
    clearInputBuffer();
    
    std::cout << "Введите специальность студента: ";
    std::getline(std::cin, student.major);
    
    std::cout << "Введите средний балл студента: ";
    std::cin >> student.gpa;
    clearInputBuffer();

    database.push_back(student);
    std::cout << "Студент добавлен в базу данных.\n";
}

void displayStudents(const std::vector<Student>& database) {
    if (database.empty()) {
        std::cout << "База данных пуста.\n";
        return;
    }
    for (size_t i = 0; i < database.size(); i++) {
        std::cout << i + 1 << ". ";
        std::cout << "Имя: " << database[i].name << "\n";
        std::cout << "Возраст: " << database[i].age << "\n";
        std::cout << "Специальность: " << database[i].major << "\n";
        std::cout << "Средний балл: " << database[i].gpa << "\n\n";
    }
}

void editStudent(std::vector<Student>& database) {
    if (database.empty()) {
        std::cout << "База данных пуста.\n";
        return;
    }
    
    displayStudents(database);
    
    int studentNumber;
    std::cout << "Введите номер студента для редактирования (1-" << database.size() << "): ";
    std::cin >> studentNumber;
    if (std::cin.fail() || studentNumber < 1 || studentNumber > static_cast<int>(database.size())) {
        std::cout << "Неверный номер студента.\n";
        clearInputBuffer();
        return;
    }
    clearInputBuffer();
    Student& student = database[studentNumber - 1];
    
    int choice;
    do {
        std::cout << "\n=== Редактирование студента: " << student.name << " ===\n";
        std::cout << "1. Изменить имя\n";
        std::cout << "2. Изменить возраст\n";
        std::cout << "3. Изменить специальность\n";
        std::cout << "4. Изменить средний балл\n";
        std::cout << "5. Показать текущую информацию\n";
        std::cout << "0. Завершить редактирование\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;
        if (std::cin.fail()) { clearInputBuffer(); continue; }
        clearInputBuffer();
        switch(choice) {
            case 1: std::cout << "Введите новое имя: "; std::getline(std::cin, student.name); break;
            case 2: std::cout << "Введите новый возраст: "; std::cin >> student.age; clearInputBuffer(); break;
            case 3: std::cout << "Введите новую специальность: "; std::getline(std::cin, student.major); break;
            case 4: std::cout << "Введите новый средний балл: "; std::cin >> student.gpa; clearInputBuffer(); break;
            case 5: displayStudents({student}); break;
            case 0: break;
            default: std::cout << "Неверный выбор.\n";
        }
    } while (choice != 0);
}
