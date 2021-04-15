#include "HomePage.h"

HomePage::HomePage(MainController*& controller, RenderWindow*& window, Font& font) {
    this->controller = controller;
    this->window = window;
    this->font = font;
    createElements();
}

HomePage::~HomePage() {
}

bool HomePage::isMouseOver() {
    bool isCursorOver = false;

    if (btnExit->isMouseOver(window)) {
        isCursorOver = true;
    }

    return isCursorOver;
}

PageName HomePage::mouseClick() {

    if (btnExit->isClick(window)) {
        return PageName::close;
    }

    return PageName::home;
}


void HomePage::draw() {
    btnExit->drawTo(window);
}

// private methods

void HomePage::createElements() {
    float posx = (float)(window->getSize().x / 2 - 125);
    float posY = 150;
    int offset = 80;

    btnExit = new Button({ posx, posY += offset }, "EXIT", font);
    btnExit->setColor({ 0, 0, 0, 205 }, { 196, 55, 55, 205 });
}