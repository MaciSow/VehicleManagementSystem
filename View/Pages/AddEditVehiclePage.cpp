#include "AddEditVehiclePage.h"

// private
void AddEditVehiclePage::create() {
    float btnWidth = 150;
    float btnPosX = width - btnWidth - 32;
    float btnPosY = height - 50 - 32;


    btnSave = new Button({32, btnPosY}, "Save", font, btnWidth);

    btnPosY = 110;

    vehicleChoice.push_back(
            new Button({width / 2 - 380 / 4 * 3 - btnWidth / 2, btnPosY}, "Car", font, btnWidth, 50, "car"));
    vehicleChoice.push_back(
            new Button({width / 2 - 380 / 4 - btnWidth / 2, btnPosY}, "Bus", font, btnWidth, 50, "bus"));
    vehicleChoice.push_back(
            new Button({width / 2 + 380 / 4 - btnWidth / 2, btnPosY}, "Van", font, btnWidth, 50, "van"));
    vehicleChoice.push_back(
            new Button({width / 2 + 380 / 4 * 3 - btnWidth / 2, btnPosY}, "Truck", font, btnWidth, 50, "truck"));

    vehicleChoice[0]->setActive(true);

    inputs.push_back(new Input({width / 2 - 360, 200}, font, "Plate:", 400));
    inputs.push_back(new Input({width / 2 - 360, 300}, font, "Brand:", 400));
    inputs.push_back(new Input({width / 2 - 360, 400}, font, "Model:", 400));
    inputs.push_back(new Input({width / 2 + 100, 200}, font, "Seats:", 260));
    inputs.push_back(new Input({width / 2 + 100, 300}, font, "Doors:", 260));
    inputs.push_back(new Input({width / 2 + 100, 400}, font, "BodyStyle:", 260));

    inputs[3]->setIsNumber();
    inputs[4]->setIsNumber();

    btnChoose.push_back(new Button({width / 2 + 232, 300}, "_/", font, 64, 40));
    btnChoose.push_back(new Button({width / 2 + 296, 300}, "X", font, 64, 40));
    btnChoose.push_back(new Button({width / 2 + 232, 400}, "_/", font, 64, 40));
    btnChoose.push_back(new Button({width / 2 + 296, 400}, "X", font, 64, 40));

    btnChoose[0]->setActive(true);
    btnChoose[1]->setColor({0, 0, 0, 205}, {196, 55, 55, 205});
    btnChoose[2]->setActive(true);
    btnChoose[3]->setColor({0, 0, 0, 205}, {196, 55, 55, 205});

    clearBtnChoose();
    prepareBtnChoose();
}

void AddEditVehiclePage::clear() {
    vehicleType = CAR;
    changeVehicle(vehicleChoice[0]);
    clearInputs();
    clearBtnChoose();
    prepareInputs();
    prepareBtnChoose();
}

// public
AddEditVehiclePage::AddEditVehiclePage(MainController *controller, RenderWindow *window, const Font &font) : Page(
        controller, window, font) {
    create();
    createBtnBack();
}

AddEditVehiclePage::~AddEditVehiclePage() {

}

void AddEditVehiclePage::textEntered(Event &event) {
    for (Input *input : inputs) {
        input->typeOn(event);
    }
}

bool AddEditVehiclePage::isMouseOver() {
    bool isCursorOver = false;

    for (Button *button : vehicleChoice) {
        if (button->isMouseOver(window)) {
            isCursorOver = true;
        }
    }

    for (Input *input : inputs) {
        if (input->isMouseOver(window)) {
            isCursorOver = true;
        }
    }

    for (Button *button : btnChoose) {
        if (button->isMouseOver(window)) {
            isCursorOver = true;
        }
    }

    if (btnSave->isMouseOver(window) ||
        handleBtnBackHover()) {
        isCursorOver = true;
    }
    return isCursorOver;
}

PageName AddEditVehiclePage::mouseClick() {
    if (btnSave->isClick(window)) {
        saveData();
        clear();
        return PageName::showVehicles;
    }

    for (Input *input : inputs) {
        input->checkSelection(window);
    }

    for (Button *button : vehicleChoice) {
        if (button->isClick(window)) {
            changeVehicle(button);
            checkVehicle();
            clearInputs();
            prepareInputs();
            clearBtnChoose();
            prepareBtnChoose();
        }
    }
    chooseMouseClick();

    if (handleBtnBackClick()) {
        clear();
        return PageName::showVehicles;
    }


    return PageName::addEditVehicle;
}

void AddEditVehiclePage::changeVehicle(Button *&button) {
    for (Button *button : vehicleChoice) {
        button->setActive(false);
        button->isMouseOver(window);
    }
    button->setActive(true);
}

