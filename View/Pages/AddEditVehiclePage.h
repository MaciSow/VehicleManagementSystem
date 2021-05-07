#ifndef VEHICLEMENAGMENTSYSTEM_ADDEDITVEHICLEPAGE_H
#define VEHICLEMENAGMENTSYSTEM_ADDEDITVEHICLEPAGE_H

#include "Page.h"
#include "../Elements/Input.h"

class AddEditVehiclePage : public virtual Page {
private:
    Button *btnSave;
    vector<Button *> vehicleChoice;
    vector<Button *> btnChoose;
    vector<Input *> inputs;
    VehicleType vehicleType = CAR;

    void clear() override;

    void changeVehicle(Button *&button);

    void checkVehicle();

    void clearInputs();

    void clearBtnChoose();

    void prepareInputs();

    void prepareBtnChoose();

    void chooseMouseClick();

    void saveData();
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