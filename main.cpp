#include <iostream>
#include <vector>
#include <string>
#include <clocale>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

// Функция для добавления студента в базу данных
void addStudent(std::vector<Student>& database) {
    Student student;
    std::cout << "Введите имя студента: ";
    std::cin >> student.name;
    std::cout << "Введите возраст студента: ";
    std::cin >> student.age;
    std::cout << "Введите специальность студента: ";
    std::cin >> student.major;
    std::cout << "Введите средний балл студента: ";
    std::cin >> student.gpa;

    database.push_back(student);
    std::cout << "Студент добавлен в базу данных.\n";
}

// Функция для вывода всех студентов из базы данных
void displayStudents(const std::vector<Student>& database) {
    if (database.empty()) {
        std::cout << "База данных пуста.\n";
        return;
    }
    
    std::cout << "Список студентов:\n";
    for (size_t i = 0; i < database.size(); i++) {
        std::cout << i + 1 << ". ";
        std::cout << "Имя: " << database[i].name << "\n";
        std::cout << "   Возраст: " << database[i].age << "\n";
        std::cout << "   Специальность: " << database[i].major << "\n";
        std::cout << "   Средний балл: " << database[i].gpa << "\n\n";
    }
}

// НОВАЯ ФУНКЦИЯ: 
void editStudent(std::vector<Student>& database) {
    if (database.empty()) {
        std::cout << "База данных пуста. Нечего редактировать.\n";
        return;
    }
    
    displayStudents(database);
    std::cout << "Функция редактирования студента будет реализована в следующих коммитах.\n";
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    std::vector<Student> database;

    int choice;
    do {
        std::cout << "\n=== Меню управления базой данных студентов ===\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "3. Редактировать информацию о студенте\n"; // НОВЫЙ ПУНКТ МЕНЮ
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(database);
                break;
            case 2:
                displayStudents(database);
                break;
            case 3: // НОВЫЙ КЕЙС ДЛЯ РЕДАКТИРОВАНИЯ
                editStudent(database);
                break;
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}