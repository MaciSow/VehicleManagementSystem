#include "AddEditDriverPage.h"

// public
AddEditDriverPage::AddEditDriverPage(MainController *controller, RenderWindow *window, const Font &font)
        : Page(controller, window, font) {
    create();
    createBtnBack();
    createBtnSave();
}

AddEditDriverPage::~AddEditDriverPage() = default;

void AddEditDriverPage::draw() {
    prepare();
    drawBtnBack();
    drawBtnSave();

    for (Input *input:inputs) {
        input->drawTo(window);
    }
}

bool AddEditDriverPage::isMouseOver() {
    bool isCursorOver = false;

    if (handleBtnBackHover() ||
        handleBtnSaveHover() ||
        inputs[0]->isMouseOver(window) ||
        inputs[1]->isMouseOver(window)) {
        isCursorOver = true;
    }

    return isCursorOver;
}

PageName AddEditDriverPage::mouseClick() {
    for (Input *input:inputs) {
        input->checkSelection(window);
    }

    if (handleBtnSaveClick()) {
        save();
        clear();
        return PageName::driverData;
    }

    if (handleBtnBackClick()) {
        if (isEdit) {
            clear();
            return PageName::driverData;
        }

        clear();
        return PageName::showDrivers;
    }

    return PageName::addEditDriver;
}

void AddEditDriverPage::textEntered(Event &event) {
    for (Input *input:inputs) {
        input->typeOn(event);
    }

    checkForm(inputs);
}

// private
void AddEditDriverPage::create() {
    float btnPosX = width / 2;
    float btnPosY = height / 2;

    inputs.push_back(new Input({btnPosX - 200, btnPosY - 76}, font, "Name", 400));
    inputs.push_back(new Input({btnPosX - 200, btnPosY + 24}, font, "Surname", 400));
}

void AddEditDriverPage::clear() {
    for (Input *input:inputs) {
        input->clear();
    }
    isOpen = false;
    blockBtnSave();
}


void AddEditDriverPage::save() {
    string name = inputs[0]->getText();
    string surname = inputs[1]->getText();

    if (isEdit) {
        controller->editDriver(name, surname);
    }
    controller->createDriver(name, surname);
}

void AddEditDriverPage::prepare() {
    if (!isOpen) {
        isOpen = true;
        inputs[0]->setPattern("^[A-Z]{1}[A-Za-z\\ ]+$");
        inputs[1]->setPattern("^[A-Z]{1}[A-Za-z\\ -]+$");

        isEdit = controller->getSelectedDriver();

        if (isEdit) {
            fillInputs();
        }
    }
}

void AddEditDriverPage::fillInputs() {
    vector<string> driverData = controller->getSelectedDriver()->getAllData();

    inputs[0]->setValue(driverData[0]);
    inputs[1]->setValue(driverData[1]);
}


