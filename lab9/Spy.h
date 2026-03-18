//
// Created by Mmiud on 9/16/2025.
//

#ifndef SPY_H
#define SPY_H

#include <vector>
#include "Observer.h"
#include "Person.h"

class Spy : public Person , public Subject {
public:
    Spy(const char* name, const char* alias, int resistance);
    void set_identity(const char* newAlias);
    void identity() override;
    void interrogate() override;
    void Attach(Observer *o) override;
    void Notify() override;
private:
    std::string alias;
    int resistance;
    std::vector<Observer*> judges;
};

#endif //SPY_H
