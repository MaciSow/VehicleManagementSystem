#ifndef VEHICLEMENAGMENTSYSTEM_VIEW_CLOSEPAGE_H
#define VEHICLEMENAGMENTSYSTEM_VIEW_CLOSEPAGE_H

#include "Page.h"

class ExitPage : public virtual Page {
public:
    ExitPage(MainController *controller, RenderWindow *window, const Font &font);

    ~ExitPage();

    void draw() override;

    bool isMouseOver() override;

    PageName mouseClick() override;

private:
    Button *btnYes;
    Button *btnNo;
    Text text;

    void create() override;
};

#endif //VEHICLEMENAGMENTSYSTEM_VIEW_CLOSEPAGE_H
