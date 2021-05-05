#ifndef VEHICLEMENAGMENTSYSTEM_SHOWREGISTERPAGE_H
#define VEHICLEMENAGMENTSYSTEM_SHOWREGISTERPAGE_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../../Controller/MainController.h"
#include "PageName.h"
#include "../Elements/Button.h"
#include "../Elements/ListItem.h"

using namespace std;
using namespace sf;

class ShowRegisterPage {
private:
    MainController *controller;
    RenderWindow *window;
    Font font;

    Vehicle *vehicle;
    vector<ListItem *> items;
    Button *btnBack;

    int offset = 0;
    int length = 0;
    int limit = 5;

    bool isOpen = false;

    void createElements();

    void createHeader();

    void drawList();

    void fillList(float listWidth, float itemHeight);

    void refresh();

    void clear();

public:
    ShowRegisterPage(MainController *controller, RenderWindow *window, const Font &font);

    ~ShowRegisterPage();

    bool isMouseOver();

    PageName mouseClick();

    void scroll(int offset);

    void draw();
};


#endif //VEHICLEMENAGMENTSYSTEM_SHOWREGISTERPAGE_H
