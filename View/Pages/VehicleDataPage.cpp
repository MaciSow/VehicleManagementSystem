#include "VehicleDataPage.h"

// public
VehicleDataPage::VehicleDataPage(MainController *controller, RenderWindow *window, const Font &font)
        : Page(controller, window, font) {
    create();
    createBtnBack();
    vehicle = controller->getSelectedVehicle();
}

VehicleDataPage::~VehicleDataPage() = default;

void VehicleDataPage::draw() {
    drawBtnBack();
    fillData();

    btnEdit->drawTo(window);
    btnDelete->drawTo(window);
    btnChangeStatus->drawTo(window);
    btnShowRegister->drawTo(window);
    btnShowRepairs->drawTo(window);
}

bool VehicleDataPage::isMouseOver() {
    bool isCursorOver = false;

    if (handleBtnBackHover() ||
        btnEdit->isMouseOver(window) ||
        btnDelete->isMouseOver(window) ||
        btnChangeStatus->isMouseOver(window) ||
        btnShowRegister->isMouseOver(window) ||
        btnShowRepairs->isMouseOver(window)) {
        isCursorOver = true;
    }

    return isCursorOver;
}

PageName VehicleDataPage::mouseClick() {
    if (btnEdit->isClick(window)) {
        return PageName::addEditVehicle;
    }

    if (btnDelete->isClick(window)) {
        controller->deleteVehicle();
        clear();
        return PageName::showVehicles;
    }

    if (btnChangeStatus->isClick(window)) {
        return PageName::changeStatus;
    }

    if (btnShowRegister->isClick(window)) {
        return PageName::showRegister;
    }

    if (btnShowRepairs->isClick(window)) {
        return PageName::showRepairs;
    }

    if (handleBtnBackClick()) {
        clear();
        return PageName::showVehicles;
    }

    return PageName::vehicleData;
}

// private
void VehicleDataPage::create() {
    float btnWidth = 150;
    float btnHeight = 32;
    float btnPosY = height - 50 - 32;
    float btnPosX = 100 + (760 / 4) * 3 - btnWidth / 2;
    float offset = btnHeight + 32;

    btnEdit = new Button({32, btnPosY}, "Edit", font, btnWidth);
    btnDelete = new Button({48 + btnWidth, btnPosY}, "Delete", font, btnWidth);

    btnPosY = height / 2 - 38;

    btnChangeStatus = new Button({btnPosX, btnPosY}, "Change status", font, btnWidth, btnHeight);
    btnShowRegister = new Button({btnPosX, btnPosY += offset}, "Show register", font, btnWidth, btnHeight);
    btnShowRepairs = new Button({btnPosX, btnPosY += offset}, "Show repairs", font, btnWidth, btnHeight);
}

void VehicleDataPage::clear() {
    controller->unselectVehicle();
}

void VehicleDataPage::fillData() {
    float posX;
    float posY = 60;
    float offset = 64;
    VehicleType vehicleType = controller->getSelectedVehicle()->getVehicleType();
    vector<string> labels = {"Brand", "Model", "Seats", "Doors", "Body", "Plate", "Status"};
    vector<string> values = controller->getSelectedVehicle()->getVehicleAllData();

    switch (vehicleType) {
        case BUS:
            labels[3] = "Coach";
            labels[4] = "WC";
            break;
        case VAN:
            labels[2] = "Capacity";
            values[2] += " kg";
            labels[3] = "Double Wheels";
            labels[4] = "Slide Doors";
            break;
        case TRUCK:
            labels[2] = "Capacity";
            values[2] += " kg";
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

        value.setFillColor(i == 6 ? getStatusColor(values[6]) : Color::Black);
        value.setPosition({posX + 8, posY});

        window->draw(item);
        window->draw(value);
    }
}

Color VehicleDataPage::getStatusColor(string status) {
    if (status == "Available") {
        return {5, 128, 10, 255};
    }

    if (status == "Broke down") {
        return {175, 28, 28, 255};
    }

    if (status == "In repair") {
        return {223, 134, 0, 255};
    }

    return {0, 0, 0, 255};
}