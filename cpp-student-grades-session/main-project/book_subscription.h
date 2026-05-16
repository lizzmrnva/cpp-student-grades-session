#pragma once

#include "constants.h"
#include <iostream>
#include <iomanip>

using namespace std;

struct StudentRecord {
    char surname[MAX_NAME_LENGTH];
    char name[MAX_NAME_LENGTH];
    char patronymic[MAX_NAME_LENGTH];
    char date[15];
    int grade;
    char discipline[MAX_DISCIPLINE_LENGTH];
};

void printRecord(const StudentRecord* record) {
    cout << left
        << setw(15) << record->surname
        << setw(15) << record->name
        << setw(15) << record->patronymic
        << setw(12) << record->date
        << setw(7) << record->grade
        << record->discipline << endl;
}

void printHeader() {
    cout << left
        << setw(15) << "Фамилия"
        << setw(15) << "Имя"
        << setw(15) << "Отчество"
        << setw(12) << "Дата"
        << setw(7) << "Оценка"
        << "Дисциплина" << endl;

    for (int i = 0; i < 80; i++) {
        cout << "-";
    }
    cout << endl;
}