#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

// finish this code; add functions, data as needed

class SettingsMgr
{
private:
	Color colorUse;
	ShapeEnum shapeUse;
public:
	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
		colorUse = startingColor;
		shapeUse = startingShape;
	}

	Color getCurColor()
	{
		return colorUse; 
	}


	ShapeEnum getCurShape()
	{
		return shapeUse;
	}

	void setColor(Color newColor)
	{
		colorUse = newColor;
	}

	void setShape(ShapeEnum newShape)
	{
		shapeUse = newShape;
	}
};
