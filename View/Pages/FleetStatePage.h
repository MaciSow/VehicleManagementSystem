#ifndef VEHICLEMENAGMENTSYSTEM_FLEETSTATEPAGE_H
#define VEHICLEMENAGMENTSYSTEM_FLEETSTATEPAGE_H

#include "Page.h"

class FleetStatePage : public virtual Page {

public:
    FleetStatePage(MainController *controller, RenderWindow *window, const Font &font);

    ~FleetStatePage();

    void draw() override;

    bool isMouseOver() override;

    PageName mouseClick() override;

private:
    void create() override;

    void clear() override;

    void fillState();
};

#endif //VEHICLEMENAGMENTSYSTEM_FLEETSTATEPAGE_H
