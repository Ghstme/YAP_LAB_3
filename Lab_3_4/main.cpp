#include <iostream>
#include <windows.h>
#include "Summator.h"
#include "SquareSummator.h"
#include "CubeSummator.h"

void displayMenu();

void calculateSum(Summator *summator, const std::string &typeName);

void clearInputBuffer();

int getPositiveInteger();

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int choice;

    Summator simpleSum;
    SquareSummator squareSum;
    CubeSummator cubeSum;

    do {
        displayMenu();
        std::cin >> choice;
        clearInputBuffer();

        switch (choice) {
            case 1:
                calculateSum(&simpleSum, "обычная сумма");
                break;
            case 2:
                calculateSum(&squareSum, "сумма квадратов");
                break;
            case 3:
                calculateSum(&cubeSum, "сумма кубов");
                break;
            case 4: {
                Summator *summators[3] = {new Summator(), new SquareSummator(), new CubeSummator()};
                std::string types[3] = {"обычная", "квадратов", "кубов"};

                std::cout << "\nВведите N для всех трех типов сумм: ";
                int N = getPositiveInteger();

                std::cout << "\nРезультаты (позднее связывание):\n";
                for (int i = 0; i < 3; ++i) {
                    std::cout << "Сумма " << types[i] << ": "
                            << summators[i]->sum(N) << std::endl;
                    delete summators[i];
                }
                break;
            }
            case 5:
                std::cout << "\nФормулы для проверки:\n";
                std::cout << "1. 1 + 2 + ... + N = N(N+1)/2\n";
                std::cout << "2. 1 + 2² + ... + N² = N(N+1)(2N+1)/6\n";
                std::cout << "3. 1 + 2³ + ... + N³ = [N(N+1)/2]²\n\n";
                break;
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }

        if (choice != 0) {
            std::cout << "\nНажмите Enter для продолжения...";
            while (std::cin.get() != '\n');
        }
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    std::cout << "\n=== Калькулятор сумм последовательностей ===\n";
    std::cout << "1. Вычислить сумму чисел 1 + 2 + ... + N\n";
    std::cout << "2. Вычислить сумму квадратов 1 + 2² + ... + N²\n";
    std::cout << "3. Вычислить сумму кубов 1 + 2³ + ... + N³\n";
    std::cout << "4. Демонстрация позднего связывания (все три суммы)\n";
    std::cout << "5. Показать формулы для проверки\n";
    std::cout << "0. Выход\n";
    std::cout << "Выберите действие: ";
}

void calculateSum(Summator *summator, const std::string &typeName) {
    std::cout << "Введите N для вычисления " << typeName << ": ";
    int N = getPositiveInteger();

    int result = summator->sum(N);
    std::cout << "\nРезультат (" << typeName << "): " << result << std::endl;
}

void clearInputBuffer() {
    while (std::cin.get() != '\n');
}

int getPositiveInteger() {
    int N;
    while (true) {
        std::cin >> N;
        if (std::cin.fail() || N < 1) {
            std::cout << "Ошибка! Введите целое число больше 0: ";
            clearInputBuffer();
        } else {
            clearInputBuffer();
            return N;
        }
    }
}
