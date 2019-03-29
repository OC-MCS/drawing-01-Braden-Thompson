#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

// finish this code; add functions, data as needed

class DrawingUI
{
private:
	Square fieldOutline;
	Square field;
public:
	DrawingUI(Vector2f p)
	{
		field.setColor(Color::Black, Color::Black);
		field.setPos(p);
		field.setSize(455, 485);
		field.setOutline(0);
		fieldOutline.setColor(Color::Transparent, Color::White);
		fieldOutline.setPos(Vector2f(p.x - 2.5, p.y));
		fieldOutline.setSize(470, 520);
		fieldOutline.setOutline(10);
	}

	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		DrawingShape* temp;
		vector<DrawingShape *> ptr;
		field.draw(&win);
		if (mgr->getVecSize() > 0);
		{
			for (int i = 0; i < mgr->getVecSize(); i++)
			{
				ptr.push_back(mgr->getVec(i));
				ptr[i]->draw(&win);
			}
		}

		fieldOutline.draw(&win);
	}
	
	bool isMouseInCanvas(Vector2f mousePos)
	{
		bool isInField = false;
		if (field.getBounds().contains(mousePos))
		{
			isInField = true;
		}
		return isInField;
	}

};

