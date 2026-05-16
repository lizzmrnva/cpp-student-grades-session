#include "sort.h"
#include <cstring>
using namespace std;
void insertionSort(StudentRecord** array, int size, CompareFunction compare) {
    for (int i = 1; i < size; i++) {
        StudentRecord* key = array[i];
        int j = i - 1;

        while (j >= 0 && compare(array[j], key) > 0) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}
void merge(StudentRecord** array, int left, int middle, int right, CompareFunction compare) {
    int n1 = middle - left + 1;
    int n2 = right - middle;
    StudentRecord** leftArray = new StudentRecord * [n1];
    StudentRecord** rightArray = new StudentRecord * [n2];
    for (int i = 0; i < n1; i++) leftArray[i] = array[left + i];
    for (int i = 0; i < n2; i++) rightArray[i] = array[middle + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (compare(leftArray[i], rightArray[j]) <= 0)
            array[k++] = leftArray[i++];
        else
            array[k++] = rightArray[j++];
    }
    while (i < n1) array[k++] = leftArray[i++];
    while (j < n2) array[k++] = rightArray[j++];

    delete[] leftArray;
    delete[] rightArray;
}
void mergeSortHelper(StudentRecord** array, int left, int right, CompareFunction compare) {
    if (left < right) {
        int middle = (left + right) / 2;
        mergeSortHelper(array, left, middle, compare);
        mergeSortHelper(array, middle + 1, right, compare);
        merge(array, left, middle, right, compare);
    }
}
void mergeSort(StudentRecord** array, int size, CompareFunction compare) {
    if (size > 1) mergeSortHelper(array, 0, size - 1, compare);
}
int compareBySurname(const StudentRecord* first, const StudentRecord* second) {
    return strcmp(first->surname, second->surname);
}
int compareByDisciplineAndGrade(const StudentRecord* first, const StudentRecord* second) {
    int result = strcmp(first->discipline, second->discipline);
    if (result != 0) return result;
    return second->grade - first->grade;
}