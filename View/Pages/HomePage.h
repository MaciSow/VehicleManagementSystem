#ifndef VEHICLEMENAGMENTSYSTEM_VIEW_HOMEPAGE_H
#define VEHICLEMENAGMENTSYSTEM_VIEW_HOMEPAGE_H

#include "Page.h"

class HomePage : public virtual Page {
private:
    Button *btnFleetState;
    Button *btnShowVehicles;
    Button *btnShowDriver;
    Button *btnExit;

public:
    HomePage(MainController *controller, RenderWindow *window, const Font &font);

    ~HomePage();

    void draw() override;

    bool isMouseOver() override;

    PageName mouseClick() override;

private:
    void create() override;

    void clear() override;
};

#endif //VEHICLEMENAGMENTSYSTEM_VIEW_HOMEPAGE_H
