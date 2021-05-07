#ifndef VEHICLEMENAGMENTSYSTEM_AVAILABLEPAGE_H
#define VEHICLEMENAGMENTSYSTEM_AVAILABLEPAGE_H

#include "Page.h"

class AvailablePage : public virtual Page {
private:
    Button *btnReturn;
    Button *btnStop;

public:
    AvailablePage(MainController *controller, RenderWindow *window, const Font &font);

    ~AvailablePage();

    void draw() override;

    bool isMouseOver() override;

    PageName mouseClick() override;

private:
    void create() override;

    void clear() override;

    void createSeparator();

    void checkChoice();
};

#endif //VEHICLEMENAGMENTSYSTEM_AVAILABLEPAGE_H
