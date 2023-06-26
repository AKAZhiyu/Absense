#include "Tea.h"
Tea::Tea(unsigned id, const std::string& name,
         const std::string& gender, const std::string& password,
         unsigned age, const std::string& position,
         const std::string& faculty)
    : Person(id, name, gender, password, age),
    position(position), faculty(faculty) {}

Tea::Tea(const Tea& other)
    : Person(other), position(other.position),
    faculty(other.faculty){}

// Copy assignment operator
Tea& Tea::operator=(const Tea& other) {
    if (this != &other) {
        Person::operator=(other);
        position = other.position;
        faculty = other.faculty;
    }
    return *this;
}

// Destructor
Tea::~Tea() noexcept {}

// Accessor function
const std::string& Tea::getPosition() const { return position; }

const std::string& Tea::getFaculty() const { return faculty; }
// Mutator function
void Tea::setPosition(const std::string& newPosition) { position = newPosition; }

void Tea::setFaculty(const std::string &newFaculty) {faculty = newFaculty; }

std::string Tea::getTable() const {
    return std::string("Teachers");
}
