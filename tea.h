#pragma once
#include "Person.h"
#ifndef TEA_H
#define TEA_H

class Tea: public Person {

protected:
    std::string position;
    std::string faculty;

public:
    Tea(unsigned id, const std::string& name,
        const std::string& gender, const std::string& password,
        unsigned age, const std::string& position,
        const std::string& faculty);

    Tea(const Tea& other);

    Tea& operator=(const Tea& other);

    virtual ~Tea() noexcept;

    const std::string& getPosition() const;

    const std::string& getFaculty() const;

    void setPosition(const std::string& newPosition);

    void setFaculty(const std::string& newFaculty);

};

#endif // !TEACHER_H
