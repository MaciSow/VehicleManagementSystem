#ifndef VEHICLEMENAGMENTSYSTEM_PAGE_H
#define VEHICLEMENAGMENTSYSTEM_PAGE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "PageName.h"
#include "../../Controller/MainController.h"
#include "../Elements/Button.h"
#include "../Elements/Input.h"

using namespace std;
using namespace sf;

class Page {
protected:
    MainController *controller;
    RenderWindow *window;
    Font font;
    Button *btnBack;

    float width = 960;
    float height = 576;

    virtual void create() = 0;

//    virtual void prepare() = 0;

    virtual void clear();

    void createBtnBack();

    void drawBackBtn();

    bool handleBtnBackClick();

    bool handleBtnBackHover();

public:
    Page(MainController *controller, RenderWindow *window, const Font &font);

    ~Page();

    virtual bool isMouseOver();

    virtual PageName mouseClick() = 0;

    virtual void draw();
};

#endif //VEHICLEMENAGMENTSYSTEM_PAGE_H
