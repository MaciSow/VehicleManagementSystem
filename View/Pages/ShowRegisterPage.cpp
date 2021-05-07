#include "ShowRegisterPage.h"

// public
ShowRegisterPage::ShowRegisterPage(MainController *controller, RenderWindow *window, const Font &font)
        : Page(controller, window, font) {
    create();
    createBtnBack();
}

ShowRegisterPage::~ShowRegisterPage() = default;

void ShowRegisterPage::draw() {
    drawBtnBack();

    if (items.empty()) {
        float listWidth = width - 208;
        float itemHeight = 60;
        fillList(listWidth, itemHeight);
    }

    createHeader();
    drawList();
}

bool ShowRegisterPage::isMouseOver() {
    bool isCursorOver = false;

    if (handleBtnBackHover()) {
        isCursorOver = true;
    }

    return isCursorOver;
}

PageName ShowRegisterPage::mouseClick() {
    if (handleBtnBackClick()) {
        clear();
        return PageName::vehicleData;
    }

    return PageName::showRegister;
}


void ShowRegisterPage::scroll(int offset) {
    if (offset < -1) {
        offset = -1;
    } else if (offset > 1) {
        offset = 1;
    }

    if (offset > 0 && scrollOffset == 0) {
        return;
    }

    int countItems = (int)items.size();
    if (offset < 0 && scrollOffset + limit >= countItems) {
        return;
    }

    scrollOffset -= offset;

    drawList();
    isMouseOver();
}

// private
void ShowRegisterPage::create() {}

void ShowRegisterPage::clear() {
    scrollOffset = 0;
    length = 0;
    limit = 5;
    items.clear();
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

void ShowRegisterPage::fillList(float listWidth, float itemHeight) {
    for (auto row:controller->getSelectedVehicle()->getRegisterData()) {
        items.push_back(new ListItem({listWidth, itemHeight}, row, font, REGISTER, to_string(length)));
        length++;
    }
}

void ShowRegisterPage::drawList() {
    int positionOffset = 0;
    float positionY = 138;

    for (int i = scrollOffset; (i < scrollOffset + limit) && (i < length); i++) {
        items[i]->setPosition(Vector2f(104, positionY));
        items[i]->drawTo(window);

        positionOffset++;
        positionY += 64;
    }
}


