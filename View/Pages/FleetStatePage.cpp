#include "FleetStatePage.h"

FleetStatePage::FleetStatePage(MainController *controller, RenderWindow *window, const Font &font) :
        controller(controller), window(window), font(font) {
    createElements();
}

FleetStatePage::~FleetStatePage() {

}

bool FleetStatePage::isMouseOver() {
    bool isCursorOver = false;
    if (btnBack->isMouseOver(window)) {
        isCursorOver = true;
    }
    return isCursorOver;
}

PageName FleetStatePage::mouseClick() {
    if (btnBack->isClick(window)) {
        clear();
        return PageName::home;
    }
    return PageName::fleetState;
}

void FleetStatePage::draw() {
    fillState();
    btnBack->drawTo(window);
}

void FleetStatePage::createElements() {
    float width = (float) (window->getSize().x);
    float height = (float) (window->getSize().y);
    float btnWidth = 150;
    float btnPosX = width - btnWidth - 32;
    float btnPosY = height - 50 - 32;

    btnBack = new Button({btnPosX, btnPosY}, "Back", font, btnWidth);
    btnBack->setColor({0, 0, 0, 205}, {196, 55, 55, 205});
}

void FleetStatePage::clear() {

}

void FleetStatePage::fillState() {
    float width = (float) (window->getSize().x);
    float posX;
    float posY = 60;
    float offset = 64;
    vector<String> labels = {
            "Vehicles amount", "Car amount", "Bus amount", "Van amount", "Truck amount",
            "Available vehicles", "On the road vehicles", "In repair vehicles", "Drivers amount", "Available drivers"
    };

//    vector<int> values = {86, 12, 21, 40, 13, 36, 40, 10, 60, 20};
    vector<int> values = controller->getStateData();

//    vector<Text> elements;

    int labelsLength = labels.size();

    for (int i = 0; i < labelsLength; ++i) {
        Text item(labels[i] + ':', font, 22);
        Text value(to_string(values[i]), font, 22);


        if (i < labelsLength / 2) {
            posX = width / 2 - 100;
        } else {
            posX = width / 2 + 260;
        }

        if (i == labelsLength / 2) {
            posY = 60;
        }

        item.setFillColor(Color::Black);
        item.setPosition({posX - item.getLocalBounds().width, posY += offset});

        value.setFillColor(Color::Black);
        value.setPosition({posX + 8, posY});

        window->draw(item);
        window->draw(value);

//        elements.push_back(item);
//        elements.push_back(value);
    }

}
