#include "DriverDataPage.h"

// public
DriverDataPage::DriverDataPage(MainController *controller, RenderWindow *window, const Font &font)
        : Page(controller, window, font) {
    create();
    createBtnBack();
}

DriverDataPage::~DriverDataPage() = default;

void DriverDataPage::draw() {
    drawBtnBack();
    fillData();

    btnEdit->drawTo(window);
    btnDelete->drawTo(window);
}

bool DriverDataPage::isMouseOver() {
    bool isCursorOver = false;

    if (handleBtnBackHover() ||
        btnEdit->isMouseOver(window) ||
        btnDelete->isMouseOver(window)) {
        isCursorOver = true;
    }

    return isCursorOver;
}

PageName DriverDataPage::mouseClick() {
    if (btnEdit->isClick(window)) {
        return PageName::addEditDriver;
    }

    if (btnDelete->isClick(window)) {
        controller->deleteDriver();
        clear();
        return PageName::showDrivers;
    }

    if (handleBtnBackClick()) {
        clear();
        return PageName::showDrivers;
    }

    return PageName::driverData;
}

// private
void DriverDataPage::create() {
    float btnWidth = 150;
    float btnPosY = height - 50 - 32;

    btnEdit = new Button({32, btnPosY}, "Edit", font, btnWidth);
    btnDelete = new Button({48 + btnWidth, btnPosY}, "Delete", font, btnWidth);
}

void DriverDataPage::clear() {
    controller->unselectDriver();
}

void DriverDataPage::fillData() {
    float posX = width / 2 + 100;
    float posY = 130;
    float offset = 64;

    vector<string> labels = {"Name", "Surname", "Status"};
    vector<string> values = controller->getSelectedDriver()->getAllData();

    int labelsLength = labels.size();

    Color statusColor = values[2] == "Available" ? Color{5, 128, 10, 255} : Color::Black;


    for (int i = 0; i < labelsLength; ++i) {
        Text item(labels[i] + ':', font, 22);
        Text value(values[i], font, 22);


        item.setFillColor(Color::Black);
        item.setPosition({posX - item.getLocalBounds().width, posY += offset});

        value.setFillColor(i == 2 ? statusColor : Color::Black);
        value.setPosition({posX + 8, posY});


        window->draw(item);
        window->draw(value);
    }
}
