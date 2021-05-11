#ifndef VEHICLEMENAGMENTSYSTEM_VEHICLEDATAPAGE_H
#define VEHICLEMENAGMENTSYSTEM_VEHICLEDATAPAGE_H

#include "Page.h"

class VehicleDataPage : public virtual Page {
private:
    Vehicle *vehicle;
    Button *btnEdit;
    Button *btnDelete;
    Button *btnChangeStatus;
    Button *btnShowRegister;
    Button *btnShowRepairs;

public:
    VehicleDataPage(MainController *controller, RenderWindow *window, const Font &font);

    ~VehicleDataPage();

    void draw() override;

    bool isMouseOver() override;

    PageName mouseClick() override;

private:
    void create() override;

    void clear() override;

    void fillData();

    Color getStatusColor(string status);
};

#endif //VEHICLEMENAGMENTSYSTEM_VEHICLEDATAPAGE_H
