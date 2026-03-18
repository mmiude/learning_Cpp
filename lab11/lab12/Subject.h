//
// Created by Mmiud on 9/26/2025.
//

#ifndef SUBJECT_H
#define SUBJECT_H
#include <memory>
#include "Observer.h"

class Subject {
public:
    virtual ~Subject() = default;
    virtual void Attach(std::shared_ptr<Observer> o) = 0;
    virtual void Notify() = 0;
};



#endif //SUBJECT_H
