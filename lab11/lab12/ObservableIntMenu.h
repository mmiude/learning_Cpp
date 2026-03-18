//
// Created by Mmiud on 9/25/2025.
//

#ifndef OBSERVABLEINTMENU_H
#define OBSERVABLEINTMENU_H

#include <vector>
#include <memory>

#include "IntEdit.h"
#include "Observer.h"
#include "Subject.h"

class ObservableIntMenu : public IntEdit, public Subject {
public:
    explicit ObservableIntMenu(std::string menu_title);
    void Attach(std::shared_ptr<Observer> o) override;
    void Notify() override;
    bool event(menuEvent e) override;

private:
    std::vector<std::shared_ptr<Observer>> observers;
};



#endif //OBSERVABLEINTMENU_H
