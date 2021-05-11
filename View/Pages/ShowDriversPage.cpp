#include "ShowDriversPage.h"

// public
ShowDriversPage::ShowDriversPage(MainController *controller, RenderWindow *window, const Font &font)
        : Page(controller, window, font) {
    create();
    createBtnBack();
}

ShowDriversPage::~ShowDriversPage() = default;

void ShowDriversPage::draw() {
    drawBtnBack();
    createHeader();

    if (items.empty()) {
        float listWidth = width - 208;
        float itemHeight = 60;
        fillList(listWidth, itemHeight);
    }

    drawList();
    btnAdd->drawTo(window);
}

bool ShowDriversPage::isMouseOver() {
    bool isCursorOver = false;
    if (btnAdd->isMouseOver(window)) {
        isCursorOver = true;
    }

    if (handleBtnBackHover()) {
        isCursorOver = true;
    }

    for (ListItem *item : items) {
        if (item->isMouseOver(window)) {
            isCursorOver = true;
        }
    }

    return isCursorOver;
}

PageName ShowDriversPage::mouseClick() {
    if (btnAdd->isClick(window)) {
        clear();
        return PageName::addEditDriver;
    }

    if (handleBtnBackClick()) {
        clear();
        return PageName::home;
    }

    for (ListItem *item : items) {
        if (item->isClick(window)) {
            controller->selectDriver(item->getId());
            clear();
            return PageName::driverData;
        }
    }
    return PageName::showDrivers;
}

void ShowDriversPage::scroll(int offset) {
    if (offset < -1) {
        offset = -1;
    } else if (offset > 1) {
        offset = 1;
    }

    if (offset > 0 && scrollOffset == 0) {
        return;
    }

    int countItems = (int) items.size();
    if (offset < 0 && scrollOffset + limit >= countItems) {
        return;
    }

    scrollOffset -= offset;

    drawList();
    isMouseOver();
}

// private
void ShowDriversPage::create() {
    float btnWidth = 150;
    float btnPosY = height - 50 - 32;

    btnAdd = new Button({32, btnPosY}, "Add", font, btnWidth);
}

void ShowDriversPage::clear() {
    scrollOffset = 0;
    length = 0;
    limit = 5;
    items.clear();
}

void ShowDriversPage::createHeader() {
    float width = (float) (window->getSize().x);
    float posX = width / 2;
    float posY = 100;

    Text name("Name and Surname", font, 18);
    Text status("Status", font, 18);

    name.setFillColor({136, 136, 136, 255});
    name.setPosition({posX - 224 - name.getLocalBounds().width / 2, posY});

    status.setFillColor({136, 136, 136, 255});
    status.setPosition({posX + 250 - status.getLocalBounds().width / 2, posY});

    RectangleShape line({(float) width - 208, 2});
    line.setFillColor({136, 136, 136, 255});
    line.move(104, 130);

    window->draw(name);
    window->draw(status);
    window->draw(line);
}

void ShowDriversPage::fillList(float listWidth, float itemHeight) {
    for (auto row:controller->getDriversList()) {
        items.push_back(new ListItem({listWidth, itemHeight}, row, font, DRIVERS, row[2]));
        length++;
    }
}

void ShowDriversPage::drawList() {
    int positionOffset = 0;
    float positionY = 138;

    for (int i = scrollOffset; (i < scrollOffset + limit) && (i < length); i++) {
        items[i]->setPosition(Vector2f(104, positionY));
        items[i]->drawTo(window);

        positionOffset++;
        positionY += 64;
    }
}
