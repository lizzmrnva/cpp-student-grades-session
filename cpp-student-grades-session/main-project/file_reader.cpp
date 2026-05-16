#include "file_reader.h"
#include <fstream>
#include <cstring>
using namespace std;
int readStudentsFromFile(const char* filename, StudentRecord* students) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка: не удалось открыть файл " << filename << endl;
        return 0;
    }
    int count = 0;
    char line[MAX_LINE_LENGTH];
    while (file.getline(line, MAX_LINE_LENGTH) && count < MAX_STUDENTS) {
        if (strlen(line) == 0) continue;
        StudentRecord record;
        int fieldsRead = sscanf(line, "%s %s %s %s %d %[^\n]",
            record.surname,
            record.name,
            record.patronymic,
            record.date,
            &record.grade,
            record.discipline);
        if (fieldsRead == 6 && isValidGrade(record.grade) && isValidDate(record.date)) {
            students[count++] = record;
        }
    }
    file.close();
    return count;
}
bool isValidGrade(int grade) {
    return grade >= 1 && grade <= 10;
}
bool isValidDate(const char* date) {
    int day, month, year;
    int result = sscanf(date, "%d.%d.%d", &day, &month, &year);
    if (result != 3) return false;
    if (day < 1 || day > 31) return false;
    if (month < 1 || month > 12) return false;
    if (year < 0 || year > 99) return false;
    return true;
}