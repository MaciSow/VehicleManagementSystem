#include "ShowVehiclesPage.h"

ShowVehiclesPage::ShowVehiclesPage(MainController *controller, RenderWindow *window, const Font &font) :
        controller(controller), window(window), font(font) {
    createElements();
}

ShowVehiclesPage::~ShowVehiclesPage() {

}

bool ShowVehiclesPage::isMouseOver() {
    bool isCursorOver = false;
    if (btnAdd->isMouseOver(window)) {
        isCursorOver = true;
    }

    if (btnBack->isMouseOver(window)) {
        isCursorOver = true;
    }

    for (ListItem *item : items) {
        if (item->isMouseOver(window)) {
            isCursorOver = true;
        }
    }

    return isCursorOver;
}

PageName ShowVehiclesPage::mouseClick() {
    if (btnAdd->isClick(window)) {
        clear();
        return PageName::addEditVehicle;
    }

    if (btnBack->isClick(window)) {
        clear();
        return PageName::home;
    }

    for (ListItem *item : items) {
        if (item->isClick(window)) {
            controller->setSelectedVehicle(item->getId());
            isOpen = false;
            return PageName::vehicleData;
        }
    }
    return PageName::showVehicles;
}

void ShowVehiclesPage::draw() {
    if (!isOpen) {
        refresh();
    }

    createHeader();
    drawList();
    btnAdd->drawTo(window);
    btnBack->drawTo(window);
}

void ShowVehiclesPage::createElements() {
    float width = (float) (window->getSize().x);
    float height = (float) (window->getSize().y);
    float btnWidth = 150;
    float btnPosX = width - btnWidth - 32;
    float btnPosY = height - 50 - 32;

    float listWidth = width - 208;
    float itemHeight = 60;

    fillList(listWidth, itemHeight);

    btnAdd = new Button({32, btnPosY}, "Add", font, btnWidth);
    btnBack = new Button({btnPosX, btnPosY}, "Back", font, btnWidth);
    btnBack->setColor({0, 0, 0, 205}, {196, 55, 55, 205});
}

void ShowVehiclesPage::clear() {
    isOpen = false;
}

void ShowVehiclesPage::createHeader() {
    float width = (float) (window->getSize().x);
    float posX = width / 2;
    float posY = 100;

    Text name("Name", font, 18);
    Text type("Type", font, 18);
    Text status("Status", font, 18);

    name.setFillColor({136, 136, 136, 255});
    name.setPosition({posX - 224 - name.getLocalBounds().width / 2, posY});

    type.setFillColor({136, 136, 136, 255});
    type.setPosition({posX - type.getLocalBounds().width / 2, posY});

    status.setFillColor({136, 136, 136, 255});
    status.setPosition({posX + 250 - status.getLocalBounds().width / 2, posY});

    RectangleShape line({(float) width - 208, 2});
    line.setFillColor({136, 136, 136, 255});
    line.move(104, 130);

    window->draw(name);
    window->draw(type);
    window->draw(status);
    window->draw(line);
}

void ShowVehiclesPage::drawList() {
    int positionOffset = 0;
    float positionY = 138;

    for (int i = offset; i < offset + limit; i++) {

        items[i]->setPosition(Vector2f(104, positionY));
        items[i]->drawTo(window);

        positionOffset++;
        positionY += 64;
    }
}

void ShowVehiclesPage::scroll(int offset) {
    if (offset < -1) {
        offset = -1;
    } else if (offset > 1) {
        offset = 1;
    }

    if (offset > 0 && this->offset == 0) {
        return;
    }

    int countItems = items.size();
    if (offset < 0 && this->offset + limit >= countItems) {
        return;
    }

    this->offset -= offset;

    drawList();
    isMouseOver();
}

void ShowVehiclesPage::fillList(float listWidth, float itemHeight) {
    for (auto row:controller->getVehicleList()) {
        items.push_back(new ListItem({listWidth, itemHeight}, row, font, VEHICLES, row[3]));
    }
    cout << items.size() << endl;
}

void ShowVehiclesPage::refresh() {
    offset = 0;
    length = 0;
    limit = 5;
    isOpen = true;
    items.clear();
    createElements();

}