#include "BasePage.h"

BasePage::BasePage(MainController *controller, RenderWindow *window, const Font &font) :
        controller(controller), window(window), font(font) {
    createElements();
}

BasePage::~BasePage() {
}

bool BasePage::isMouseOver() {
    bool isCursorOver = false;
    if (btnBack->isMouseOver(window)) {
        isCursorOver = true;
    }
    return isCursorOver;
}

PageName BasePage::mouseClick() {
    if (btnBack->isClick(window)) {
        clear();
        return PageName::home;
    }
    return PageName::vehicleData;
}

void BasePage::createElements() {
    float width = (float) (window->getSize().x);
    float height = (float) (window->getSize().y);
    float btnWidth = 150;
    float btnPosX = width - btnWidth - 32;
    float btnPosY = height - 50 - 32;

    btnBack = new Button({btnPosX, btnPosY}, "Back", font, btnWidth);
    btnBack->setColor({0, 0, 0, 205}, {196, 55, 55, 205});
}

void BasePage::draw() {
    btnBack->drawTo(window);
}

void BasePage::clear() {

}