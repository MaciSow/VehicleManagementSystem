#include "ShowRegisterPage.h"

ShowRegisterPage::ShowRegisterPage(MainController *controller, RenderWindow *window, const Font &font) :
        controller(controller), window(window), font(font) {
    createElements();
}

ShowRegisterPage::~ShowRegisterPage() {
}

bool ShowRegisterPage::isMouseOver() {
    bool isCursorOver = false;
    if (btnBack->isMouseOver(window)) {
        isCursorOver = true;
    }

    return isCursorOver;
}

PageName ShowRegisterPage::mouseClick() {
    if (btnBack->isClick(window)) {
        clear();
        return PageName::vehicleData;
    }

    return PageName::showRegister;
}

void ShowRegisterPage::createElements() {
    float width = (float) (window->getSize().x);
    float height = (float) (window->getSize().y);
    float btnWidth = 150;
    float btnPosX = width - btnWidth - 32;
    float btnPosY = height - 50 - 32;

    btnBack = new Button({btnPosX, btnPosY}, "Back", font, btnWidth);
    btnBack->setColor({0, 0, 0, 205}, {196, 55, 55, 205});
}

void ShowRegisterPage::createHeader() {
    float width = (float) (window->getSize().x);
    float posX = width / 2;
    float posY = 100;

    Text name("Name", font, 18);
    Text distance("Distance", font, 18);
    Text start("Start", font, 18);
    Text end("End", font, 18);

    name.setFillColor({136, 136, 136, 255});
    name.setPosition({posX - 224 - name.getLocalBounds().width / 2, posY});

    distance.setFillColor({136, 136, 136, 255});
    distance.setPosition({posX, posY});

    start.setFillColor({136, 136, 136, 255});
    start.setPosition({width - 269 - start.getLocalBounds().width / 2, posY});

    end.setFillColor({136, 136, 136, 255});
    end.setPosition({width - 159 - end.getLocalBounds().width / 2, posY});

    RectangleShape line({(float) width - 208, 2});
    line.setFillColor({136, 136, 136, 255});
    line.move(104, 130);

    window->draw(name);
    window->draw(distance);
    window->draw(start);
    window->draw(end);
    window->draw(line);
}

void ShowRegisterPage::drawList() {
    int positionOffset = 0;
    float positionY = 138;

    for (int i = offset; (i < offset + limit) && (i < length); i++) {

        items[i]->setPosition(Vector2f(104, positionY));
        items[i]->drawTo(window);

        positionOffset++;
        positionY += 64;
    }
}

void ShowRegisterPage::fillList(float listWidth, float itemHeight) {
    for (auto row:controller->getSelectedVehicle()->getRegisterData()) {
        items.push_back(new ListItem({listWidth, itemHeight}, row, font, REGISTER, to_string(length)));
        length++;
    }
}

void ShowRegisterPage::scroll(int offset) {
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

void ShowRegisterPage::draw() {
    if (!isOpen) {
        refresh();
    }

    if (!items.size()) {
        float width = (float) (window->getSize().x);
        float listWidth = width - 208;
        float itemHeight = 60;

        fillList(listWidth, itemHeight);
    }

    createHeader();
    drawList();

    btnBack->drawTo(window);
}

void ShowRegisterPage::clear() {
    offset = 0;
    length = 0;
    limit = 5;
    isOpen = false;
    items.clear();
}

void ShowRegisterPage::refresh() {
    cout << "refresh";
    offset = 0;
    length = 0;
    limit = 5;
    isOpen = true;
    items.clear();
    createElements();
}