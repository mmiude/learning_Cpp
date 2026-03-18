//
// Created by Mmiud on 9/25/2025.
//

#ifndef COLOROBSERVER_H
#define COLOROBSERVER_H

#include "Observer.h"

class ColorObserver : public Observer {
public:
    ColorObserver() = default;
    void Update(std::string & title, int value) override;
};



#endif //COLOROBSERVER_H
