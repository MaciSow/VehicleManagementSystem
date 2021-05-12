#include "AddEditVehiclePage.h"

// public
AddEditVehiclePage::AddEditVehiclePage(MainController *controller, RenderWindow *window, const Font &font)
        : Page(controller, window, font) {
    create();
    createBtnBack();
    createBtnSave();
}

AddEditVehiclePage::~AddEditVehiclePage() = default;

void AddEditVehiclePage::draw() {
    prepare();
    drawBtnBack();
    drawBtnSave();

    for (Button *button : btnVehicleChoices) {
        button->drawTo(window);
    }

    for (Input *input : inputs) {
        input->drawTo(window);
    }

    for (Button *button : btnOptions) {
        if (!button->getIsHidden()) {
            button->drawTo(window);
        }
    }
}

bool AddEditVehiclePage::isMouseOver() {
    bool isCursorOver = false;
    if (!isEdit) {
        for (Button *button : btnVehicleChoices) {
            if (button->isMouseOver(window)) {
                isCursorOver = true;
            }
        }
    }
    for (Input *input : inputs) {
        if (input->isMouseOver(window)) {
            isCursorOver = true;
        }
    }

    for (Button *button : btnOptions) {
        if (button->isMouseOver(window)) {
            isCursorOver = true;
        }
    }

    if (handleBtnBackHover() || handleBtnSaveHover()) {
        isCursorOver = true;
    }
    return isCursorOver;
}

PageName AddEditVehiclePage::mouseClick() {
    for (Input *input : inputs) {
        input->checkSelection(window);
    }

    if (!isEdit) {
        for (Button *button : btnVehicleChoices) {
            if (button->isClick(window)) {
                changeVehicleChoice(button);
            }
        }
    }

    chooseMouseClick();

    if (handleBtnBackClick()) {
        if (isEdit) {
            clear();
            return PageName::vehicleData;
        }

        clear();
        return PageName::showVehicles;
    }

    if (btnSave->isClick(window)) {

    }

    if (handleBtnSaveClick()) {
        saveData();
        clear();
        return PageName::showVehicles;
    }

    return PageName::addEditVehicle;
}

void AddEditVehiclePage::textEntered(Event &event) {
    for (Input *input : inputs) {
        input->typeOn(event);
    }
    checkForm(inputs);
}

// private
void AddEditVehiclePage::create() {
    float btnWidth = 150;
    float btnPosX = width / 2;
    float btnPosY = height - 50 - 32;

    btnSave = new Button({32, btnPosY}, "Save", font, btnWidth);

    btnPosY = 110;

    btnVehicleChoices.push_back(
            new Button({btnPosX - 380 / 4 * 3 - btnWidth / 2, btnPosY}, "Car", font, btnWidth, 50, "Car"));
    btnVehicleChoices.push_back(
            new Button({btnPosX - 380 / 4 - btnWidth / 2, btnPosY}, "Bus", font, btnWidth, 50, "Bus"));
    btnVehicleChoices.push_back(
            new Button({btnPosX + 380 / 4 - btnWidth / 2, btnPosY}, "Van", font, btnWidth, 50, "Van"));
    btnVehicleChoices.push_back(
            new Button({btnPosX + 380 / 4 * 3 - btnWidth / 2, btnPosY}, "Truck", font, btnWidth, 50, "Truck"));

    btnVehicleChoices[0]->setActive(true);

    inputs.push_back(new Input({btnPosX - 360, 200}, font, "Plate:", 400));
    inputs.push_back(new Input({btnPosX - 360, 300}, font, "Brand:", 400));
    inputs.push_back(new Input({btnPosX - 360, 400}, font, "Model:", 400));
    inputs.push_back(new Input({btnPosX + 100, 200}, font, "Seats:", 260));
    inputs.push_back(new Input({btnPosX + 100, 300}, font, "Doors:", 260));
    inputs.push_back(new Input({btnPosX + 100, 400}, font, "Body style:", 260));

    btnOptions.push_back(new Button({btnPosX + 232, 300}, "_/", font, 64, 40));
    btnOptions.push_back(new Button({btnPosX + 296, 300}, "X", font, 64, 40));
    btnOptions.push_back(new Button({btnPosX + 232, 400}, "_/", font, 64, 40));
    btnOptions.push_back(new Button({btnPosX + 296, 400}, "X", font, 64, 40));

    btnOptions[0]->setActive(true);
    btnOptions[1]->setColor({0, 0, 0, 205}, {196, 55, 55, 205});
    btnOptions[2]->setActive(true);
    btnOptions[3]->setColor({0, 0, 0, 205}, {196, 55, 55, 205});

    clearBtnOptions();
    prepareBtnOptions();
}

