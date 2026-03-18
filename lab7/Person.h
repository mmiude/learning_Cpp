//
// Created by Mmiud on 9/11/2025.
//

#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person {
public:
    Person(const char* name = "nobody");
    virtual ~Person() = default;
    virtual void identity() const;
    virtual void interrogate();
private:
    std::string name;
};

class Spy : public Person {
public:
    Spy(const char* name, const char* alias, int resistance);
    void set_identity(const char* newAlias);
    void identity() const override;
    void interrogate() override;
private:
    std::string alias;
    int resistance;
};


#endif //PERSON_H
