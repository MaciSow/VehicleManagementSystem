#ifndef VEHICLEMENAGMENTSYSTEM_SHOWDRIVERSPAGE_H
#define VEHICLEMENAGMENTSYSTEM_SHOWDRIVERSPAGE_H

#include "Page.h"

class ShowDriversPage : public virtual Page {
private:
    vector<ListItem *> items;
    Button *btnAdd;

    int scrollOffset = 0;
    int length = 0;
    int limit = 5;

public:
    ShowDriversPage(MainController *controller, RenderWindow *window, const Font &font);

    virtual ~ShowDriversPage();

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


#endif //VEHICLEMENAGMENTSYSTEM_SHOWDRIVERSPAGE_H
