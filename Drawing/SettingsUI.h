#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"
#include "Shape.h"

// finish this code; add functions, data as needed

const int TEXT_X = 30;
const int SHAPE_X = 45;
const int CHANGE_IN_Y = 45;
const int TEXT_Y_COLOR = 35;
const int TEXT_Y_SHAPE = TEXT_Y_COLOR + 250;
const int COLOR_Y_START = TEXT_Y_COLOR + 40;
const int SHAPE_Y_START = TEXT_Y_SHAPE + 40;

void die(string msg);

class SettingsUI
{
private:
	SettingsMgr *Manager;
	Circle RedBtn, BlueBtn, GreenBtn, CircleBtn;
	Square SquareBtn;
	Font font;
	Text SelColor, SelShape;
public:
	SettingsUI(SettingsMgr *mgr)
	{
		if (!font.loadFromFile("arial.ttf"))
			die("Font Load Error.");
		Manager = mgr;
		setText();
		setButtons();
	}
	void handleMouseUp(Vector2f mouse)
	{
		if (RedBtn.getBounds().contains(mouse))
			setRed();
		else if (GreenBtn.getBounds().contains(mouse))
			setGreen();
		else if (BlueBtn.getBounds().contains(mouse))
			setBlue();
		else if (SquareBtn.getBounds().contains(mouse))
			setSquare();
		else if (CircleBtn.getBounds().contains(mouse))
			setCircle();
	}

	void draw(RenderWindow& win)
	{
		win.draw(SelColor);
		win.draw(SelShape);
		RedBtn.draw(&win);
		GreenBtn.draw(&win);
		BlueBtn.draw(&win);
		CircleBtn.draw(&win);
		SquareBtn.draw(&win);
	}

	void die(string msg)
	{
		cout << msg << endl;
		exit(-1);
	}

	void setButtons()
	{
		RedBtn.setColor(Color::Red, Color::Black);
		RedBtn.setPos(Vector2f(SHAPE_X, COLOR_Y_START));
		GreenBtn.setColor(Color::Black, Color::Green);
		GreenBtn.setPos(Vector2f(SHAPE_X, RedBtn.getPos().y + CHANGE_IN_Y));
		BlueBtn.setColor(Color::Black, Color::Blue);
		BlueBtn.setPos(Vector2f(SHAPE_X, GreenBtn.getPos().y + CHANGE_IN_Y));
		CircleBtn.setColor(Color::White, Color::Black);
		CircleBtn.setPos(Vector2f(SHAPE_X, SHAPE_Y_START));
		SquareBtn.setColor(Color::Black, Color::White);
		SquareBtn.setPos(Vector2f(SHAPE_X, CircleBtn.getPos().y + CHANGE_IN_Y));
	}

	void setText()
	{
		SelColor.setString("Selected Color:");
		SelColor.setFont(font);
		SelColor.setPosition(Vector2f(TEXT_X, TEXT_Y_COLOR));
		SelShape.setString("Selected Shape:");
		SelShape.setFont(font);
		SelShape.setPosition(Vector2f(TEXT_X, TEXT_Y_SHAPE));
	}

	void setGreen()
	{
		RedBtn.setColor(Color::Black, Color::Red);
		GreenBtn.setColor(Color::Green, Color::Black);
		BlueBtn.setColor(Color::Black, Color::Blue);
		Manager->setColor(Color::Green);
	}

	void setRed()
	{
		RedBtn.setColor(Color::Red, Color::Black);
		GreenBtn.setColor(Color::Black, Color::Green);
		BlueBtn.setColor(Color::Black, Color::Blue);
		Manager->setColor(Color::Red);
	}

	void setBlue()
	{
		RedBtn.setColor(Color::Black, Color::Red);
		GreenBtn.setColor(Color::Black, Color::Green);
		BlueBtn.setColor(Color::Blue, Color::Black);
		Manager->setColor(Color::Blue);
	}

	void setCircle()
	{
		CircleBtn.setColor(Color::White, Color::Black);
		SquareBtn.setColor(Color::Black, Color::White);
		Manager->setShape(CIRCLE);
	}

	void setSquare()
	{
		CircleBtn.setColor(Color::Black, Color::White);
		SquareBtn.setColor(Color::White, Color::Black);
		Manager->setShape(SQUARE);
	}
};
