#include "Page.h"

// public
Page::Page(MainController *controller, RenderWindow *window, const Font &font) {
    this->controller = controller;
    this->window = window;
    this->font = font;
    width = (float) (window->getSize().x);
    height = (float) (window->getSize().y);
}

Page::~Page() = default;

void Page::draw() {
}

bool Page::isMouseOver() {
    return handleBtnBackHover();
}

PageName Page::mouseClick() {
    return PageName::home;
}

// protected
void Page::create() {
}


void Page::clear() {
}

void Page::checkForm(vector<Input*> inputs) {
    for (Input *input:inputs) {
        if (!input->getValid() || !input->getText().length()) {
            blockBtnSave();
            return;
        }
    }
    activeBtnSave();
}

void Page::createBtnBack() {
    float btnWidth = 150;
    float btnPosX = width - btnWidth - 32;
    float btnPosY = height - 50 - 32;

    btnBack = new Button({btnPosX, btnPosY}, "Back", font, btnWidth);
    btnBack->setColor({0, 0, 0, 205}, {196, 55, 55, 205});
}

void Page::drawBtnBack() {
    btnBack->drawTo(window);
}

bool Page::handleBtnBackClick() {
    return btnBack->isClick(window);
}

bool Page::handleBtnBackHover() {
    return btnBack->isMouseOver(window);
}

void Page::createBtnSave() {
    float btnWidth = 150;
    float btnPosX = 32;
    float btnPosY = height - 50 - 32;

    btnSave = new Button({btnPosX, btnPosY}, "Save", font, btnWidth);
    btnSave->setBlock();
}

void Page::drawBtnSave() {
    btnSave->drawTo(window);
}

bool Page::handleBtnSaveClick() {
    return btnSave->isClick(window);
}

bool Page::handleBtnSaveHover() {
    return btnSave->isMouseOver(window);
}

void Page::activeBtnSave() {
    btnSave->setBlock(false);
}

void Page::blockBtnSave() {
    btnSave->setBlock(true);
}
