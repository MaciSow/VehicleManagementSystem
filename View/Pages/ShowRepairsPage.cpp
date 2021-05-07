#include "ShowRepairsPage.h"

// public
ShowRepairsPage::ShowRepairsPage(MainController *controller, RenderWindow *window, const Font &font)
        : Page(controller, window, font) {
    create();
    createBtnBack();
}

ShowRepairsPage::~ShowRepairsPage() = default;

void ShowRepairsPage::draw() {
    drawBtnBack();
    createHeader();

    if (items.empty()) {
        float listWidth = width - 208;
        float itemHeight = 60;
        fillList(listWidth, itemHeight);
    }

    drawList();
}

bool ShowRepairsPage::isMouseOver() {
    bool isCursorOver = false;

    if (handleBtnBackHover()) {
        isCursorOver = true;
    }

    return isCursorOver;
}

PageName ShowRepairsPage::mouseClick() {
    if (handleBtnBackClick()) {
        clear();
        return PageName::vehicleData;
    }

    return PageName::showRepairs;
}

void ShowRepairsPage::scroll(int offset) {
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

void ShowRepairsPage::create() {}

void ShowRepairsPage::clear() {
    scrollOffset = 0;
    length = 0;
    limit = 5;
    items.clear();
}

void ShowRepairsPage::fillList(float listWidth, float itemHeight) {
    for (auto row:controller->getSelectedVehicle()->getRepairsData()) {
        items.push_back(new ListItem({listWidth, itemHeight}, row, font, REPAIRS, to_string(length)));
        length++;
    }
}

void ShowRepairsPage::drawList() {
    int positionOffset = 0;
    float positionY = 138;

    for (int i = scrollOffset; (i < scrollOffset + limit) && (i < length); i++) {

        items[i]->setPosition(Vector2f(104, positionY));
        items[i]->drawTo(window);

        positionOffset++;
        positionY += 64;
    }
}
