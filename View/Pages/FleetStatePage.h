#ifndef VEHICLEMENAGMENTSYSTEM_FLEETSTATEPAGE_H
#define VEHICLEMENAGMENTSYSTEM_FLEETSTATEPAGE_H

#include "Page.h"

class FleetStatePage :public virtual Page {
private:
    void clear() override;
    void fillState();

public:
    FleetStatePage(MainController *controller, RenderWindow *window, const Font &font);
    ~FleetStatePage();

    PageName mouseClick() override;
    void create() override;
    void draw() override;
};


#endif //VEHICLEMENAGMENTSYSTEM_FLEETSTATEPAGE_H
