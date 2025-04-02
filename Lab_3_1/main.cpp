#include <iostream>
#define NOGDI
#include <windows.h>
#undef Rectangle

#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Square.h"
#include "CylinderVolume.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Figure *figure = nullptr;
    int choice;
    double cylinder_height;

    std::cout << "Выберите тип фигуры:" << std::endl;
    std::cout << "1. Круг" << std::endl;
    std::cout << "2. Прямоугольник" << std::endl;
    std::cout << "3. Треугольник" << std::endl;
    std::cout << "4. Квадрат" << std::endl;
    std::cout << "Ваш выбор: ";
    std::cin >> choice;

    if (choice == 1) {
        double radius;
        std::cout << "Введите радиус круга: ";
        std::cin >> radius;
        figure = new Circle(radius);
    } else if (choice == 2) {
        double width, height;
        std::cout << "Введите ширину и высоту прямоугольника: ";
        std::cin >> width >> height;
        figure = new ::Rectangle(width, height); // Явное указание пространства имён
    } else if (choice == 3) {
        double base, height;
        std::cout << "Введите основание и высоту треугольника: ";
        std::cin >> base >> height;
        figure = new Triangle(base, height);
    } else if (choice == 4) {
        double side;
        std::cout << "Введите сторону квадрата: ";
        std::cin >> side;
        figure = new Square(side);
    } else {
        std::cout << "Неверный выбор!" << std::endl;
        return 1;
    }

    std::cout << "Введите высоту цилиндра: ";
    std::cin >> cylinder_height;

    figure->Show();
    std::cout << "Площадь: " << figure->CalcArea() << std::endl;
    std::cout << "Объем цилиндра: " << CalculateCylinderVolume(figure, cylinder_height) << std::endl;

    delete figure;
    return 0;
}
