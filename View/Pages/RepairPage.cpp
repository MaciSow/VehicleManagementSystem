#include "RepairPage.h"

// public
RepairPage::RepairPage(MainController *controller, RenderWindow *window, const Font &font)
        : Page(controller, window, font) {
    create();
    createBtnBack();
    createBtnSave();
}

RepairPage::~RepairPage() = default;

void RepairPage::draw() {
    drawBtnBack();
    drawBtnSave();
    createSeparator();

    prepare();

    btnRepairNow->drawTo(window);
    input->drawTo(window);
}

bool RepairPage::isMouseOver() {
    bool isCursorOver = false;

    if (handleBtnBackHover() ||
        handleBtnSaveHover() ||
        input->isMouseOver(window) ||
        btnRepairNow->isMouseOver(window)) {
        isCursorOver = true;
    }

    return isCursorOver;
}

PageName RepairPage::mouseClick() {
    input->checkSelection(window);

    if (btnRepairNow->isClick(window)) {
        btnRepairNow->setActive(true);
        input->clear();
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
    return PageName::repair;
}

void RepairPage::textEntered(Event &event) {
    input->typeOn(event);
    if (btnRepairNow->getActive()) {
        btnRepairNow->setActive(false);
    }
    checkChoice();
}

// private
void RepairPage::create() {
    float btnPosX = width / 2;
    float btnPosY = height / 2 - 16;

    input = new Input({btnPosX - 125, btnPosY - 84}, font, "How long it will take", 250);

    btnRepairNow = new Button({btnPosX - 125, btnPosY + 42}, "Repair it now", font);

    RectangleShape line({100, 2});
    line.setFillColor({136, 136, 136, 255});
    line.move(btnPosX - 116, btnPosY);

}

void RepairPage::clear() {
    btnRepairNow->setActive(false);
    input->setLabel("How long it will take");
    input->clear();

    isOpen = false;
    blockBtnSave();
}

void RepairPage::createSeparator() {
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

void RepairPage::checkChoice() {
    if (btnRepairNow->getActive() || input->getText().length()) {
        activeBtnSave();
    }
}

void RepairPage::save() {
    if (btnRepairNow->getActive()) {
        controller->setRepair(0);
        return;
    }

    int takeTime = stoi(input->getText());
    controller->setRepair(takeTime);
}

void RepairPage::prepare() {
    if (!isOpen) {
        isOpen = true;
        Status *status = controller->getSelectedVehicle()->getStatus();
        input->setPattern("^\\d{1,2}$");

        if (status->getStatusType() == REPAIR) {
            string stringDate = status->getData()[2];
            Date* date = new Date(stringDate);

            input->setLabel("How long it will take yet");
            input->setValue(to_string(date->getDay()));
        }
    }
}

