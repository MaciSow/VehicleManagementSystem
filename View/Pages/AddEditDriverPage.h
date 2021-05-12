#ifndef VEHICLEMENAGMENTSYSTEM_ADDEDITDRIVERPAGE_H
#define VEHICLEMENAGMENTSYSTEM_ADDEDITDRIVERPAGE_H

#include "Page.h"

class AddEditDriverPage : public virtual Page {
public:
    AddEditDriverPage(MainController *controller, RenderWindow *window, const Font &font);

    ~AddEditDriverPage();

    void draw() override;

    bool isMouseOver() override;

    PageName mouseClick() override;

    void textEntered(Event &event);

private:
    bool isEdit = false;
    bool isOpen = false;

    vector<Input *>inputs;

    void create() override;

    void clear() override;

    void save();

    void prepare();

    void fillInputs();
};


#endif //VEHICLEMENAGMENTSYSTEM_ADDEDITDRIVERPAGE_H
