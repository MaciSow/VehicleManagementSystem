#ifndef VEHICLEMENAGMENTSYSTEM_CHANGESTATUSPAGE_H
#define VEHICLEMENAGMENTSYSTEM_CHANGESTATUSPAGE_H

#include "Page.h"

class ChangeStatusPage : public virtual Page {
private:
    Button *btnAvailable;
    Button *btnRoad;
    Button *btnBroke;
    Button *btnRepair;

public:
    ChangeStatusPage(MainController *controller, RenderWindow *window, const Font &font);

    ~ChangeStatusPage();

    void draw() override;

    bool isMouseOver() override;

    PageName mouseClick() override;

private:
    void create() override;

    void clear() override;

    void setBtnBlock();
};

#endif //VEHICLEMENAGMENTSYSTEM_CHANGESTATUSPAGE_H
