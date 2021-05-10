#ifndef VEHICLEMENAGMENTSYSTEM_REPAIRPAGE_H
#define VEHICLEMENAGMENTSYSTEM_REPAIRPAGE_H

#include "Page.h"

class RepairPage : public virtual Page {
public:
    RepairPage(MainController *controller, RenderWindow *window, const Font &font);

    ~RepairPage();

    void draw() override;

    bool isMouseOver() override;

    PageName mouseClick() override;

    void textEntered(Event &event);

private:
    Input *input;
    Button *btnRepairNow;

    bool isOpen = false;

    void create() override;

    void clear() override;

    void createSeparator();

    void checkChoice();

    void save();

    void prepare();
};


#endif //VEHICLEMENAGMENTSYSTEM_REPAIRPAGE_H
