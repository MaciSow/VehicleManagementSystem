#ifndef VEHICLEMENAGMENTSYSTEM_PAGE_H
#define VEHICLEMENAGMENTSYSTEM_PAGE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../Controller/MainController.h"
#include "PageName.h"
#include "../Elements/Button.h"

using namespace std;
using namespace sf;

class Page {
protected:
    MainController *controller;
    RenderWindow *window;
    Font font;
    Button *btnBack;

    virtual void create();
    virtual void clear();

    void createBtnBack();
    void drawBackBtn();
    bool handleBtnBackClick();
    bool handleBtnBackHover();

public:
    Page();
    ~Page();

    virtual bool isMouseOver();
    virtual PageName mouseClick();
    virtual void draw();
};

#endif //VEHICLEMENAGMENTSYSTEM_PAGE_H
