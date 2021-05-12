#ifndef VEHICLEMENAGMENTSYSTEM_PAGE_H
#define VEHICLEMENAGMENTSYSTEM_PAGE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "PageName.h"
#include "../../Controller/MainController.h"
#include "../Elements/Button.h"
#include "../Elements/Input.h"
#include "../Elements/ListItem.h"

using namespace std;
using namespace sf;

class Page {
protected:
    MainController *controller;
    RenderWindow *window;
    Font font;
    Button *btnBack;
    Button *btnSave;

    float width = 960;
    float height = 576;

public:
    Page(MainController *controller, RenderWindow *window, const Font &font);

    ~Page();

    virtual void draw();

    virtual bool isMouseOver();

    virtual PageName mouseClick() = 0;

protected:
    virtual void create() = 0;

//    virtual void prepare() = 0;

    virtual void clear();

    void checkForm(vector<Input*> inputs);

    void createBtnBack();

    void drawBtnBack();

    bool handleBtnBackClick();

    bool handleBtnBackHover();

    void createBtnSave();

    void drawBtnSave();

    bool handleBtnSaveClick();

    bool handleBtnSaveHover();

    void activeBtnSave();

    void blockBtnSave();
};

#endif //VEHICLEMENAGMENTSYSTEM_PAGE_H
