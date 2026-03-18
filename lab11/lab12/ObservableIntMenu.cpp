//
// Created by Mmiud on 9/25/2025.
//

#include <iostream>
#include "ObservableIntMenu.h"

ObservableIntMenu::ObservableIntMenu(std::string menu_title) : IntEdit(menu_title) {

}

void ObservableIntMenu::Attach(std::shared_ptr<Observer> o) {
    observers.push_back(o);
}

void ObservableIntMenu::Notify() {
    std::string title = MenuItem::title();
    for (const auto& o : observers) o->Update(title, value);
}

bool ObservableIntMenu::event(menuEvent e) {
    if ( e == MenuItem::ok && changed) Notify();
    return IntEdit::event(e);
}

