#include "filter.h"
#include <cstring>
using namespace std;
int filterByDiscipline(const StudentRecord* students, int count,
    StudentRecord* filtered, const char* discipline) {
    int filteredCount = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].discipline, discipline) == 0) {
            filtered[filteredCount++] = students[i];
        }
    }
    return filteredCount;
}
int filterByMinGrade(const StudentRecord* students, int count,
    StudentRecord* filtered, int minGrade) {
    int filteredCount = 0;
    for (int i = 0; i < count; i++) {
        if (students[i].grade > minGrade) {
            filtered[filteredCount++] = students[i];
        }
    }
    return filteredCount;
}