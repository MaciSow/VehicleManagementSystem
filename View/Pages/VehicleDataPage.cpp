#include "VehicleDataPage.h"

VehicleDataPage::VehicleDataPage(MainController *controller, RenderWindow *window, const Font &font) :
        controller(controller), window(window), font(font) {
    createElements();
    vehicle = controller->getSelectedVehicle();
}

VehicleDataPage::~VehicleDataPage() {
}

bool VehicleDataPage::isMouseOver() {
    bool isCursorOver = false;
    if (btnEdit->isMouseOver(window) ||
        btnDelete->isMouseOver(window) ||
        btnBack->isMouseOver(window) ||
        btnChangeStatus->isMouseOver(window) ||
        btnShowRegister->isMouseOver(window) ||
        btnShowRepairs->isMouseOver(window)) {
        isCursorOver = true;
    }
    return isCursorOver;
}

PageName VehicleDataPage::mouseClick() {
    if (btnEdit->isClick(window)) {
        clear();
        return PageName::showVehicles;
    }

    if (btnDelete->isClick(window)) {
        clear();
        return PageName::showVehicles;
    }

    if (btnBack->isClick(window)) {
        clear();
        return PageName::showVehicles;
    }

    if (btnChangeStatus->isClick(window)) {
        clear();
        return PageName::showVehicles;
    }

    if (btnShowRegister->isClick(window)) {
        clear();
        return PageName::showVehicles;
    }

    if (btnShowRepairs->isClick(window)) {
        clear();
        return PageName::showVehicles;
    }

    return PageName::vehicleData;
}

void VehicleDataPage::createElements() {
    float width = (float) (window->getSize().x);
    float height = (float) (window->getSize().y);
    float btnWidth = 150;
    float btnHeight = 32;
    float btnPosY = height - 50 - 32;
    float btnPosX = 100 + (760 / 4) * 3 - btnWidth / 2;
    float offset = btnHeight + 32;

    btnEdit = new Button({32, btnPosY}, "Edit", font, btnWidth);
    btnDelete = new Button({48 + btnWidth, btnPosY}, "Delete", font, btnWidth);
    btnBack = new Button({width - btnWidth - 32, btnPosY}, "Back", font, btnWidth);
    btnBack->setColor({0, 0, 0, 205}, {196, 55, 55, 205});

    btnPosY = height / 2 - 38;

    btnChangeStatus = new Button({btnPosX, btnPosY}, "Change status", font, btnWidth, btnHeight);
    btnShowRegister = new Button({btnPosX, btnPosY += offset}, "Show register", font, btnWidth, btnHeight);
    btnShowRepairs = new Button({btnPosX, btnPosY += offset}, "Show repairs", font, btnWidth, btnHeight);
}

void VehicleDataPage::draw() {
    fillData();
    btnEdit->drawTo(window);
    btnDelete->drawTo(window);
    btnBack->drawTo(window);

    btnChangeStatus->drawTo(window);
    btnShowRegister->drawTo(window);
    btnShowRepairs->drawTo(window);
}

void VehicleDataPage::clear() {

}

void VehicleDataPage::fillData() {
    float width = (float) (window->getSize().x);
    float posX;
    float posY = 60;
    float offset = 64;
    VehicleType vehicleType = controller->getSelectedVehicle()->getVehicleType();
    vector<String> labels = {"Brand", "Model", "Seats", "Doors", "Body", "Plate", "Status"};
    vector<string> values = controller->getSelectedVehicle()->getVehicleAllData();

    switch (vehicleType) {
        case BUS:
            labels[3] = "Coach";
            labels[4] = "WC";
            break;
        case VAN:
            labels[2] = "Capacity";
            labels[3] = "Double Wheels";
            labels[4] = "Slide Doors";
            break;
        case TRUCK:
            labels[2] = "Capacity";
            labels[3] = "Axis";
            labels[4] = "Trailer";
            break;
        default:
            break;

    }

    int labelsLength = labels.size();

    for (int i = 0; i < labelsLength; ++i) {
        Text item(labels[i] + ':', font, 22);
        Text value(values[i], font, 22);


        if (i < 5) {
            posX = 100 + 760 / 4;
        } else {
            posX = 100 + (760 / 4) * 3;
        }

        if (i == 5) {
            posY = 60;
        }

        item.setFillColor(Color::Black);
        item.setPosition({posX - item.getLocalBounds().width, posY += offset});

        value.setFillColor(Color::Black);
        value.setPosition({posX + 8, posY});

        window->draw(item);
        window->draw(value);
    }
}
