#ifndef VEHICLEMENAGMENTSYSTEM_CHANGESTATUSPAGE_H
#define VEHICLEMENAGMENTSYSTEM_CHANGESTATUSPAGE_H

#include "Page.h"

class ChangeStatusPage : public virtual Page {
private:
    Button * btnAvailable;
    Button * btnRoad;
    Button * btnBroke;
    Button * btnRepair;

    void clear() override;

    void setBtnBlock();

public:
    ChangeStatusPage(MainController *controller, RenderWindow *window, const Font &font);

    ~ChangeStatusPage();

    bool isMouseOver() override;

    PageName mouseClick() override;

    void create() override;

    void draw() override;
};


#endif //VEHICLEMENAGMENTSYSTEM_CHANGESTATUSPAGE_H
