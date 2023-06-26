#include "Stud.h"
Stud::Stud(unsigned id, const std::string& name,
         const std::string& gender, const std::string password,
         unsigned age, const std::string& _class,
         const std::string major):
    Person(id, name, gender, password, age),
    student_class(_class), major(major){}

Stud::Stud(const Stud& other): Person(other),
    student_class(other.student_class), major(other.major){}

Stud& Stud::operator=(const Stud& other) {
    if (this != &other) {
        Person::operator=(other);
        student_class = other.student_class;
        major = other.major;
    }
    return *this;
}

Stud::~Stud() noexcept {}

const std::string& Stud::getClass() const {
    return student_class;
}

const std::string& Stud::getMajor() const {
    return major;
}


void Stud::setClass(const std::string& new_class) {
    student_class = new_class;
}

void Stud::setMajor(const std::string &new_major) {
    major = new_major;
}

std::string Stud::getTable() const {
    return std::string("Students");
}
