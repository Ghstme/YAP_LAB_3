#include "FileIO.h"
#include <fstream>
#include <string>
#include <iostream>

void saveStudentsToFile(const std::vector<Student> &students, const std::string &filename) {
    std::ofstream out(filename);
    if (!out.is_open()) {
        std::cerr << "Ошибка открытия файла для записи студентов: " << filename << std::endl;
        return;
    }

    for (const auto &student: students) {
        out << student.getFullName() << "\n";
        const auto &scores = student.getScores();
        for (size_t i = 0; i < scores.size(); ++i) {
            if (i != 0) out << " ";
            out << scores[i];
        }
        out << "\n";
    }
}

std::vector<Student> loadStudentsFromFile(const std::string &filename) {
    std::vector<Student> students;
    std::ifstream in(filename);
    if (!in.is_open()) {
        std::cerr << "Ошибка открытия файла для чтения студентов: " << filename << std::endl;
        return students;
    }

    std::string line;
    while (std::getline(in, line)) {
        size_t pos1 = line.find(' ');
        size_t pos2 = line.find(' ', pos1 + 1);

        std::string lastName = line.substr(0, pos1);
        std::string firstName = line.substr(pos1 + 1, pos2 - pos1 - 1);
        std::string patronymic = line.substr(pos2 + 1);

        std::getline(in, line);
        std::vector<int> scores;
        size_t start = 0;
        size_t end = line.find(' ');

        while (end != std::string::npos) {
            scores.push_back(std::stoi(line.substr(start, end - start)));
            start = end + 1;
            end = line.find(' ', start);
        }
        if (start < line.length()) {
            scores.push_back(std::stoi(line.substr(start)));
        }

        students.emplace_back(firstName, lastName, patronymic, scores);
    }

    return students;
}

void saveTeachersToFile(const std::vector<Teacher> &teachers, const std::string &filename) {
    std::ofstream out(filename);
    if (!out.is_open()) {
        std::cerr << "Ошибка открытия файла для записи преподавателей: " << filename << std::endl;
        return;
    }

    for (const auto &teacher: teachers) {
        out << teacher.getFullName() << "\n";
        out << static_cast<int>(teacher.getPosition()) << "\n";


        const std::vector<std::string> &subjects = teacher.getSubjects();
        for (const auto &subject: subjects) {
            out << subject << "\n";
        }
        out << "===\n";
    }
}

std::vector<Teacher> loadTeachersFromFile(const std::string &filename) {
    std::vector<Teacher> teachers;
    std::ifstream in(filename);
    if (!in.is_open()) {
        std::cerr << "Ошибка открытия файла для чтения преподавателей: " << filename << std::endl;
        return teachers;
    }

    std::string line;
    while (std::getline(in, line)) {
        size_t pos1 = line.find(' ');
        size_t pos2 = line.find(' ', pos1 + 1);

        std::string lastName = line.substr(0, pos1);
        std::string firstName = line.substr(pos1 + 1, pos2 - pos1 - 1);
        std::string patronymic = line.substr(pos2 + 1);

        std::getline(in, line);
        Position position = static_cast<Position>(std::stoi(line));

        std::vector<std::string> subjects;
        while (std::getline(in, line) && line != "===") {
            subjects.push_back(line);
        }

        teachers.emplace_back(firstName, lastName, patronymic, position, subjects);
    }

    return teachers;
}
