#include "ShowRepairsPage.h"

ShowRepairsPage::ShowRepairsPage(MainController *controller, RenderWindow *window, const Font &font) :
        controller(controller), window(window), font(font) {
    createElements();
}

ShowRepairsPage::~ShowRepairsPage() {
}

bool ShowRepairsPage::isMouseOver() {
    bool isCursorOver = false;
    if (btnBack->isMouseOver(window)) {
        isCursorOver = true;
    }

    return isCursorOver;
}

PageName ShowRepairsPage::mouseClick() {
    if (btnBack->isClick(window)) {
        clear();
        return PageName::vehicleData;
    }

    return PageName::showRepairs;
}

void ShowRepairsPage::createElements() {
    float width = (float) (window->getSize().x);
    float height = (float) (window->getSize().y);
    float btnWidth = 150;
    float btnPosX = width - btnWidth - 32;
    float btnPosY = height - 50 - 32;

    btnBack = new Button({btnPosX, btnPosY}, "Back", font, btnWidth);
    btnBack->setColor({0, 0, 0, 205}, {196, 55, 55, 205});
}

void ShowRepairsPage::createHeader() {
    float width = (float) (window->getSize().x);
    float posX = width / 2;
    float posY = 100;

    Text name("Name", font, 18);
    Text description("Description", font, 18);
    Text fixDate("Fix Date", font, 18);

    name.setFillColor({136, 136, 136, 255});
    name.setPosition({posX - 224 - name.getLocalBounds().width / 2, posY});

    description.setFillColor({136, 136, 136, 255});
    description.setPosition({posX, posY});

    fixDate.setFillColor({136, 136, 136, 255});
    fixDate.setPosition({width - 159 - fixDate.getLocalBounds().width / 2, posY});


    RectangleShape line({(float) width - 208, 2});
    line.setFillColor({136, 136, 136, 255});
    line.move(104, 130);

    window->draw(name);
    window->draw(description);
    window->draw(fixDate);
    window->draw(line);
}

void ShowRepairsPage::drawList() {
    int positionOffset = 0;
    float positionY = 138;

    for (int i = offset; (i < offset + limit) && (i < length); i++) {

        items[i]->setPosition(Vector2f(104, positionY));
        items[i]->drawTo(window);

        positionOffset++;
        positionY += 64;
    }
}

void ShowRepairsPage::fillList(float listWidth, float itemHeight) {
    for (auto row:controller->getSelectedVehicle()->getRepairsData()) {
        items.push_back(new ListItem({listWidth, itemHeight}, row, font, REPAIRS, to_string(length)));
        length++;
    }
}

void ShowRepairsPage::scroll(int offset) {
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

void ShowRepairsPage::draw() {
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

void ShowRepairsPage::clear() {
    offset = 0;
    length = 0;
    limit = 5;
    isOpen = false;
    items.clear();
}

void ShowRepairsPage::refresh() {
    offset = 0;
    length = 0;
    limit = 5;
    isOpen = true;
    items.clear();
    createElements();
}