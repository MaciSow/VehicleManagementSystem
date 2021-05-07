#include "AvailablePage.h"

// public
AvailablePage::AvailablePage(MainController *controller, RenderWindow *window, const Font &font)
        : Page(controller, window, font) {
    create();
    createBtnBack();
    createBtnSave();
}

AvailablePage::~AvailablePage() = default;

void AvailablePage::draw() {
    drawBtnBack();
    drawBtnSave();
    createSeparator();

    btnReturn->drawTo(window);
    btnStop->drawTo(window);
}

bool AvailablePage::isMouseOver() {
    bool isCursorOver = false;

    if (handleBtnBackHover() || handleBtnSaveHover() ||
        btnReturn->isMouseOver(window) ||
        btnStop->isMouseOver(window)) {
        isCursorOver = true;
    }

    return isCursorOver;
}

PageName AvailablePage::mouseClick() {
    if (btnReturn->isClick(window)) {
        btnStop->setActive(false);
        btnReturn->setActive(true);
    }

    if (btnStop->isClick(window)) {
        btnReturn->setActive(false);
        btnStop->setActive(true);
    }

    if (handleBtnSaveClick()) {
        controller->setAvailable(btnStop->getActive());
        clear();
        return PageName::vehicleData;
    }

    checkChoice();

    if (handleBtnBackClick()) {
        clear();
        return PageName::changeStatus;
    }
    return PageName::available;
}

// private
void AvailablePage::create() {
    float btnPosX = width / 2;
    float btnPosY = height / 2 - 16;

    btnReturn = new Button({btnPosX - 125, btnPosY - 84}, "Return from road", font);
    btnStop = new Button({btnPosX - 125, btnPosY + 42}, "Stop journey now", font);

    RectangleShape line({100, 2});
    line.setFillColor({136, 136, 136, 255});
    line.move(btnPosX - 116, btnPosY);

}

void AvailablePage::clear() {
    btnReturn->setActive(false);
    btnStop->setActive(false);
    blockBtnSave();
}

void AvailablePage::createSeparator() {
    float posX = width / 2;
    float posY = height / 2 - 12;

    RectangleShape lineLeft({100, 2});
    lineLeft.setFillColor({136, 136, 136, 255});
    lineLeft.move(posX - 124, posY);

    RectangleShape lineRight({100, 2});
    lineRight.setFillColor({136, 136, 136, 255});
    lineRight.move(posX + 24, posY);

    Text text("OR", font, 18);
    text.setFillColor({136, 136, 136, 255});
    text.setPosition({posX - text.getLocalBounds().width / 2, posY - text.getLocalBounds().height + 2});

    window->draw(lineRight);
    window->draw(lineLeft);
    window->draw(text);
}

void AvailablePage::checkChoice() {
    if (btnReturn->getActive() || btnStop->getActive()) {
        activeBtnSave();
    }
}

