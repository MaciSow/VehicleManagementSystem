#ifndef VEHICLEMENAGMENTSYSTEM_FLEETSTATEPAGE_H
#define VEHICLEMENAGMENTSYSTEM_FLEETSTATEPAGE_H

#include <SFML/Graphics.hpp>
#include "../Elements/Button.h"
#include "../../Controller/MainController.h"
#include "PageName.h"
#include "iostream"

using namespace std;
using namespace sf;

class FleetStatePage {
private:
    MainController *controller;
    RenderWindow *window;
    Font font;

    Button *btnBack;

    void createElements();

    void clear();

public:
    FleetStatePage(MainController *controller, RenderWindow *window, const Font &font);

    ~FleetStatePage();

    bool isMouseOver();

    PageName mouseClick();

    void draw();

    void fillState();
};


#endif //VEHICLEMENAGMENTSYSTEM_FLEETSTATEPAGE_H
