#ifndef TEACHER_H
#define TEACHER_H
#include "Human.h"
#include <vector>
#include <string>

enum class Position {
    UNKNOWN,
    ASSISTANT,
    SENIOR_LECTURER,
    DOCENT,
    PROFESSOR
};

class Teacher : public Human {
    Position position;
    std::vector<std::string> subjects;

public:
    Teacher();

    Teacher(const std::string &firstName, const std::string &lastName,
            const std::string &patronymic, Position position,
            const std::vector<std::string> &subjects);

    const std::vector<std::string> &getSubjects() const { return subjects; }

    void addSubject(const std::string &subject);

    std::string getShortTeacherInfo() const;

    std::string getFullTeacherInfo() const;

    size_t getSubjectsCount() const;

    Position getPosition() const;

    bool teachesSubject(const std::string &subject) const;

    static std::string positionToString(Position pos);

    static Position stringToPosition(const std::string &pos);
};
#endif //TEACHER_H
