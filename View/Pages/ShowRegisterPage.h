#ifndef VEHICLEMENAGMENTSYSTEM_SHOWREGISTERPAGE_H
#define VEHICLEMENAGMENTSYSTEM_SHOWREGISTERPAGE_H

#include "Page.h"

class ShowRegisterPage : public virtual Page {
private:
    Vehicle *vehicle;
    vector<ListItem *> items;

    int scrollOffset = 0;
    int length = 0;
    int limit = 5;

public:
    ShowRegisterPage(MainController *controller, RenderWindow *window, const Font &font);

    ~ShowRegisterPage();

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


#endif //VEHICLEMENAGMENTSYSTEM_SHOWREGISTERPAGE_H
