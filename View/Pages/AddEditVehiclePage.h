#ifndef VEHICLEMENAGMENTSYSTEM_ADDEDITVEHICLEPAGE_H
#define VEHICLEMENAGMENTSYSTEM_ADDEDITVEHICLEPAGE_H

#include "Page.h"
#include "../Elements/Input.h"

class AddEditVehiclePage : public virtual Page {
private:
    Button *btnSave;
    vector<Button *> vehicleChoice;

    vector<Input *> inputs;
    vector<Button *> btnChoose;
    VehicleType vehicleType = CAR;

    void clear() override;

    void changeVehicle(Button *&button);

    void checkVehicle();

    void clearInputs();

    void clearBtnChoose();

    void prepareInputs();

    void prepareBtnChoose();

public:
    AddEditVehiclePage(MainController *controller, RenderWindow *window, const Font &font);

    ~AddEditVehiclePage();

    void textEntered(Event &event);

    bool isMouseOver();

    PageName mouseClick() override;

    void create() override;

    void draw() override;
};

#endif //VEHICLEMENAGMENTSYSTEM_ADDEDITVEHICLEPAGE_H