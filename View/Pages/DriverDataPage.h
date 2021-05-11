#ifndef VEHICLEMENAGMENTSYSTEM_DRIVERDATAPAGE_H
#define VEHICLEMENAGMENTSYSTEM_DRIVERDATAPAGE_H

#include "Page.h"

class DriverDataPage : public virtual Page {
private:
    Button *btnEdit;
    Button *btnDelete;

public:
    DriverDataPage(MainController *controller, RenderWindow *window, const Font &font);

    ~DriverDataPage();

    void draw() override;

    bool isMouseOver() override;

    PageName mouseClick() override;

private:
    void create() override;

    void clear() override;

    void fillData();
};


#endif //VEHICLEMENAGMENTSYSTEM_DRIVERDATAPAGE_H
