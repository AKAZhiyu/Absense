#pragma once

#ifndef STUD_H
#define STUD_H
#include "Person.h"
class Stud: public Person {
protected:
    std::string student_class;
    std::string major;

public:
    Stud(unsigned id, const std::string& name,
        const std::string& gender, const std::string password,
        unsigned age, const std::string& _class,
        const std::string major);

    Stud(const Stud& other);

    Stud& operator=(const Stud& other);

    virtual ~Stud() noexcept;

    const std::string& getClass() const;
    const std::string& getMajor() const;


    void setClass(const std::string& new_class);
    void setMajor(const std::string& new_major);

    virtual std::string getTable() const;
};

#endif // !STUD_H
