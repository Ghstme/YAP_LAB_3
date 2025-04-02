#include <iostream>
#include <vector>
#include <windows.h>
#include "Student.h"
#include "Teacher.h"
#include "FileIO.h"

void displayMenu();

void addStudent(std::vector<Student> &students);

void addTeacher(std::vector<Teacher> &teachers);

void displayAllStudents(const std::vector<Student> &students);

void displayAllTeachers(const std::vector<Teacher> &teachers);

void saveData(const std::vector<Student> &students, const std::vector<Teacher> &teachers);

void loadData(std::vector<Student> &students, std::vector<Teacher> &teachers);

void displaySpecialReports(const std::vector<Student> &students, const std::vector<Teacher> &teachers);

void clearInputBuffer();

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::vector<Student> students;
    std::vector<Teacher> teachers;

    int choice;
    do {
        displayMenu();
        std::cin >> choice;
        clearInputBuffer();

        switch (choice) {
            case 1: addStudent(students);
                break;
            case 2: addTeacher(teachers);
                break;
            case 3: displayAllStudents(students);
                break;
            case 4: displayAllTeachers(teachers);
                break;
            case 5: saveData(students, teachers);
                break;
            case 6: loadData(students, teachers);
                break;
            case 7: displaySpecialReports(students, teachers);
                break;
            case 0: std::cout << "Выход из программы.\n";
                break;
            default: std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}


void clearInputBuffer() {
    while (std::cin.get() != '\n') {
        continue;
    }
}

void displayMenu() {
    std::cout << "\nМеню:\n";
    std::cout << "1. Добавить студента\n";
    std::cout << "2. Добавить преподавателя\n";
    std::cout << "3. Показать всех студентов\n";
    std::cout << "4. Показать всех преподавателей\n";
    std::cout << "5. Сохранить данные в файл\n";
    std::cout << "6. Загрузить данные из файла\n";
    std::cout << "7. Показать специальные отчеты\n";
    std::cout << "0. Выход\n";
    std::cout << "Выберите действие: ";
}


void addStudent(std::vector<Student> &students) {
    std::string firstName, lastName, patronymic;
    std::cout << "Введите имя: ";
    std::getline(std::cin, firstName);
    std::cout << "Введите фамилию: ";
    std::getline(std::cin, lastName);
    std::cout << "Введите отчество: ";
    std::getline(std::cin, patronymic);

    std::vector<int> scores;
    std::cout << "Введите оценки через пробел: ";
    std::string scoresLine;
    std::getline(std::cin, scoresLine);


    std::string currentScore;
    for (char c: scoresLine) {
        if (c == ' ') {
            if (!currentScore.empty()) {
                try {
                    int score = std::stoi(currentScore);
                    if (score < 1 || score > 5) {
                        std::cout << "Ошибка: оценка должна быть от 1 до 5\n";
                        return;
                    }
                    scores.push_back(score);
                    currentScore.clear();
                } catch (...) {
                    std::cout << "Ошибка ввода оценок!\n";
                    return;
                }
            }
        } else if (isdigit(c)) {
            currentScore += c;
        }
    }


    if (!currentScore.empty()) {
        try {
            int score = std::stoi(currentScore);
            if (score < 1 || score > 5) {
                std::cout << "Ошибка: оценка должна быть от 1 до 5\n";
                return;
            }
            scores.push_back(score);
        } catch (...) {
            std::cout << "Ошибка ввода оценок!\n";
            return;
        }
    }

    students.emplace_back(firstName, lastName, patronymic, scores);
    std::cout << "Студент добавлен.\n";
}

void addTeacher(std::vector<Teacher> &teachers) {
    std::string firstName, lastName, patronymic, positionStr;
    std::cout << "Введите имя: ";
    std::getline(std::cin, firstName);
    std::cout << "Введите фамилию: ";
    std::getline(std::cin, lastName);
    std::cout << "Введите отчество: ";
    std::getline(std::cin, patronymic);

    std::cout << "Введите должность (ассистент, старший преподаватель, доцент, профессор): ";
    std::getline(std::cin, positionStr);
    Position position = Teacher::stringToPosition(positionStr);

    std::vector<std::string> subjects;
    std::cout << "Введите предметы через запятую: ";
    std::string subjectsLine;
    std::getline(std::cin, subjectsLine);

    std::string subject;
    for (char c: subjectsLine) {
        if (c == ',') {
            if (!subject.empty()) {
                subjects.push_back(subject);
                subject.clear();
            }
        } else if (c != ' ') {
            subject += c;
        }
    }
    if (!subject.empty()) {
        subjects.push_back(subject);
    }

    teachers.emplace_back(firstName, lastName, patronymic, position, subjects);
    std::cout << "Преподаватель добавлен.\n";
}


void displayAllStudents(const std::vector<Student> &students) {
    std::cout << "\nСписок студентов:\n";
    if (students.empty()) {
        std::cout << "Нет данных о студентах.\n";
        return;
    }

    for (size_t i = 0; i < students.size(); ++i) {
        std::cout << i + 1 << ". " << students[i].getFullStudentInfo() << "\n";
    }
}

void displayAllTeachers(const std::vector<Teacher> &teachers) {
    std::cout << "\nСписок преподавателей:\n";
    for (const auto &teacher: teachers) {
        std::cout << teacher.getFullTeacherInfo() << "\n";
    }
}

void saveData(const std::vector<Student> &students, const std::vector<Teacher> &teachers) {
    saveStudentsToFile(students, "students.txt");
    saveTeachersToFile(teachers, "teachers.txt");
    std::cout << "Данные сохранены в файлы students.txt и teachers.txt\n";
}

void loadData(std::vector<Student> &students, std::vector<Teacher> &teachers) {
    students = loadStudentsFromFile("students.txt");
    teachers = loadTeachersFromFile("teachers.txt");
    std::cout << "Данные загружены из файлов students.txt и teachers.txt\n";
}

void displaySpecialReports(const std::vector<Student> &students, const std::vector<Teacher> &teachers) {
    std::cout << "\n1. Студенты с средним баллом > 4:\n";
    for (const auto &student: students) {
        if (student.getAverageScore() > 4.0) {
            std::cout << student.getShortStudentInfo() << "\n";
        }
    }


    std::cout << "\n2. Студенты с средним баллом < 3:\n";
    for (const auto &student: students) {
        if (student.getAverageScore() < 3.0) {
            std::cout << student.getShortStudentInfo() << "\n";
        }
    }


    std::cout << "\n3. Студент с наибольшим количеством оценок:\n";
    if (!students.empty()) {
        const Student *maxStudent = &students[0];
        for (const auto &student: students) {
            if (student.getScoresCount() > maxStudent->getScoresCount()) {
                maxStudent = &student;
            }
        }
        std::cout << maxStudent->getFullStudentInfo() << "\n";
    }


    std::cout << "\n4. Все доценты:\n";
    for (const auto &teacher: teachers) {
        if (teacher.getPosition() == Position::DOCENT) {
            std::cout << teacher.getShortTeacherInfo() << "\n";
        }
    }


    std::cout << "\n5. Профессор с наибольшим количеством предметов:\n";
    const Teacher *maxProfessor = nullptr;
    for (const auto &teacher: teachers) {
        if (teacher.getPosition() == Position::PROFESSOR) {
            if (!maxProfessor || teacher.getSubjectsCount() > maxProfessor->getSubjectsCount()) {
                maxProfessor = &teacher;
            }
        }
    }
    if (maxProfessor) {
        std::cout << maxProfessor->getFullTeacherInfo() << "\n";
    }


    std::cout << "\n6. Преподаватели, ведущие информатику:\n";
    for (const auto &teacher: teachers) {
        if (teacher.teachesSubject("Информатика")) {
            std::cout << teacher.getFullTeacherInfo() << "\n";
        }
    }
}
