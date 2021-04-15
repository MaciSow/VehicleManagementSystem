#ifndef VEHICLEMENAGMENTSYSTEM_MAINCONTROLLER_H
#define VEHICLEMENAGMENTSYSTEM_MAINCONTROLLER_H

#include <typeinfo>
#include <iostream>
//#include "../View/ConsoleView.h"
//#include "../Model/Others/File.h"

using namespace std;

class MainController {
private:

//	File* f1;
    string path = "resources/";
    string filename = "Carrier.txt";

public:
    bool isCreating = false;

    MainController();

    void save(string filename);

    void clean();
};


#endif //VEHICLEMENAGMENTSYSTEM_MAINCONTROLLER_H
