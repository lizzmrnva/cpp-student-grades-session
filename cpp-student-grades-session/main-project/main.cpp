#include <iostream>
#include "file_reader.h"
using namespace std;
int main() {
    cout << "Программа обработки итогов сессии" << endl;
    cout << "Вариант 8: Итоги сессии" << endl;
    cout << "Автор: Миронова Елизавета" << endl;
    StudentRecord students[MAX_STUDENTS];
    int count = readStudentsFromFile("data.txt", students);
    if (count == 0) {
        cout << "Ошибка: не удалось загрузить данные!" << endl;
        return 1;
    }
    cout << "✓ Загружено студентов: " << count << endl << endl;
    printHeader();
    for (int i = 0; i < count; i++) {
        printRecord(&students[i]);
    }
    return 0;
}