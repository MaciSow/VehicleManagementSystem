#include "GraphicView.h"

GraphicView::GraphicView(MainController *&ctr) {
    this->controller = ctr;

    createWindow();
    pageName = PageName::home;
    homePage = new HomePage(controller, window, font);
    fleetStatePage = new FleetStatePage(controller, window, font);
    showVehiclesPage = new ShowVehiclesPage(controller, window, font);
    vehicleDataPage = new VehicleDataPage(controller, window, font);
    showRegisterPage = new ShowRegisterPage(controller, window, font);
    showRepairsPage = new ShowRepairsPage(controller, window, font);
    addEditVehiclePage = new AddEditVehiclePage(controller, window, font);
    basePage = new BasePage(controller, window, font);
    closePage = new ClosePage(controller, window, font);
}

GraphicView::~GraphicView() = default;

void GraphicView::start() {
    while (window->isOpen()) {
        Event event;

        while (window->pollEvent(event)) {
            switch (event.type) {
                case Event::KeyPressed:
                    if (event.key.code == Keyboard::Escape) {
                        window->close();
                    }
                    break;

                case Event::TextEntered:
                    textEnteredHandle(event);
                    break;

                case Event::MouseMoved:
                    mouseMovedHandle();
                    break;

                case Event::MouseButtonPressed:
                    mouseButtonPressedHandle(event);
                    break;

                case Event::MouseWheelMoved:
                    mouseWheelMovedHandle(event);
                    break;

                case Event::Closed:
                    window->close();
                    break;

                default:
                    break;
            }
        }

        window->clear();
        createBackground();
        drawPage();
        window->setMouseCursor(cursor);
        window->display();

        if (pageName == PageName::close) {
            cleanPage();
            window->close();
        }
    }
}

void GraphicView::textEnteredHandle(Event &event) {
    switch (pageName) {
        case PageName::addEditVehicle:
            addEditVehiclePage->textEntered(event);
            break;


        default:
            break;
    }
}

void GraphicView::mouseMovedHandle() {
    bool isCursorChange = false;

    switch (pageName) {
        case PageName::home:
            if (homePage->isMouseOver()) {
                isCursorChange = true;
            }
            break;

        case PageName::fleetState:
            if (fleetStatePage->isMouseOver()) {
                isCursorChange = true;
            }
            break;

        case PageName::showVehicles:
            if (showVehiclesPage->isMouseOver()) {
                isCursorChange = true;
            }
            break;

        case PageName::vehicleData:
            if (vehicleDataPage->isMouseOver()) {
                isCursorChange = true;
            }
            break;

        case PageName::showRegister:
            if (showRegisterPage->isMouseOver()) {
                isCursorChange = true;
            }
            break;

        case PageName::showRepairs:
            if (showRepairsPage->isMouseOver()) {
                isCursorChange = true;
            }
            break;

        case PageName::addEditVehicle:
            if (addEditVehiclePage->isMouseOver()) {
                isCursorChange = true;
            }
            break;

        case PageName::base:
            if (basePage->isMouseOver()) {
                isCursorChange = true;
            }
            break;

        case PageName::close:
            if (closePage->isMouseOver()) {
                isCursorChange = true;
            }
            break;

        default:
            break;
    }

    if (isCursorChange) {
        cursor.loadFromSystem(Cursor::Hand);
    } else {
        cursor.loadFromSystem(Cursor::Arrow);
    }
}

void GraphicView::mouseButtonPressedHandle(Event &event) {
    if (event.key.code == (int) Mouse::Left) {
        switch (pageName) {

            case PageName::home:
                pageName = homePage->mouseClick();
                break;

            case PageName::fleetState:
                pageName = fleetStatePage->mouseClick();
                break;

            case PageName::showVehicles:
                pageName = showVehiclesPage->mouseClick();
                break;

            case PageName::vehicleData:
                pageName = vehicleDataPage->mouseClick();
                break;

            case PageName::showRegister:
                pageName = showRegisterPage->mouseClick();
                break;

            case PageName::showRepairs:
                pageName = showRepairsPage->mouseClick();
                break;

            case PageName::addEditVehicle:
                pageName = addEditVehiclePage->mouseClick();
                break;

            case PageName::base:
                pageName = basePage->mouseClick();
                break;

            case PageName::close:
                pageName = closePage->mouseClick();
                break;

            default:
                break;

        };
    }
}

