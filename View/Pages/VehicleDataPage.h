#ifndef VEHICLEMENAGMENTSYSTEM_VEHICLEDATAPAGE_H
#define VEHICLEMENAGMENTSYSTEM_VEHICLEDATAPAGE_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../../Controller/MainController.h"
#include "PageName.h"
#include "../Elements/Button.h"

using namespace std;
using namespace sf;

class VehicleDataPage {
private:
    MainController *controller;
    RenderWindow *window;
    Font font;
    Vehicle* vehicle;

    Button *btnBack;

    void createElements();

    void clear();

public:
    VehicleDataPage(MainController *controller, RenderWindow *window, const Font &font);

    ~VehicleDataPage();

    bool isMouseOver();

    PageName mouseClick();

    void draw();
};


#endif //VEHICLEMENAGMENTSYSTEM_VEHICLEDATAPAGE_H
