#include "HomePage.h"

// public
HomePage::HomePage(MainController *controller, RenderWindow *window, const Font &font)
        : Page(controller, window, font) {
    create();
}

HomePage::~HomePage() = default;

void HomePage::draw() {
    btnFleetState->drawTo(window);
    btnShowVehicles->drawTo(window);
    btnShowDriver->drawTo(window);
    btnExit->drawTo(window);
}

bool HomePage::isMouseOver() {
    bool isCursorOver = false;

    if (btnFleetState->isMouseOver(window) ||
        btnShowVehicles->isMouseOver(window) ||
        btnShowDriver->isMouseOver(window) ||
        btnExit->isMouseOver(window)) {
        isCursorOver = true;
    }
    return isCursorOver;
}

PageName HomePage::mouseClick() {

    if (btnFleetState->isClick(window)) {
        return PageName::fleetState;
    }

    if (btnShowVehicles->isClick(window)) {
        return PageName::showVehicles;
    }

    if (btnShowDriver->isClick(window)) {
        return PageName::showDrivers;
    }

    if (btnExit->isClick(window)) {
        return PageName::close;
    }

    return PageName::home;
}

// private
void HomePage::create() {
    auto posX = (float) (width / 2 - 125);
    float posY = 150;
    float offset = 80;

    btnFleetState = new Button({posX, posY}, "Fleet state", font);
    btnShowVehicles = new Button({posX, posY += offset}, "Show vehicles", font);
    btnShowDriver = new Button({posX, posY += offset}, "Show drivers", font);
    btnExit = new Button({posX, posY += offset}, "Exit", font);
    btnExit->setColor({0, 0, 0, 205}, {196, 55, 55, 205});
}

void HomePage::clear() {
}
