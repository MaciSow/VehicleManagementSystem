#ifndef VEHICLEMENAGMENTSYSTEM_VIEW_CLOSEPAGE_H
#define VEHICLEMENAGMENTSYSTEM_VIEW_CLOSEPAGE_H


#include "../Elements/Button.h"
#include "../Elements/Input.h"
#include "../../Controller/MainController.h"
#include "PageName.h"
#include "iostream"

using namespace std;
using namespace sf;

class  ClosePage {
private:
    MainController*controller;
    RenderWindow *window;
    Font font;


public:
    ClosePage(MainController*&controller, RenderWindow *&window, Font &font);
    ~ ClosePage();


    bool isMouseOver();
    PageName mouseClick();
    void draw();
};

#endif //VEHICLEMENAGMENTSYSTEM_VIEW_CLOSEPAGE_H
