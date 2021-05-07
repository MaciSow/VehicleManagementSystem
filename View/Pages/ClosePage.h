#ifndef VEHICLEMENAGMENTSYSTEM_VIEW_CLOSEPAGE_H
#define VEHICLEMENAGMENTSYSTEM_VIEW_CLOSEPAGE_H

#include "Page.h"

class ClosePage : public virtual Page {

public:
    ClosePage(MainController *controller, RenderWindow *window, const Font &font);

    ~ ClosePage();

    void draw() override;

    bool isMouseOver() override;

    PageName mouseClick() override;

private:
    void create() override;

    void clear() override;
};

#endif //VEHICLEMENAGMENTSYSTEM_VIEW_CLOSEPAGE_H
