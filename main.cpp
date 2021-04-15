#include <iostream>
#include <SFML/Window.hpp>

#include "View/GraphicView.h"

using namespace sf;

int main() {
    MainController* c1 = new MainController();

    GraphicView* view = new GraphicView(c1);
    view->start();

    c1->clean();



//    Window window(sf::VideoMode(800, 600), "Vehicle Management System");
//
//    while (window.isOpen()) {
//        Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//    }
    return 0;
}

