#include "ClosePage.h"

ClosePage::ClosePage(MainController *&controller, RenderWindow *&window, Font &font) {
    this->controller = controller;
    this->window = window;
    this->font = font;

}

ClosePage::~ClosePage() {
}

bool ClosePage::isMouseOver() {

    return true;
}

PageName ClosePage::mouseClick() {

}

void ClosePage::draw() {

}