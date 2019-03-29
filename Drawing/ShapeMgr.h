#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

// finish the ShapeMgr class.

class ShapeMgr
{
private:
	vector<DrawingShape *> Shape;
	getFile file;
public:
	ShapeMgr()
	{
		
	}

	void load()
	{
		fstream file;
		file.open("shapes.bin", ios::in | ios::binary);
		if (!file)
		{
			cout << "Could not load" << endl;
			exit(-1);
		}
		while (file)
		{
			getFile	temp;
			file.read(reinterpret_cast<char*>(&temp), sizeof(temp));

			Color temp_color(temp.color);
			if (temp.size == CIRCLE)
			{
				Shape.push_back(new Circle(temp.position, temp_color));
			}
			else {
				Shape.push_back(new Square(temp.position, temp_color));
			}
		}
	}
	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		pos.x -= 10;
		pos.y -= 10;
		if (whichShape == CIRCLE)
		{
			Circle * Circ = new Circle(pos, color);
			Shape.push_back(Circ);
		}

		else if (whichShape == SQUARE)
		{
			Square * Sqr = new Square(pos, color);
			Shape.push_back(Sqr);
		}
	}

	int getVecSize()
	{
		return Shape.size();
	}

	DrawingShape* getVec(int count)
	{
		return Shape[count];
	}

	~ShapeMgr()
	{
		fstream File;
		File.open("shapes.bin", ios::out | ios::binary);
		for (int i = 0; i < Shape.size(); i++)
		{
			file = (Shape[i]->getDoc());
			File.write(reinterpret_cast<char *>(&file), sizeof(getFile));
		}
		while (!Shape.empty())
		{
			Shape.pop_back();
		}
	}
};
