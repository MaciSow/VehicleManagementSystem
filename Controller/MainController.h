#ifndef VEHICLEMENAGMENTSYSTEM_MAINCONTROLLER_H
#define VEHICLEMENAGMENTSYSTEM_MAINCONTROLLER_H

#include <typeinfo>
#include <iostream>

#include "../Model/Others/File.h"
#include "../Model/Fleet.h"
//#include "../View/ConsoleView.h"

using namespace std;

class MainController {
private:
    Fleet* fleet;
	File* f1;
    string path = "assets/";
    string filename = "Vehicles.yaml";

public:
    bool isCreating = false;

    MainController();

    void save(string filename);

    void clean();

    vector<int> getStateData();
};


#endif //VEHICLEMENAGMENTSYSTEM_MAINCONTROLLER_H
