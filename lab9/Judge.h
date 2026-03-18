//
// Created by Mmiud on 9/16/2025.
//

#ifndef JUDGE_H
#define JUDGE_H
#include "Observer.h"
#include "Person.h"


class Judge : public Person, public Observer {
public:
    explicit Judge(const char* name);
    void Update() override;
};



#endif //JUDGE_H
