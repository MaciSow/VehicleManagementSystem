#include "HomePage.h"

HomePage::HomePage(MainController *&controller, RenderWindow *&window, Font &font) {
    this->controller = controller;
    this->window = window;
    this->font = font;
    createElements();
}

HomePage::~HomePage() {
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
        return PageName::close; //TODO name page to in
    }

    if (btnExit->isClick(window)) {
        return PageName::close;
    }

    return PageName::home;
}


void HomePage::draw() {
    btnFleetState->drawTo(window);
    btnShowVehicles->drawTo(window);
    btnShowDriver->drawTo(window);
    btnExit->drawTo(window);
}

// private methods

void HomePage::createElements() {
    float posX = (float) (window->getSize().x / 2 - 125);
    float posY = 150;
    int offset = 80;

    btnFleetState = new Button({posX, posY}, "Fleet state", font);
    btnShowVehicles = new Button({posX, posY += offset}, "Show vehicles", font);
    btnShowDriver = new Button({posX, posY += offset}, "Show drivers", font);
    btnExit = new Button({posX, posY += offset}, "Exit", font);
    btnExit->setColor({0, 0, 0, 205}, {196, 55, 55, 205});
}