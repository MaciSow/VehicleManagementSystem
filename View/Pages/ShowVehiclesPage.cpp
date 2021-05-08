#include "ShowVehiclesPage.h"

// public
ShowVehiclesPage::ShowVehiclesPage(MainController *controller, RenderWindow *window, const Font &font)
        : Page(controller, window, font) {
    create();
    createBtnBack();
}

ShowVehiclesPage::~ShowVehiclesPage() = default;

void ShowVehiclesPage::draw() {
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

bool ShowVehiclesPage::isMouseOver() {
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

PageName ShowVehiclesPage::mouseClick() {
    if (btnAdd->isClick(window)) {
        clear();
        return PageName::addEditVehicle;
    }

    if (handleBtnBackClick()) {
        clear();
        return PageName::home;
    }

    for (ListItem *item : items) {
        if (item->isClick(window)) {
            controller->selectVehicle(item->getId());
            clear();
            return PageName::vehicleData;
        }
    }
    return PageName::showVehicles;
}

void ShowVehiclesPage::scroll(int offset) {
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
void ShowVehiclesPage::create() {
    float btnWidth = 150;
    float btnPosY = height - 50 - 32;

    btnAdd = new Button({32, btnPosY}, "Add", font, btnWidth);
}

void ShowVehiclesPage::clear() {
    scrollOffset = 0;
    length = 0;
    limit = 5;
    items.clear();
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

void ShowVehiclesPage::fillList(float listWidth, float itemHeight) {
    for (auto row:controller->getVehiclesList()) {
        items.push_back(new ListItem({listWidth, itemHeight}, row, font, VEHICLES, row[3]));
        length++;
    }
}

void ShowVehiclesPage::drawList() {
    int positionOffset = 0;
    float positionY = 138;

    for (int i = scrollOffset; (i < scrollOffset + limit) && (i < length); i++) {
        items[i]->setPosition(Vector2f(104, positionY));
        items[i]->drawTo(window);

        positionOffset++;
        positionY += 64;
    }
}
