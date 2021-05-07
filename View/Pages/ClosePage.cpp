#include "ClosePage.h"

// public
ClosePage::ClosePage(MainController *controller, RenderWindow *window, const Font &font)
        : Page(controller, window, font) {
    create();
}

ClosePage::~ClosePage() = default;

void ClosePage::draw() {
}

bool ClosePage::isMouseOver() {
    return true;
}

PageName ClosePage::mouseClick() {
}

// private
void ClosePage::create() {

}

void ClosePage::clear() {
    Page::clear();
}
