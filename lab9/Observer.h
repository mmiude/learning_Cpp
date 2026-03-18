//
// Created by Mmiud on 9/16/2025.
//

#ifndef OBSERVER_H
#define OBSERVER_H

class Observer;
class Subject {
public:
    virtual ~Subject() = default;

    virtual void Attach(Observer *o) = 0;
    virtual void Notify() = 0;
};

class Observer {
public:
    virtual ~Observer() = default;

    virtual void Update() = 0;
};



#endif //OBSERVER_H
