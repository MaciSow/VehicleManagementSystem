#ifndef VEHICLEMENAGMENTSYSTEM_BASEPAGE_H
#define VEHICLEMENAGMENTSYSTEM_BASEPAGE_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../../Controller/MainController.h"
#include "PageName.h"
#include "../Elements/Button.h"

using namespace std;
using namespace sf;

class BasePage {
private:
    MainController *controller;
    RenderWindow *window;
    Font font;

    Button *btnBack;

    void createElements();

    void clear();

public:
    BasePage(MainController *controller, RenderWindow *window, const Font &font);

    ~BasePage();

    bool isMouseOver();

    PageName mouseClick();

    void draw();
};


#endif //VEHICLEMENAGMENTSYSTEM_BASEPAGE_H
