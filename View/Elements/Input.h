#ifndef VEHICLEMENAGMENTSYSTEM_VIEW_INPUT_H
#define VEHICLEMENAGMENTSYSTEM_VIEW_INPUT_H

#include <SFML/Graphics.hpp>
#include "iostream"
#include "sstream"
#include "math.h"

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

using namespace std;
using namespace sf;

class Input {
private:
	Text input;
	Text label;
	RectangleShape frame;

	string id = "";
	ostringstream text;
	bool isSelected = false;
	float width = 250;
	float height = 40;
	int limit = (int)floor((width-20)/10);
	int fontSize = 16;
	bool isNumber = false;
	bool isEditable = true;

    enum State {
		inactive,
		hover,
		active
	};

	void create(Vector2f position, Font& font, string label);
	void setInputState(State state);
	void inputLogic(int charTyped);
	void deleteLastChar();
	void addSlash();


public:
	Input(Vector2f position, Font& font ,string label = "", float width = 250, string id = "" );
	~Input();

	void setIsNumber(bool isNumber = true);
	void setValue(string value);
	void setWidth(float width);
	void setLimit(int limit);
	string getId();
	bool isMouseOver(RenderWindow*& window);
	void checkSelection(RenderWindow*& window);
	void setSelected(bool isSelected);
	void typeOn(Event input);
	void drawTo(RenderWindow*& window);
	void clear();
	bool validate();
	string getText();
    void setLabel(string label);
    bool getIsEditable() const;
    void setIsEditable(bool isEditable);
};

#endif  //VEHICLEMENAGMENTSYSTEM_VIEW_INPUT_H