#include <iostream>
#include <SFML/Window.hpp>

using namespace sf;

int main() {
    Window window(sf::VideoMode(800, 600), "Vehicle Management System");

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    return 0;
}

