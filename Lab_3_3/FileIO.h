#ifndef FILEIO_H
#define FILEIO_H
#include "Student.h"
#include "Teacher.h"
#include <vector>

void saveStudentsToFile(const std::vector<Student> &students, const std::string &filename);

std::vector<Student> loadStudentsFromFile(const std::string &filename);

void saveTeachersToFile(const std::vector<Teacher> &teachers, const std::string &filename);

std::vector<Teacher> loadTeachersFromFile(const std::string &filename);
#endif //FILEIO_H
