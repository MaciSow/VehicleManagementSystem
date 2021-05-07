#ifndef VEHICLEMENAGMENTSYSTEM_SHOWVEHICLESPAGE_H
#define VEHICLEMENAGMENTSYSTEM_SHOWVEHICLESPAGE_H

#include "Page.h"

class ShowVehiclesPage : public virtual Page {
private:
    vector<ListItem *> items;
    Button *btnAdd;

    int scrollOffset = 0;
    int length = 0;
    int limit = 5;

public:
    ShowVehiclesPage(MainController *controller, RenderWindow *window, const Font &font);

    virtual ~ShowVehiclesPage();

    void draw() override;

    bool isMouseOver() override;

    PageName mouseClick() override;

    void scroll(int offset);

private:
    void create() override;

    void clear() override;

    void createHeader();

    void fillList(float listWidth, float itemHeight);

    void drawList();
};


#endif //VEHICLEMENAGMENTSYSTEM_SHOWVEHICLESPAGE_H
