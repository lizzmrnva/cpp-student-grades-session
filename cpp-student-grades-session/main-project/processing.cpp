#include "processing.h"
#include <cstring>
using namespace std;
// Возвращает количество дней с начала года
int dateToDay(const char* date) {
    int day = (date[0] - '0') * 10 + (date[1] - '0');
    int month = (date[3] - '0') * 10 + (date[4] - '0');
    int year = (date[6] - '0') * 10 + (date[7] - '0');
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int totalDays = day;
    for (int i = 0; i < month - 1; i++) {
        totalDays += daysInMonth[i];
    }
    return totalDays;
}
int getSessionDuration(const StudentRecord* students, int count) {
    // Если нет студентов, длительность = 0
    if (count == 0) {
        return 0;
    }
    // Находим минимальный и максимальный дни в году
    int minDay = dateToDay(students[0].date);
    int maxDay = dateToDay(students[0].date);
    // Проходим по всем студентам
    for (int i = 1; i < count; i++) {
        int currentDay = dateToDay(students[i].date);
        // Обновляем минимум
        if (currentDay < minDay) {
            minDay = currentDay;
        }
        // Обновляем максимум
        if (currentDay > maxDay) {
            maxDay = currentDay;
        }
    }
    // Возвращаем разницу
    return maxDay - minDay;
}