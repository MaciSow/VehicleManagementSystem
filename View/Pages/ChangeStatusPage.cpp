#include "ChangeStatusPage.h"

// public
ChangeStatusPage::ChangeStatusPage(MainController *controller, RenderWindow *window, const Font &font)
        : Page(controller, window, font) {
    create();
    createBtnBack();
}

ChangeStatusPage::~ChangeStatusPage() = default;

void ChangeStatusPage::draw() {
    setBtnBlock();

    btnAvailable->drawTo(window);
    btnRoad->drawTo(window);
    btnBroke->drawTo(window);
    btnRepair->drawTo(window);
    drawBtnBack();
}

bool ChangeStatusPage::isMouseOver() {
    bool isCursorOver = false;

    if (btnAvailable->isMouseOver(window) ||
        btnRoad->isMouseOver(window) ||
        btnBroke->isMouseOver(window) ||
        btnRepair->isMouseOver(window) ||
        handleBtnBackHover()) {
        isCursorOver = true;
    }

    return isCursorOver;
}

PageName ChangeStatusPage::mouseClick() {
    if (btnAvailable->isClick(window)) {
        return PageName::available;
    }

    if (btnRoad->isClick(window)) {
        return PageName::vehicleData;
    }

    if (btnBroke->isClick(window)) {
        return PageName::vehicleData;
    }

    if (btnRepair->isClick(window)) {
        return PageName::vehicleData;
    }

    if (handleBtnBackClick()) {
        clear();
        return PageName::vehicleData;
    }
    return PageName::changeStatus;
}

// private
void ChangeStatusPage::create() {
    float btnPosX = width / 2;
    float btnPosY = height / 2 - 16;

    btnAvailable = new Button({btnPosX - 274, btnPosY - 74}, "Available", font);
    btnRoad = new Button({btnPosX + 24, btnPosY - 74}, "On the road", font);
    btnBroke = new Button({btnPosX - 274, btnPosY + 24}, "Broke down", font);
    btnRepair = new Button({btnPosX + 24, btnPosY + 24}, "In repair", font);
}

void ChangeStatusPage::clear() {
    btnAvailable->setBlock(false);
    btnRoad->setBlock(false);
    btnBroke->setBlock(false);
    btnRepair->setBlock(false);
}

void ChangeStatusPage::setBtnBlock() {
    StatusType status = controller->getSelectedVehicle()->getStatusType();

    switch (status) {
        case AVAILABLE:
            btnAvailable->setBlock();
            btnRepair->setBlock();
            break;
        case ROAD:
            btnRoad->setBlock();
            btnRepair->setBlock();
            break;
        case BROKE:
        case REPAIR:
            btnAvailable->setBlock();
            btnRoad->setBlock();
            btnBroke->setBlock();
            break;
        default:
            break;
    }
}