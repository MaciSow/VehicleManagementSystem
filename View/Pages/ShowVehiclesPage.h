#ifndef VEHICLEMENAGMENTSYSTEM_SHOWVEHICLESPAGE_H
#define VEHICLEMENAGMENTSYSTEM_SHOWVEHICLESPAGE_H


#include <SFML/Graphics.hpp>
#include "../Elements/Button.h"
#include "../../Controller/MainController.h"
#include "PageName.h"
#include "../Elements/ListItem.h"

using namespace std;
using namespace sf;

class ShowVehiclesPage {
private:
    MainController *controller;
    RenderWindow *window;
    Font font;

    vector<ListItem *> items;
    Button *btnAdd;
    Button *btnBack;

    int offset = 0;
    int length = 6;
    int limit = 5;

    bool isOpen = false;

    void createElements();

    void createHeader();

    void drawList();

    void fillList(float listWidth, float itemHeight);

    void refresh();

    void clear();

public:
    ShowVehiclesPage(MainController *controller, RenderWindow *window, const Font &font);

    virtual ~ShowVehiclesPage();

    bool isMouseOver();

    PageName mouseClick();

    void scroll(int offset);

    void draw();
};


#endif //VEHICLEMENAGMENTSYSTEM_SHOWVEHICLESPAGE_H
