#include <iostream>
#include <vector>
#include <string>
#include <limits> 
#include <clocale>  


struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

// Функция для очистки буфера ввода
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Улучшенная функция для добавления студента с очисткой буфера
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

// Финальная версия функции редактирования с полной обработкой ошибок
void editStudent(std::vector<Student>& database) {
    if (database.empty()) {
        std::cout << "База данных пуста. Нечего редактировать.\n";
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
        
        if (std::cin.fail()) {
            std::cout << "Неверный ввод. Пожалуйста, введите число.\n";
            clearInputBuffer();
            continue;
        }
        
        clearInputBuffer();
        
        switch (choice) {
            case 1:
                std::cout << "Текущее имя: " << student.name << "\n";
                std::cout << "Введите новое имя: ";
                std::getline(std::cin, student.name);
                std::cout << "✓ Имя успешно изменено.\n";
                break;
            case 2:
                std::cout << "Текущий возраст: " << student.age << "\n";
                std::cout << "Введите новый возраст: ";
                std::cin >> student.age;
                if (std::cin.fail() || student.age < 0 || student.age > 150) {
                    std::cout << "Неверный возраст. Возраст должен быть числом от 0 до 150.\n";
                    student.age = 0; // Сброс на значение по умолчанию
                }
                clearInputBuffer();
                std::cout << "✓ Возраст успешно изменен.\n";
                break;
            case 3:
                std::cout << "Текущая специальность: " << student.major << "\n";
                std::cout << "Введите новую специальность: ";
                std::getline(std::cin, student.major);
                std::cout << "✓ Специальность успешно изменена.\n";
                break;
            case 4:
                std::cout << "Текущий средний балл: " << student.gpa << "\n";
                std::cout << "Введите новый средний балл: ";
                std::cin >> student.gpa;
                if (std::cin.fail() || student.gpa < 0.0 || student.gpa > 5.0) {
                    std::cout << "Неверный средний балл. Балл должен быть числом от 0.0 до 5.0.\n";
                    student.gpa = 0.0; // Сброс на значение по умолчанию
                }
                clearInputBuffer();
                std::cout << "✓ Средний балл успешно изменен.\n";
                break;
            case 5:
                std::cout << "\n=== Текущая информация о студенте ===\n";
                std::cout << "Имя: " << student.name << "\n";
                std::cout << "Возраст: " << student.age << "\n";
                std::cout << "Специальность: " << student.major << "\n";
                std::cout << "Средний балл: " << student.gpa << "\n";
                break;
            case 0:
                std::cout << "✓ Редактирование завершено. Возврат в главное меню.\n";
                break;
            default:
                std::cout << "Неверный выбор. Пожалуйста, выберите действие от 0 до 5.\n";
        }
    } while (choice != 0);
}

int main() {
    std::vector<Student> database;
    setlocale(LC_ALL, "ru_RU.UTF-8");


    int choice;
    do {
        std::cout << "\n=== Меню управления базой данных студентов ===\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "3. Редактировать информацию о студенте\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;
        
        if (std::cin.fail()) {
            std::cout << "Неверный ввод. Пожалуйста, введите число.\n";
            clearInputBuffer();
            continue;
        }
        
        clearInputBuffer();

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
                std::cout << "Выход из программы. До свидания!\n";
                break;
            default:
                std::cout << "Неверный выбор. Пожалуйста, выберите действие от 0 до 3.\n";
        }
    } while (choice != 0);

    return 0;
}