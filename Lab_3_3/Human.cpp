#include "Human.h"

Human::Human() : firstName("Неизвестно"), lastName("Неизвестно"), patronymic("Неизвестно") {
}

Human::Human(const std::string &firstName, const std::string &lastName, const std::string &patronymic)
    : firstName(firstName), lastName(lastName), patronymic(patronymic) {
}

std::string Human::getSurnameAndInitials() const {
    std::string result = lastName + " ";
    if (!firstName.empty()) result += firstName[0];
    result += ".";
    if (!patronymic.empty()) result += patronymic[0];
    result += ".";
    return result;
}

std::string Human::getFullName() const {
    return lastName + " " + firstName + " " + patronymic;
}
