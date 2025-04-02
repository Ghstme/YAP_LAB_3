#ifndef STUDENT_H
#define STUDENT_H
#include "Human.h"
#include <vector>

class Student : public Human {
    std::vector<int> scores;

public:
    Student();
    Student(const std::string& firstName, const std::string& lastName,
            const std::string& patronymic, const std::vector<int>& scores);

    void addScore(int score);
    double getAverageScore() const;
    std::string getShortStudentInfo() const;
    std::string getFullStudentInfo() const;
    size_t getScoresCount() const;
    const std::vector<int>& getScores() const;
};
#endif //STUDENT_H
