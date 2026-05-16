#pragma once
#include "book_subscription.h"
using namespace std;
typedef int (*CompareFunction)(const StudentRecord*, const StudentRecord*);
typedef void (*SortFunction)(StudentRecord**, int, CompareFunction);
void insertionSort(StudentRecord** array, int size, CompareFunction compare);
void mergeSort(StudentRecord** array, int size, CompareFunction compare);
int compareBySurname(const StudentRecord* first, const StudentRecord* second);
int compareByDisciplineAndGrade(const StudentRecord* first, const StudentRecord* second);