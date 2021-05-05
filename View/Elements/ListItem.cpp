#include "ListItem.h"

ListItem::ListItem(Vector2f size, vector<string> data, Font &font, ListType listType, string id) {
    this->id = id;
    this->listType = listType;
    width = size.x;
    height = size.y;
    create(data, font);
}

string ListItem::getId() {
    return id;
}

void ListItem::setId(string id) {
    this->id = id;
}

void ListItem::setPosition(Vector2f position) {
    float itemPosX = listItem.getPosition().x;
    float itemPosY = listItem.getPosition().y;
    float itemWidth = listItem.getSize().x;

    listItem.setPosition(position);

    this->column1.setPosition({itemPosX + 16, itemPosY + 16});

    switch (listType) {
        case VEHICLES:
            this->column2.setPosition({itemPosX + itemWidth / 2 - column2.getLocalBounds().width / 2, itemPosY + 16});
        case DRIVERS:
            this->column3.setPosition({itemPosX + itemWidth - column3.getLocalBounds().width - 16, itemPosY + 16});
            break;
        case REGISTER:
            this->column2.setPosition({itemPosX + itemWidth / 2 + 16, itemPosY + 16});
            this->column3.setPosition({itemPosX + itemWidth - 220, itemPosY + 16});
            this->column4.setPosition({itemPosX + itemWidth - 110, itemPosY + 16});
            break;
        case REPAIRS:
            this->column2.setPosition({itemPosX + 316, itemPosY + 16});
            this->column3.setPosition({itemPosX + itemWidth - 110, itemPosY + 16});
            break;
        default:
            break;
    }
}


bool ListItem::isMouseOver(RenderWindow *&window) {
    int mouseX = (int) Mouse::getPosition(*window).x;
    int mouseY = (int) Mouse::getPosition(*window).y;

    int btnPosX = (int) listItem.getPosition().x;
    int btnPosY = (int) listItem.getPosition().y;

    if (mouseX > btnPosX && mouseX < btnPosX + width &&
        mouseY > btnPosY && mouseY < btnPosY + height) {
        setListItemState(hover);

        return true;
    }

    setListItemState(active);

    return false;
}

bool ListItem::isClick(RenderWindow *&window) {
    if (isMouseOver(window)) {
        setListItemState(pressed);
        return true;
    }

    return false;
}

void ListItem::release(RenderWindow *&window) {
    if (isMouseOver(window)) {
        setListItemState(hover);
        return;
    }

    setListItemState(active);
}

void ListItem::drawTo(RenderWindow *&window) {
    window->draw(listItem);

    window->draw(column1);
    window->draw(column2);
    window->draw(column3);
    window->draw(column4);
}

// private methods

void ListItem::setListItemState(State state) {
    switch (state) {
        case active:
            listItem.setFillColor({255, 255, 255, 150});
            break;
        case hover:
            listItem.setFillColor({86, 155, 240, 205});
            break;
        case pressed:
            listItem.setFillColor({86, 155, 240, 255});
            break;
        default:
            break;
    }
}

int ListItem::getHeight() {
    return (int) listItem.getSize().y;
}

void ListItem::create(vector<string> data, Font &font) {
    listItem.setSize({width, height});

    column1.setString(data[0]);
    column1.setFont(font);
    column1.setCharacterSize(h1);
    column1.setFillColor(Color::Black);

    column2.setFont(font);
    column2.setFillColor(Color::Black);

    column3.setFont(font);
    column3.setFillColor(Color::Black);

    column4.setFont(font);
    column4.setFillColor(Color::Black);

    switch (listType) {
        case VEHICLES:
            column2.setString(data[1]);
            column2.setCharacterSize(h1);

            column3.setString(data[2]);
            column3.setCharacterSize(h1);
            column3.setFillColor(getStatusColor(data[2]));
            break;
        case DRIVERS:
            column3.setString(data[1]);
            column3.setCharacterSize(h1);
            column3.setFillColor(getStatusColor(data[1]));
            break;
        case REGISTER:
            column2.setString(data[1]);
            column2.setCharacterSize(h2);

            column3.setString(data[2]);
            column3.setCharacterSize(h2);

            column4.setString(data[3]);
            column4.setCharacterSize(h2);
            break;
        case REPAIRS:
            column2.setString(data[1]);
            column2.setCharacterSize(h2);

            column3.setString(data[2]);
            column3.setCharacterSize(h2);
            break;
        case CHOOSEDRIVER:
            column1.setCharacterSize(h2);
            break;
        default:
            break;
    }

    setListItemState(active);
}

Color ListItem::getStatusColor(string status) {
    if (status == "Available") {
        return {5, 128, 10, 255};
    }

    if (status == "Broke down") {
        return {175, 28, 28, 255};
    }

    if (status == "In repair") {
        return {223, 134, 0, 255};
    }

    return {0, 0, 0, 255};
}

