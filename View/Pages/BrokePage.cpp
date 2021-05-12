#include "BrokePage.h"

// public
BrokePage::BrokePage(MainController *controller, RenderWindow *window, const Font &font)
        : Page(controller, window, font) {
    create();
    createBtnBack();
    createBtnSave();
}

BrokePage::~BrokePage() = default;

void BrokePage::draw() {
    if(!isOpen){
        isOpen = true;
        inputs[0]->setPattern("^[A-Za-z\\ ]+$");
        inputs[1]->setPattern("^[A-Za-z\\d]{0,1}[A-Za-z\\d\\ ]*$");
    }

    drawBtnBack();
    drawBtnSave();

    for (Input *input:inputs) {
        input->drawTo(window);
    }
}

bool BrokePage::isMouseOver() {
    bool isCursorOver = false;

    if (handleBtnBackHover() ||
        handleBtnSaveHover() ||
        inputs[0]->isMouseOver(window) ||
        inputs[1]->isMouseOver(window)) {
        isCursorOver = true;
    }

    return isCursorOver;
}

PageName BrokePage::mouseClick() {
    for (Input *input:inputs) {
        input->checkSelection(window);
    }

    if (handleBtnSaveClick()) {
        save();
        clear();
        return PageName::vehicleData;
    }

    if (handleBtnBackClick()) {
        clear();
        return PageName::changeStatus;
    }

    checkChoice();
    return PageName::broke;
}

void BrokePage::textEntered(Event &event) {
    for (Input *input:inputs) {
        input->typeOn(event);
    }

    checkChoice();
}

// private
void BrokePage::create() {
    float btnPosX = width / 2;
    float btnPosY = height / 2 - 16;

    inputs.push_back(new Input({btnPosX - 200, btnPosY - 84}, font, "What broke", 400));
    inputs.push_back(new Input({btnPosX - 200, btnPosY}, font, "Description", 400, 80));

    RectangleShape line({100, 2});
    line.setFillColor({136, 136, 136, 255});
    line.move(btnPosX - 116, btnPosY);
}

void BrokePage::clear() {
    for (Input *input:inputs) {
        input->clear();
    }
    isOpen = false;
    blockBtnSave();
}


void BrokePage::checkChoice() {
    if (inputs[0]->getText().length()) {
        activeBtnSave();
    }
}

void BrokePage::save() {
    string name = inputs[0]->getText();
    string description = inputs[1]->getText();

    controller->setBroke(name, description);
}


