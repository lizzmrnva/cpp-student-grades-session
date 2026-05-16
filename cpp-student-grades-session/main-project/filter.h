#pragma once
#include "book_subscription.h"
using namespace std;
int filterByDiscipline(const StudentRecord* students, int count,
    StudentRecord* filtered, const char* discipline);
int filterByMinGrade(const StudentRecord* students, int count,
    StudentRecord* filtered, int minGrade);