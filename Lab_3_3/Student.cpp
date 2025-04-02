#include "Student.h"
#include <cmath>
#include <sstream>

Student::Student() : Human(), scores() {
}

Student::Student(const std::string &firstName, const std::string &lastName,
                 const std::string &patronymic, const std::vector<int> &scores)
    : Human(firstName, lastName, patronymic), scores(scores) {
}

void Student::addScore(int score) {
    scores.push_back(score);
}

double Student::getAverageScore() const {
    if (scores.empty()) return 0.0;
    int sum = 0;
    for (int score: scores) {
        sum += score;
    }

    return round(static_cast<double>(sum) / scores.size() * 100) / 100;
}

std::string Student::getShortStudentInfo() const {
    std::ostringstream oss;
    oss << getSurnameAndInitials() << ": " << getAverageScore();
    return oss.str();
}

std::string Student::getFullStudentInfo() const {
    if (scores.empty()) {
        return getFullName() + ": нет оценок";
    }

    std::string result = getFullName() + ": ";
    for (size_t i = 0; i < scores.size(); ++i) {
        if (i != 0) result += " ";
        result += std::to_string(scores[i]);
    }


    double avg = getAverageScore();
    char buffer[32];
    snprintf(buffer, sizeof(buffer), " - %.2f", avg);
    result += buffer;

    return result;
}

size_t Student::getScoresCount() const {
    return scores.size();
}

const std::vector<int> &Student::getScores() const {
    return scores;
}
