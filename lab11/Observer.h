//
// Created by Mmiud on 9/25/2025.
//

#ifndef OBSERVER_H
#define OBSERVER_H


class Observer {
public:
    virtual ~Observer() = default;
    virtual void Update(std::string & title, int value) = 0;
};



#endif //OBSERVER_H
