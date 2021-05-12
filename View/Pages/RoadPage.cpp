#include "RoadPage.h"

// public
RoadPage::RoadPage(MainController *controller, RenderWindow *window, const Font &font)
        : Page(controller, window, font) {
    create();
    createBtnBack();
    createBtnSave();
}

RoadPage::~RoadPage() = default;

void RoadPage::draw() {
    inputs[0]->drawTo(window);
    inputs[1]->drawTo(window);

    if(!isOpen){
        isOpen = true;
        inputs[0]->setPattern("^\\d{1,5}$");
        inputs[1]->setPattern("^\\d{0,2}$");
    }

    drawBtnBack();
    drawBtnSave();
    createSeparator();

    if (items.empty()) {
        float listWidth = width - 400;
        float itemHeight = 50;
        fillList(listWidth, itemHeight);
    }

    drawList();
}

bool RoadPage::isMouseOver() {
    bool isCursorOver = false;

    for (Input *input : inputs) {
        if (input->isMouseOver(window)) {
            isCursorOver = true;
        }
    }

    for (ListItem *item : items) {
        if (item->isMouseOver(window)) {
            isCursorOver = true;
        }
    }

    if (handleBtnBackHover()
        || handleBtnSaveHover()) {
        isCursorOver = true;
    }
    return isCursorOver;
}

PageName RoadPage::mouseClick() {

    for (Input *input : inputs) {
        input->checkSelection(window);
    }

    for (ListItem *item : items) {
        if (item->isClick(window)) {
            selectItem(item);
            checkValues();
        }
    }

    if (handleBtnSaveClick()) {
        save();
        clear();
        return PageName::vehicleData;
    }

    if (handleBtnBackClick()) {
        clear();
        return PageName::changeStatus;
    }
    return PageName::road;
}

// private
void RoadPage::create() {
    inputs.push_back(new Input({200, 130}, font, "Kilometers:", 250));
    inputs.push_back(new Input({width - 450, 130}, font, "Pause days:", 250));
}

void RoadPage::clear() {
    scrollOffset = 0;
    length = 0;
    limit = 4;
    items.clear();
    clearItems();
    isOpen = false;
    inputs[0]->clear();
    inputs[1]->clear();
    blockBtnSave();
}

void RoadPage::createSeparator() {
    float posX = width / 2;

    RectangleShape line({width - 400, 2});
    line.setFillColor({136, 136, 136, 255});
    line.move(200, 210);


    Text text("Choose driver", font, 18);
    text.setFillColor({136, 136, 136, 255});
    text.setPosition({posX - text.getLocalBounds().width / 2, 185});

    window->draw(line);
    window->draw(text);
}

void RoadPage::textEntered(Event &event) {
    for (Input *input : inputs) {
        input->typeOn(event);
    }
    checkValues();
}

void RoadPage::scroll(int offset) {
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

void RoadPage::drawList() {
    int positionOffset = 0;
    float positionY = 216;

    for (int i = scrollOffset; (i < scrollOffset + limit) && (i < length); i++) {

        items[i]->setPosition(Vector2f(200, positionY));
        items[i]->drawTo(window);

        positionOffset++;
        positionY += 54;
    }
}

void RoadPage::fillList(float listWidth, float itemHeight) {
    for (auto row:controller->getDriversList(true)) {
        items.push_back(new ListItem({listWidth, itemHeight}, row, font, CHOOSEDRIVER, row[1]));
        length++;
    }
}

void RoadPage::selectItem(ListItem *item) {
    clearItems();
    item->setPressed();
}

void RoadPage::clearItems() {
    for (ListItem *item : items) {
        item->setPressed(false);
    }
}

ListItem *RoadPage::getPressedItem() {
    for (ListItem *item : items) {
        if (item->getPressed()) {
            return item;
        }
    }
    return nullptr;
}

void RoadPage::checkValues() {
    if (!getPressedItem()) {
        blockBtnSave();
        return;
    }

    if (inputs[0]->getText().length() && inputs[0]->getValid() && inputs[1]->getValid()) {
        activeBtnSave();
        return;
    }

    blockBtnSave();
}

void RoadPage::save() {
    int kilometers = stoi(inputs[0]->getText());
    int pause = stoi(inputs[0]->getText());
    string driverId = getPressedItem()->getId();

    controller->setRoad(kilometers, pause, driverId);
}

