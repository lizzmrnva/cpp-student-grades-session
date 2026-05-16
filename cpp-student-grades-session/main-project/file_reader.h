#pragma once
#include "book_subscription.h"
int readStudentsFromFile(const char* filename, StudentRecord* students);
bool isValidGrade(int grade);
bool isValidDate(const char* date);