void AddEditVehiclePage::prepare() {
    if (!isOpen) {
        isOpen = true;

        activeBtnSave();

        isEdit = controller->getSelectedVehicle();

        vehicleType = CAR;
        prepareVehicleChoice(btnVehicleChoices[0]);
        prepareInputs();

        if (isEdit) {
            fillInputs();
            disableVehicleChoice();
        }

        prepareBtnOptions();

    }
}

void AddEditVehiclePage::clear() {
    clearVehicleChoice();
    clearInputs();
    clearBtnOptions();

    isOpen = false;
    isEdit = false;

    blockBtnSave();
}

void AddEditVehiclePage::changeVehicleChoice(Button *&button) {
    prepareVehicleChoice(button);

    updateVehicleType();

    clearInputs();
    clearBtnOptions();

    prepareInputs();
    prepareBtnOptions();
}

void AddEditVehiclePage::prepareVehicleChoice(Button *&button) {
    for (Button *btnChoice : btnVehicleChoices) {
        btnChoice->setActive(false);
        btnChoice->isMouseOver(window);
    }
    button->setActive(true);
}

void AddEditVehiclePage::updateVehicleType() {
    for (Button *button : btnVehicleChoices) {
        if (button->getActive()) {
            if (button->getId() == "Car") {
                vehicleType = CAR;
            }

            if (button->getId() == "Bus") {
                vehicleType = BUS;
            }

            if (button->getId() == "Van") {
                vehicleType = VAN;
            }

            if (button->getId() == "Truck") {
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

void AddEditVehiclePage::prepareInputs() {
    string optionValue = "Yes";

    if (isEdit) {
        optionValue = "";
    }
    inputs[0]->setPattern("^[A-Z]{2,3}#[A-Z\\d]{4,5}$");

    switch (vehicleType) {
        case CAR:
            inputs[4]->setWidth(260);
            inputs[5]->setWidth(260);

            inputs[3]->setLabel("Seats:");
            inputs[4]->setLabel("Doors:");
            inputs[5]->setLabel("Body style:");

            inputs[3]->setPattern("^\\d{1}$");
            inputs[4]->setPattern("^\\d{1}$");
            inputs[5]->setPattern("^[A-Z]{1}[A-Za-z ]{2,}");
            break;
        case BUS:
            inputs[4]->setWidth(132);
            inputs[5]->setWidth(132);

            inputs[3]->setLabel("Seats:");
            inputs[4]->setLabel("Coach:");
            inputs[5]->setLabel("WC:");

            inputs[3]->setPattern("^\\d{1,2}$");

            inputs[4]->setValue(optionValue);
            inputs[4]->setIsEditable(false);
            inputs[5]->setValue(optionValue);
            inputs[5]->setIsEditable(false);
            break;
        case VAN:
            inputs[4]->setWidth(132);
            inputs[5]->setWidth(132);

            inputs[3]->setLabel("Capacity:");
            inputs[4]->setLabel("Double wheel:");
            inputs[5]->setLabel("Slide doors:");

            inputs[3]->setPattern("^\\d{5}$");

            inputs[4]->setValue(optionValue);
            inputs[4]->setIsEditable(false);
            inputs[5]->setValue(optionValue);
            inputs[5]->setIsEditable(false);
            break;
        case TRUCK:
            inputs[4]->setWidth(260);
            inputs[5]->setWidth(132);

            inputs[3]->setLabel("Capacity:");
            inputs[4]->setLabel("Axis:");
            inputs[5]->setLabel("Trailer:");

            inputs[3]->setPattern("^\\d{5}$");

            inputs[5]->setValue(optionValue);
            inputs[5]->setIsEditable(false);
            break;
        default:
            break;
    }
}

void AddEditVehiclePage::clearBtnOptions() {
    for (Button *button : btnOptions) {
        button->setIsHidden(true);
        button->setActive(false);
    }
}

void AddEditVehiclePage::prepareBtnOptions() {
    bool firstOption = true;
    bool secondOption = true;

    if (isEdit) {
        vehicleType = controller->getSelectedVehicle()->getVehicleType();

        firstOption = inputs[4]->getText() == "Yes";
        secondOption = inputs[5]->getText() == "Yes";
    }

    switch (vehicleType) {
        case CAR:
            break;
        case BUS:
        case VAN:
            for (Button *button : btnOptions) {
                button->setIsHidden(false);
            }

            btnOptions[0]->setActive(firstOption);
            btnOptions[1]->setActive(!firstOption);
            btnOptions[2]->setActive(secondOption);
            btnOptions[3]->setActive(!secondOption);
            break;
        case TRUCK:
            btnOptions[2]->setIsHidden(false);
            btnOptions[3]->setIsHidden(false);

            btnOptions[2]->setActive(secondOption);
            btnOptions[3]->setActive(!secondOption);
            break;
        default:
            break;
    }
}

void AddEditVehiclePage::chooseMouseClick() {
    if (btnOptions[0]->isClick(window)) {
        inputs[4]->clear();
        inputs[4]->setValue("Yes");
        btnOptions[1]->setActive(false);
        btnOptions[0]->setActive(true);
    }

    if (btnOptions[1]->isClick(window)) {
        inputs[4]->clear();
        inputs[4]->setValue("No");
        btnOptions[0]->setActive(false);
        btnOptions[1]->setActive(true);
    }

    if (btnOptions[2]->isClick(window)) {
        inputs[5]->clear();
        inputs[5]->setValue("Yes");
        btnOptions[3]->setActive(false);
        btnOptions[2]->setActive(true);
    }

    if (btnOptions[3]->isClick(window)) {
        inputs[5]->clear();
        inputs[5]->setValue("No");
        btnOptions[2]->setActive(false);
        btnOptions[3]->setActive(true);
    }
}

void AddEditVehiclePage::saveData() {
    vector<string> data;

    for (Input *input : inputs) {
        data.push_back(input->getText());
    }

    if (isEdit) {
        controller->editVehicle(data);
        return;
    }

    controller->createVehicle(data, vehicleType);
}

void AddEditVehiclePage::fillInputs() {
    vector<string> vehicleData = controller->getSelectedVehicle()->getVehicleAllData();

    inputs[0]->setValue(vehicleData[5]);
    inputs[1]->setValue(vehicleData[0]);
    inputs[2]->setValue(vehicleData[1]);
    inputs[3]->setValue(vehicleData[2]);
    inputs[4]->setValue(vehicleData[3]);
    inputs[5]->setValue(vehicleData[4]);
}

void AddEditVehiclePage::disableVehicleChoice() {
    for (Button *button : btnVehicleChoices) {
        if (controller->getSelectedVehicle()->getVehicleTypeName() != button->getId()) {
            button->setBlock();
        } else {
            button->setActive(true);
        }
    }
}

void AddEditVehiclePage::clearVehicleChoice() {
    for (Button *button : btnVehicleChoices) {
        button->setBlock(false);
    }
}