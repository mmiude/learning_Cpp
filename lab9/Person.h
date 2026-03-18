//
// Created by Mmiud on 9/11/2025.
//

#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person {
public:
    explicit Person(const char* name = "nobody");
    virtual ~Person() = default;
    virtual void identity();
    virtual void interrogate();
private:
    std::string name;
};


#endif //PERSON_H
