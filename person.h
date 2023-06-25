#pragma once

#ifndef PERSON_H
#define PERSON_H
#include<string>
#include <stdexcept>
class Person {
protected:
    const unsigned id;
    std::string name;
    std::string gender;
    std::string passwd;
    unsigned age;

private:

    static void validateAge(unsigned int age) {
        if (age <= 5 || age >= 100) {
            throw std::invalid_argument("Invalid age.");
        }
    };

public:
    // Parameterized constructor
    Person(unsigned id, const std::string& name,
           const std::string& gender, const std::string& password,
           unsigned age)
        : id(id), name(name), gender(gender), passwd(password), age(age) {
        validateAge(age);
    }

    // Copy constructor
    Person(const Person& other)
        : id(other.id), name(other.name), gender(other.gender),
        passwd(other.passwd), age(other.age){}

    // Copy assignment operator
    Person& operator=(const Person& other){
        if (this != &other) {
            //id = other.id;
            name = other.name;
            gender = other.gender;
            age = other.age;
        }
        return *this;
    }

    // Destructor
    virtual ~Person() noexcept {}

    // Accessor functions
    const std::string& getName() const { return name; }
    const std::string& getGender() const { return gender; }
    unsigned getId() const { return id; }
    const std::string& getPasswd() const { return passwd; }
    const unsigned& getAge() const {return age;}
    // Mutator functions
    void setName(const std::string& newName) { name = newName; }
    void setGender(const std::string& newGender) { gender = newGender; }
    void setPassword(const std::string& newPasswd) { passwd = newPasswd; }
    void setAge(unsigned newAge) { age = newAge; }
    //void setId(const std::string& newId) { id = newId; }

};




#endif
