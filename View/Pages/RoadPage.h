#ifndef VEHICLEMENAGMENTSYSTEM_ROADPAGE_H
#define VEHICLEMENAGMENTSYSTEM_ROADPAGE_H

#include "Page.h"

class RoadPage : public virtual Page {
private:
    vector<Input *> inputs;
    vector<ListItem *> items;

    bool isOpen = false;

    int scrollOffset = 0;
    int length = 0;
    int limit = 4;
public:
    RoadPage(MainController *controller, RenderWindow *window, const Font &font);

    ~RoadPage();

    void draw() override;

    bool isMouseOver() override;

    PageName mouseClick() override;

    void textEntered(Event &event);

    void scroll(int offset);

private:
    void create() override;

    void clear() override;

    void createSeparator();

    void drawList();

    void fillList(float listWidth, float itemHeight);

    void selectItem(ListItem *item);

    void clearItems();

    ListItem *getPressedItem();

    void checkValues();

    void save();
};


#endif //VEHICLEMENAGMENTSYSTEM_ROADPAGE_H
