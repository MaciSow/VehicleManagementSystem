#include <iostream>
#include <SFML/Window.hpp>

#include "View/GraphicView.h"

using namespace sf;

int main() {
    MainController* c1 = new MainController();

    GraphicView* view = new GraphicView(c1);
    view->start();

    c1->clean();
    return 0;
}