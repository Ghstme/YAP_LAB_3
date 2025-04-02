#include "Teacher.h"

Teacher::Teacher() : Human(), position(Position::UNKNOWN), subjects() {
}

Teacher::Teacher(const std::string &firstName, const std::string &lastName,
                 const std::string &patronymic, Position position,
                 const std::vector<std::string> &subjects)
    : Human(firstName, lastName, patronymic), position(position), subjects(subjects) {
}

void Teacher::addSubject(const std::string &subject) {
    subjects.push_back(subject);
}

std::string Teacher::getShortTeacherInfo() const {
    return getSurnameAndInitials() + " " + positionToString(position)
           + ": " + std::to_string(subjects.size());
}

std::string Teacher::getFullTeacherInfo() const {
    std::string result = getFullName() + " " + positionToString(position) + ": ";
    for (size_t i = 0; i < subjects.size(); ++i) {
        if (i != 0) result += ", ";
        result += subjects[i];
    }
    return result;
}

size_t Teacher::getSubjectsCount() const {
    return subjects.size();
}

Position Teacher::getPosition() const {
    return position;
}

bool Teacher::teachesSubject(const std::string &subject) const {
    for (const auto &subj: subjects) {
        if (subj == subject) return true;
    }
    return false;
}

std::string Teacher::positionToString(Position pos) {
    switch (pos) {
        case Position::ASSISTANT: return "ассистент";
        case Position::SENIOR_LECTURER: return "старший преподаватель";
        case Position::DOCENT: return "доцент";
        case Position::PROFESSOR: return "профессор";
        default: return "неизвестно";
    }
}

Position Teacher::stringToPosition(const std::string &pos) {
    if (pos == "ассистент") return Position::ASSISTANT;
    if (pos == "старший преподаватель") return Position::SENIOR_LECTURER;
    if (pos == "доцент") return Position::DOCENT;
    if (pos == "профессор") return Position::PROFESSOR;
    return Position::UNKNOWN;
}
