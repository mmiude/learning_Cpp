#include <cstdlib>

#include <iostream>

#include "ColorObserver.h"
#include "Menu.h"
#include "IntEdit.h"
#include "ObservableIntMenu.h"


int main(int argc, char **argv) {

    auto ColorObs = std::make_shared<ColorObserver>();
    auto red = std::make_shared<ObservableIntMenu>("Red");
    auto blue = std::make_shared<ObservableIntMenu>("Blue");
    auto green = std::make_shared<ObservableIntMenu>("Green");

    red->Attach(ColorObs);
    blue->Attach(ColorObs);
    green->Attach(ColorObs);

    auto sub_menu = std::make_shared<Menu>("Colors");
    sub_menu->add_item(red);
    sub_menu->add_item(blue);
    sub_menu->add_item(green);

    auto main_menu = std::make_shared<Menu>("Main menu");
    main_menu->add_item(std::make_shared<IntEdit>("Speed"));
    main_menu->add_item(std::make_shared<IntEdit>("Target"));
    main_menu->add_item(std::make_shared<IntEdit>("Sound"));
    main_menu->add_item(sub_menu);

    //main_menu->add_item(std::make_shared<Menu>("Testing empty menu"));

    main_menu->show();

    std::string s;
    do {
        std::cin >> s;
        if(s[0]=='+') main_menu->event(MenuItem::up);
        if(s[0]=='-') main_menu->event(MenuItem::down);
        if(s[0]=='<') main_menu->event(MenuItem::back);
        if(s[0]=='o') main_menu->event(MenuItem::ok);
    } while(s[0] != 'q');


	return 0;
}


