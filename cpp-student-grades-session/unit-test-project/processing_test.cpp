#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/book_subscription.h"
#include "../main-project/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
    TEST_CLASS(ProcessingTests)
    {
    public:
        // Тест 1: Сессия с одной датой должна вернуть 0
        TEST_METHOD(Test_SingleDate_ReturnsZero)
        {
            StudentRecord students[1];

            strcpy_s(students[0].surname, MAX_NAME_LENGTH, "Иванов");
            strcpy_s(students[0].name, MAX_NAME_LENGTH, "Иван");
            strcpy_s(students[0].patronymic, MAX_NAME_LENGTH, "Иванович");
            strcpy_s(students[0].date, 15, "15.01.24");
            students[0].grade = 8;
            strcpy_s(students[0].discipline, MAX_DISCIPLINE_LENGTH, "История");

            int result = getSessionDuration(students, 1);
            Assert::AreEqual(0, result);
        }
        // Тест 2: Сессия с датами в одном месяце
        TEST_METHOD(Test_SameMondates_ReturnsDifference)
        {
            StudentRecord students[2];

            strcpy_s(students[0].surname, MAX_NAME_LENGTH, "Иванов");
            strcpy_s(students[0].name, MAX_NAME_LENGTH, "Иван");
            strcpy_s(students[0].patronymic, MAX_NAME_LENGTH, "Иванович");
            strcpy_s(students[0].date, 15, "10.01.24");
            students[0].grade = 8;
            strcpy_s(students[0].discipline, MAX_DISCIPLINE_LENGTH, "История");

            strcpy_s(students[1].surname, MAX_NAME_LENGTH, "Петров");
            strcpy_s(students[1].name, MAX_NAME_LENGTH, "Петр");
            strcpy_s(students[1].patronymic, MAX_NAME_LENGTH, "Петрович");
            strcpy_s(students[1].date, 15, "20.01.24");
            students[1].grade = 9;
            strcpy_s(students[1].discipline, MAX_DISCIPLINE_LENGTH, "Математика");

            int result = getSessionDuration(students, 2);
            Assert::AreEqual(10, result);
        }

        // Тест 3: Сессия с датами в разных месяцах
        TEST_METHOD(Test_DifferentMonths_CalculatesDuration)
        {
            StudentRecord students[2];

            strcpy_s(students[0].surname, MAX_NAME_LENGTH, "Иванов");
            strcpy_s(students[0].name, MAX_NAME_LENGTH, "Иван");
            strcpy_s(students[0].patronymic, MAX_NAME_LENGTH, "Иванович");
            strcpy_s(students[0].date, 15, "31.01.24");
            students[0].grade = 8;
            strcpy_s(students[0].discipline, MAX_DISCIPLINE_LENGTH, "История");

            strcpy_s(students[1].surname, MAX_NAME_LENGTH, "Петров");
            strcpy_s(students[1].name, MAX_NAME_LENGTH, "Петр");
            strcpy_s(students[1].patronymic, MAX_NAME_LENGTH, "Петрович");
            strcpy_s(students[1].date, 15, "05.02.24");
            students[1].grade = 9;
            strcpy_s(students[1].discipline, MAX_DISCIPLINE_LENGTH, "Математика");

            int result = getSessionDuration(students, 2);
            Assert::AreEqual(5, result);
        }
    };
}