#ifndef VEHICLEMENAGMENTSYSTEM_ADDEDITVEHICLEPAGE_H
#define VEHICLEMENAGMENTSYSTEM_ADDEDITVEHICLEPAGE_H

#include "Page.h"

class AddEditVehiclePage : public virtual Page {
private:
    bool isEdit = false;
    bool isOpen = false;

    vector<Button *> btnVehicleChoices;
    vector<Button *> btnOptions;
    vector<Input *> inputs;
    VehicleType vehicleType = CAR;

public:
    AddEditVehiclePage(MainController *controller, RenderWindow *window, const Font &font);

    ~AddEditVehiclePage();

    void draw() override;

    bool isMouseOver() override;

    PageName mouseClick() override;

    void textEntered(Event &event);

private:
    void create() override;

    void prepare();

    void clear() override;

    void changeVehicleChoice(Button *&button);

    void prepareVehicleChoice(Button *&button);

    void updateVehicleType();

    void fillInputs();

    void clearInputs();

    void clearBtnOptions();

    void prepareInputs();

    void prepareBtnOptions();

    void chooseMouseClick();

    void disableVehicleChoice();

    void clearVehicleChoice();

    void saveData();
};

#endif //VEHICLEMENAGMENTSYSTEM_ADDEDITVEHICLEPAGE_H