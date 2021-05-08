#ifndef VEHICLEMENAGMENTSYSTEM_VIEW_LIST_ITEM_H
#define VEHICLEMENAGMENTSYSTEM_VIEW_LIST_ITEM_H

#include <SFML/Graphics.hpp>
#include "iostream"

using namespace std;
using namespace sf;

enum ListType {
    VEHICLES,
    DRIVERS,
    REGISTER,
    REPAIRS,
    CHOOSEDRIVER
};

enum State {
    active,
    hover,
    pressed
};

class ListItem {
private:
    RectangleShape listItem;
    ListType listType;

    Text column1;
    Text column2;
    Text column3;
    Text column4;

    bool isPressed = false;

    float width = 250;
    float height = 50;
    int h1 = 24;
    int h2 = 18;
    string id = "";

    void create(vector<string> data, Font &font);

    Color getStatusColor(string status);

public:

    ListItem(Vector2f size, vector<string> data, Font &font, ListType listType = VEHICLES, string id = 0);

    ~ListItem();

    string getId();

    void setId(string id);

    int getHeight();

    void setListItemState(State state);

    void setPosition(Vector2f position);

    bool isMouseOver(RenderWindow *&window);

    bool isClick(RenderWindow *&window);

    void release(RenderWindow *&window);

    void drawTo(RenderWindow *&window);

    void setPressed(bool isPressed = true);

    bool getPressed() const;
};

#endif  //VEHICLEMENAGMENTSYSTEM_VIEW_LIST_ITEM_H