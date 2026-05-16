#include "file_reader.h"
#include <fstream>
#include <sstream> 
#include <cstring>
#include <iostream>

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

        stringstream ss(line);
        StudentRecord record;

        ss >> record.surname;
        ss >> record.name;
        ss >> record.patronymic;
        ss >> record.date;
        ss >> record.grade;

        ss >> ws;
        ss.getline(record.discipline, MAX_DISCIPLINE_LENGTH);

        if (!ss.fail() && isValidGrade(record.grade) && isValidDate(record.date)) {
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
    stringstream ss(date);
    int day, month, year;
    char dot1, dot2;
    ss >> day >> dot1 >> month >> dot2 >> year;
    if (ss.fail() || dot1 != '.' || dot2 != '.') {
        return false;
    }
    if (day < 1 || day > 31) return false;
    if (month < 1 || month > 12) return false;
    if (year < 0 || year > 2100) return false;
    return true;
}