#include "database.h"
#include "test.h"
#include <iostream>
#include <vector>


int main() {
    std::vector<Student> database;

    runTests();


    int choice;
    do {
        std::cout << "\n1. Добавить студента\n2. Вывести список\n3. Редактировать\n0. Выход\nВыберите действие: ";
        std::cin >> choice;
        if (std::cin.fail()) { clearInputBuffer(); continue; }
        clearInputBuffer();
        switch(choice) {
            case 1: addStudent(database); break;
            case 2: displayStudents(database); break;
            case 3: editStudent(database); break;
            case 0: break;
            default: std::cout << "Неверный выбор.\n";
        }
    } while(choice != 0);

    return 0;
}
