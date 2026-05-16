#include <iostream>
#include "file_reader.h"
#include "filter.h"
using namespace std;
int main() {
    cout << "Программа обработки итогов сессии" << endl;
    cout << "Вариант 8: Итоги сессии" << endl;
    cout << "Автор: Миронова Елизавета" << endl;
    StudentRecord students[MAX_STUDENTS];
    StudentRecord filtered[MAX_STUDENTS];
    int count = readStudentsFromFile("data.txt", students);
    if (count == 0) {
        cout << "Ошибка: не удалось загрузить данные!" << endl;
        return 1;
    }
    cout << " Загружено студентов: " << count << endl;
    int choice = -1;
    while (choice != 0) {
        cout << "\nМЕНЮ" << endl;
        cout << "1. Показать всех студентов" << endl;
        cout << "2. Фильтр: категория 'История Беларуси'" << endl;
        cout << "3. Фильтр: оценка выше 7" << endl;
        cout << "0. Выход" << endl;
        cout << "Выбор: ";
        cin >> choice;
        if (choice == 1) {
            cout << "\n=== ВСЕ СТУДЕНТЫ ===" << endl;
            printHeader();
            for (int i = 0; i < count; i++) {
                printRecord(&students[i]);
            }
        }
        else if (choice == 2) {
            int n = filterByDiscipline(students, count, filtered, "История Беларуси");
            cout << "\n=== СТУДЕНТЫ: ИСТОРИЯ БЕЛАРУСИ ===" << endl;
            cout << "Найдено: " << n << endl;
            printHeader();
            for (int i = 0; i < n; i++) {
                printRecord(&filtered[i]);
            }
        }
        else if (choice == 3) {
            int n = filterByMinGrade(students, count, filtered, 7);
            cout << "\n=== СТУДЕНТЫ С ОЦЕНКОЙ > 7 ===" << endl;
            cout << "Найдено: " << n << endl;
            printHeader();
            for (int i = 0; i < n; i++) {
                printRecord(&filtered[i]);
            }
        }
    }
    return 0;
}