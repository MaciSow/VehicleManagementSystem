#ifndef VEHICLEMENAGMENTSYSTEM_AVAILABLEPAGE_H
#define VEHICLEMENAGMENTSYSTEM_AVAILABLEPAGE_H

#include "Page.h"

class AvailablePage : public virtual Page {
private:
    Button *btnSave;

    Button *btnReturn;
    Button *btnStop;

    void clear() override;

    void createSeparator();

    void checkChoice();

public:
    AvailablePage(MainController *controller, RenderWindow *window, const Font &font);

    ~AvailablePage();

    bool isMouseOver() override;

    PageName mouseClick() override;

    void create() override;

    void draw() override;
};

#endif //VEHICLEMENAGMENTSYSTEM_AVAILABLEPAGE_H