void AddEditVehiclePage::draw() {
    drawBackBtn();
    btnSave->drawTo(window);

    for (Button *button : vehicleChoice) {
        button->drawTo(window);
    }

    for (Input *input : inputs) {
        input->drawTo(window);
    }

    for (Button *button : btnChoose) {
        if (!button->getIsHidden()) {
            button->drawTo(window);
        }
    }

}

void AddEditVehiclePage::checkVehicle() {
    for (Button *button : vehicleChoice) {
        if (button->getActive()) {
            if (button->getId() == "car") {
                vehicleType = CAR;
            }

            if (button->getId() == "bus") {
                vehicleType = BUS;
            }

            if (button->getId() == "van") {
                vehicleType = VAN;
            }

            if (button->getId() == "truck") {
                vehicleType = TRUCK;
            }
        }
    }
}

void AddEditVehiclePage::clearInputs() {
    for (Input *input : inputs) {
        input->clear();
        input->setIsEditable(true);
    }
}

void AddEditVehiclePage::clearBtnChoose() {
    for (Button *button : btnChoose) {
        button->setIsHidden(true);
        button->setActive(false);
    }
}

void AddEditVehiclePage::prepareInputs() {
    switch (vehicleType) {
        case CAR:
            inputs[4]->setWidth(260);
            inputs[5]->setWidth(260);

            inputs[3]->setLabel("Seats:");
            inputs[4]->setLabel("Doors:");
            inputs[5]->setLabel("Body style:");

            inputs[4]->setIsNumber();
            break;
        case BUS:
            inputs[4]->setWidth(132);
            inputs[5]->setWidth(132);

            inputs[3]->setLabel("Seats:");
            inputs[4]->setLabel("Coach:");
            inputs[5]->setLabel("WC:");

            inputs[4]->setIsNumber(false);

            inputs[4]->setValue("Yes");
            inputs[4]->setIsEditable(false);
            inputs[5]->setValue("Yes");
            inputs[5]->setIsEditable(false);
            break;
        case VAN:
            inputs[4]->setWidth(132);
            inputs[5]->setWidth(132);

            inputs[3]->setLabel("Capacity:");
            inputs[4]->setLabel("Double wheel:");
            inputs[5]->setLabel("Slide doors:");

            inputs[4]->setIsNumber(false);

            inputs[4]->setValue("Yes");
            inputs[4]->setIsEditable(false);
            inputs[5]->setValue("Yes");
            inputs[5]->setIsEditable(false);
            break;
        case TRUCK:
            inputs[4]->setWidth(260);
            inputs[5]->setWidth(132);

            inputs[3]->setLabel("Capacity:");
            inputs[4]->setLabel("Axis:");
            inputs[5]->setLabel("Trailer:");

            inputs[4]->setIsNumber();

            inputs[5]->setValue("Yes");
            inputs[5]->setIsEditable(false);
            break;
        default:
            break;
    }
}

void AddEditVehiclePage::prepareBtnChoose() {
    switch (vehicleType) {
        case CAR:
            break;
        case BUS:
        case VAN:
            for (Button *button : btnChoose) {
                button->setIsHidden(false);
            }

            btnChoose[0]->setActive(true);
            btnChoose[2]->setActive(true);
            break;
        case TRUCK:
            btnChoose[2]->setIsHidden(false);
            btnChoose[3]->setIsHidden(false);

            btnChoose[2]->setActive(true);
            break;
        default:
            break;
    }
}

void AddEditVehiclePage::chooseMouseClick() {
// todo: fix refresh hover btn after change choice

//    for (Button *button : btnChoose) {
//        if (!button->getIsHidden()) {
//            button->setActive(false);
//        }
//    };

    if (btnChoose[0]->isClick(window)) {
        inputs[4]->clear();
        inputs[4]->setValue("Yes");
        btnChoose[1]->setActive(false);
        btnChoose[0]->setActive(true);
    }

    if (btnChoose[1]->isClick(window)) {
        inputs[4]->clear();
        inputs[4]->setValue("No");
        btnChoose[0]->setActive(false);
        btnChoose[1]->setActive(true);
    }

    if (btnChoose[2]->isClick(window)) {
        inputs[5]->clear();
        inputs[5]->setValue("Yes");
        btnChoose[3]->setActive(false);
        btnChoose[2]->setActive(true);
    }

    if (btnChoose[3]->isClick(window)) {
        inputs[5]->clear();
        inputs[5]->setValue("No");
        btnChoose[2]->setActive(false);
        btnChoose[3]->setActive(true);
    }


}

void AddEditVehiclePage::saveData() {
    vector<string> data;

    for (Input *input : inputs) {
        data.push_back(input->getText());
    }
    controller->createVehicle(data, vehicleType);
}
