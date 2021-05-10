#ifndef VEHICLEMENAGMENTSYSTEM_VIEW_GRAPHICVIEW_H
#define VEHICLEMENAGMENTSYSTEM_VIEW_GRAPHICVIEW_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "../Controller/MainController.h"
#include "Elements/Button.h"
#include "Elements/Input.h"
#include "Pages/PageName.h"
#include "Pages/HomePage.h"
#include "Pages/FleetStatePage.h"
#include "Pages/VehicleDataPage.h"
#include "Pages/BasePage.h"
#include "Pages/ClosePage.h"
#include "Pages/ShowVehiclesPage.h"
#include "Pages/ShowRegisterPage.h"
#include "Pages/ShowRepairsPage.h"
#include "Pages/AddEditVehiclePage.h"
#include "Pages/ChangeStatusPage.h"
#include "Pages/AvailablePage.h"
#include "Pages/RoadPage.h"
#include "Pages/RepairPage.h"

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
    VehicleDataPage* vehicleDataPage;
    ChangeStatusPage* changeStatusPage;
    AvailablePage* availablePage;
    RoadPage* roadPage;
    RepairPage* repairPage;
    ShowRegisterPage* showRegisterPage;
    ShowRepairsPage* showRepairsPage;
    AddEditVehiclePage* addEditVehiclePage;
    BasePage* basePage;
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
