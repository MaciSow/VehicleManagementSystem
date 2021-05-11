#include "ExitPage.h"

// public
ExitPage::ExitPage(MainController *controller, RenderWindow *window, const Font &font)
        : Page(controller, window, font) {
    create();
}

ExitPage::~ExitPage() = default;

void ExitPage::draw() {
    window->draw(text);
    btnYes->drawTo(window);
    btnNo->drawTo(window);
}

bool ExitPage::isMouseOver() {
    bool isCursorOver = false;

    if (btnYes->isMouseOver(window) ||
        btnNo->isMouseOver(window)) {
        isCursorOver = true;
    }

    return isCursorOver;
}

PageName ExitPage::mouseClick() {
    if (btnYes->isClick(window)) {
        controller->save();
        return PageName::close;
    }

    if (btnNo->isClick(window)) {
        return PageName::close;
    }

    return PageName::exit;
}

// private
void ExitPage::create() {
    float posX = width / 2;
    float posY = height / 2;
    float btnWidth = 150;

    btnYes = new Button({posX - 24 - btnWidth, posY + 16}, "Yes", font, btnWidth);
    btnNo = new Button({posX + 26, posY + 16}, "No", font, btnWidth);
    btnNo->setColor({0, 0, 0, 205}, {196, 55, 55, 205});

    text = Text("Do you want save data?", font, 24);
    text.setFillColor(Color::Black);
    text.setPosition({posX - text.getLocalBounds().width / 2, posY - 64});
}