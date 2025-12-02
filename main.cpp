#include <iostream>
#include <vector>
#include <string>

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

// НОВАЯ ФУНКЦИЯ: Полная реализация редактирования с меню выбора полей
void editStudent(std::vector<Student>& database) {
    if (database.empty()) {
        std::cout << "База данных пуста. Нечего редактировать.\n";
        return;
    }
    
    displayStudents(database);
    
    int studentNumber;
    std::cout << "Введите номер студента для редактирования (1-" << database.size() << "): ";
    std::cin >> studentNumber;
    
    if (studentNumber < 1 || studentNumber > static_cast<int>(database.size())) {
        std::cout << "Неверный номер студента.\n";
        return;
    }
    
    Student& student = database[studentNumber - 1];
    
    int choice;
    do {
        std::cout << "\nРедактирование студента: " << student.name << "\n";
        std::cout << "1. Изменить имя\n";
        std::cout << "2. Изменить возраст\n";
        std::cout << "3. Изменить специальность\n";
        std::cout << "4. Изменить средний балл\n";
        std::cout << "5. Показать текущую информацию\n";
        std::cout << "0. Завершить редактирование\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                std::cout << "Текущее имя: " << student.name << "\n";
                std::cout << "Введите новое имя: ";
                std::cin >> student.name;
                std::cout << "Имя изменено.\n";
                break;
            case 2:
                std::cout << "Текущий возраст: " << student.age << "\n";
                std::cout << "Введите новый возраст: ";
                std::cin >> student.age;
                std::cout << "Возраст изменен.\n";
                break;
            case 3:
                std::cout << "Текущая специальность: " << student.major << "\n";
                std::cout << "Введите новую специальность: ";
                std::cin >> student.major;
                std::cout << "Специальность изменена.\n";
                break;
            case 4:
                std::cout << "Текущий средний балл: " << student.gpa << "\n";
                std::cout << "Введите новый средний балл: ";
                std::cin >> student.gpa;
                std::cout << "Средний балл изменен.\n";
                break;
            case 5:
                std::cout << "\nТекущая информация о студенте:\n";
                std::cout << "Имя: " << student.name << "\n";
                std::cout << "Возраст: " << student.age << "\n";
                std::cout << "Специальность: " << student.major << "\n";
                std::cout << "Средний балл: " << student.gpa << "\n";
                break;
            case 0:
                std::cout << "Редактирование завершено.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);
}

int main() {
    std::vector<Student> database;

    int choice;
    do {
        std::cout << "\n=== Меню управления базой данных студентов ===\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "3. Редактировать информацию о студенте\n";
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
            case 3:
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