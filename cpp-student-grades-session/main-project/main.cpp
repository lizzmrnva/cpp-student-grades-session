#include <iostream>
#include <windows.h>
#include "file_reader.h"
#include "filter.h"
#include "sort.h"
using namespace std;
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Программа обработки итогов сессии" << endl;
    cout << "Вариант 8: Итоги сессии" << endl;
    cout << "Автор: Миронова Елизавета" << endl;
    cout << "Группа: 09876-ф" << endl;
    StudentRecord students[MAX_STUDENTS];
    StudentRecord filtered[MAX_STUDENTS];
    int count = readStudentsFromFile("data.txt", students);
    if (count == 0) {
        cout << "Ошибка: не удалось загрузить данные!" << endl;
        return 1;
    }
    cout << "Загружено студентов: " << count << endl;
    int choice = -1;
    while (choice != 0) {
        cout << "\nМЕНЮ" << endl;
        cout << "1. Показать всех студентов" << endl;
        cout << "2. Фильтр: категория 'История Беларуси'" << endl;
        cout << "3. Фильтр: оценка выше 7" << endl;
        cout << "4. Сортировка" << endl;
        cout << "0. Выход" << endl;
        cout << "Выбор: ";
        cin >> choice;
        if (choice == 1) {
            cout << "\nВСЕ СТУДЕНТЫ" << endl;
            printHeader();
            for (int i = 0; i < count; i++) {
                printRecord(&students[i]);
            }
        }
        else if (choice == 2) {
            int n = filterByDiscipline(students, count, filtered, "История Беларуси");
            cout << "\nСТУДЕНТЫ: ИСТОРИЯ БЕЛАРУСИ" << endl;
            cout << "Найдено: " << n << endl;
            printHeader();
            for (int i = 0; i < n; i++) {
                printRecord(&filtered[i]);
            }
        }
        else if (choice == 3) {
            int n = filterByMinGrade(students, count, filtered, 7);
            cout << "\nСТУДЕНТЫ С ОЦЕНКОЙ > 7" << endl;
            cout << "Найдено: " << n << endl;
            printHeader();
            for (int i = 0; i < n; i++) {
                printRecord(&filtered[i]);
            }
        }
        else if (choice == 4) {
            StudentRecord* array[MAX_STUDENTS];
            for (int i = 0; i < count; i++) {
                array[i] = &students[i];
            }
            SortFunction sortMethods[] = { insertionSort, mergeSort };
            cout << "\nВыбор метода сортировки:" << endl;
            cout << "1. Insertion sort (вставками)" << endl;
            cout << "2. Merge sort (слиянием)" << endl;
            cout << "Выбор: ";
            int sortChoice;
            cin >> sortChoice;
            if (sortChoice < 1 || sortChoice > 2) {
                cout << "Неверный выбор." << endl;
                continue;
            }
            CompareFunction compareCriteria[] = { compareBySurname, compareByDisciplineAndGrade };
            cout << "Выбор критерия сортировки:" << endl;
            cout << "1. По возрастанию фамилии" << endl;
            cout << "2. По дисциплине (возр.) и оценке (убыв.)" << endl;
            cout << "Выбор: ";
            int compareChoice;
            cin >> compareChoice;
            if (compareChoice < 1 || compareChoice > 2) {
                cout << "Неверный выбор." << endl;
                continue;
            }
            sortMethods[sortChoice - 1](array, count, compareCriteria[compareChoice - 1]);
            cout << "\nРЕЗУЛЬТАТЫ СОРТИРОВКИ" << endl;
            printHeader();
            for (int i = 0; i < count; i++) {
                printRecord(array[i]);
            }
        }
    }
    return 0;
}