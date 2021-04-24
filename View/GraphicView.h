#ifndef VEHICLEMENAGMENTSYSTEM_VIEW_GRAPHICVIEW_H
#define VEHICLEMENAGMENTSYSTEM_VIEW_GRAPHICVIEW_H

#include "../Controller/MainController.h"
#include "Elements/Button.h"
#include "Elements/Input.h"
#include "Pages/PageName.h"
#include "Pages/HomePage.h"
#include "Pages/FleetStatePage.h"
#include "Pages/ClosePage.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "iostream"
#include "Pages/ShowVehiclesPage.h"

using namespace std;
using namespace sf;

class GraphicView {
private:
    MainController* controller;
    string resourcePath = "assets/";
    RenderWindow* window;
    Font font;
    Cursor cursor;
    bool isUpdate = false;
    int width = 960;
    int height = 576;
    PageName pageName;
    HomePage* homePage;
    FleetStatePage* fleetStatePage;
    ShowVehiclesPage* showVehiclesPage;
    ClosePage* closePage;

    void textEnteredHandle(Event& event);
    void mouseMovedHandle();
    void mouseButtonPressedHandle(Event& event);
    void mouseButtonReleasedHandle();
    void mouseWheelMovedHandle(Event& event);
    void drawPage();

    void loadFont();
    void createWindow();
    void createTitle(string title);
    void createFrame(int width, int height, int offsetY = 80);
    void createBackground();
    void cleanPage();

public:
    GraphicView(MainController*& ctr);
    ~GraphicView();

    void start();
};


#endif //VEHICLEMENAGMENTSYSTEM_VIEW_GRAPHICVIEW_H