void GraphicView::mouseButtonReleasedHandle() {

}

void GraphicView::mouseWheelMovedHandle(Event &event) {
    switch (pageName) {
        case PageName::showVehicles:
            showVehiclesPage->scroll(event.mouseWheel.delta);
            break;

        case PageName::showRegister:
            showRegisterPage->scroll(event.mouseWheel.delta);
            break;

        case PageName::showRepairs:
            showRepairsPage->scroll(event.mouseWheel.delta);
            break;

        default:
            break;
    };
}

void GraphicView::drawPage() {
    int frameHeight = 380;
    int framePosY = 90;
    string vehicleType = "";

    switch (pageName) {
        case PageName::home:
            createTitle("Vehicle Management System");
            homePage->draw();
            break;

        case PageName::fleetState:
            createTitle("Fleet state");
            createFrame(width - 200, frameHeight, framePosY);
            fleetStatePage->draw();
            break;

        case PageName::showVehicles:
            createTitle("Show vehicles");
            createFrame(width - 200, frameHeight, framePosY);
            showVehiclesPage->draw();
            break;

        case PageName::vehicleData:
            vehicleType = controller->getSelectedVehicle()->getVehicleTypeName();
            createTitle(vehicleType + " data");
            createFrame(width - 200, frameHeight, framePosY);
            vehicleDataPage->draw();
            break;

        case PageName::showRegister:
            createTitle("Show register");
            createFrame(width - 200, frameHeight, framePosY);
            showRegisterPage->draw();
            break;

        case PageName::showRepairs:
            createTitle("Show repairs");
            createFrame(width - 200, frameHeight, framePosY);
            showRepairsPage->draw();
            break;

        case PageName::addEditVehicle:
            createTitle("Add Vehicle");
            createFrame(width - 200, frameHeight, framePosY);
            addEditVehiclePage->draw();
            break;

        case PageName::base:
            createTitle("Base Page");
            createFrame(width - 200, frameHeight, framePosY);
            basePage->draw();
            break;

        case PageName::close:
            createTitle("Save file");
            createFrame(width - 200, 300, height / 2 - 150);
            closePage->draw();
            break;

        default:
            break;
    };
}

void GraphicView::createWindow() {
    loadFont();

    window = new RenderWindow(VideoMode(width, height), "Vehicle Menagment System", Style::Titlebar | Style::Close);

    window->display();
    View view(FloatRect(0, 0, float(width), float(height)));
    window->setView(view);
}

void GraphicView::createTitle(string title) {
    Text text(title, font, 36);
    text.setPosition(50, 16);
    text.setFillColor({0, 0, 0, 200});

    RectangleShape line({(float) width - 100, 2});
    line.setFillColor({0, 0, 0, 200});
    line.move(50, 64);

    window->draw(text);
    window->draw(line);
}

void GraphicView::createFrame(int width, int height, int offsetY) {
    RectangleShape frame;

    frame.setSize({(float) width, (float) height});
    frame.setPosition((float) (this->width - width) / 2, (float) offsetY);
    frame.setFillColor({255, 255, 255, 160});

    window->draw(frame);
}

void GraphicView::createBackground() {
    Sprite background;
    Texture texture;

    if (!texture.loadFromFile(resourcePath + "bgr.jpg")) {
        cout << "Fail load bgr";
    }

    background.setTexture(texture);
//    background.setScale(0.5, 0.5);

    window->draw(background);
}

void GraphicView::cleanPage() {
    delete homePage;
    delete closePage;
    controller->clean();
}

void GraphicView::loadFont() {
    if (!font.loadFromFile(resourcePath + "font.ttf")) {
        cout << "Fail load font";
    }
}
