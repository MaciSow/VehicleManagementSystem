#ifndef VEHICLEMENAGMENTSYSTEM_BROKEPAGE_H
#define VEHICLEMENAGMENTSYSTEM_BROKEPAGE_H


#include "Page.h"

class BrokePage : public virtual Page {
public:
    BrokePage(MainController *controller, RenderWindow *window, const Font &font);

    ~BrokePage();

    void draw() override;

    bool isMouseOver() override;

    PageName mouseClick() override;

    void textEntered(Event &event);

private:
    vector<Input *>inputs;

    void create() override;

    void clear() override;

    void checkChoice();

    void save();
};

#endif //VEHICLEMENAGMENTSYSTEM_BROKEPAGE_H