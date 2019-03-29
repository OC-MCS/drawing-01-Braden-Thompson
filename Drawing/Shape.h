#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// finish this code; add functions, classes, data as needed
struct getFile
{
	unsigned int color;
	ShapeEnum size;
	Vector2f position;
};
// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{
private:
	getFile file;
public:
	virtual void setColor(Color fillColor, Color outlineColor) = 0;
	virtual void setPos(Vector2f pos) = 0;
	virtual FloatRect getBounds() = 0;
	virtual Vector2f getPos() = 0;
	virtual void draw(RenderWindow * win) = 0;
	getFile getDoc()
	{
		return file;
	}
};

class Circle : public DrawingShape
{
private:
	CircleShape Circ;
public:
	Circle()
	{
		Circ.setOutlineThickness(2);
		Circ.setRadius(10);
	}

	Circle(Vector2f pos, Color col)
	{
		Circ.setPosition(pos);
		Circ.setFillColor(col);
		Circ.setOutlineColor(col);
		Circ.setOutlineThickness(2);
		Circ.setRadius(10);
	}

	void setColor(Color fillColor, Color outlineColor)
	{
		Circ.setFillColor(fillColor);
		Circ.setOutlineColor(outlineColor);
	}

	void setPos(Vector2f pos)
	{
		Circ.setPosition(pos);
	}

	FloatRect getBounds()
	{
		return Circ.getGlobalBounds();
	}

	Vector2f getPos()
	{
		return Circ.getPosition();
	}

	void draw(RenderWindow * win)
	{
		win->draw(Circ);
	}
};

class Square : public DrawingShape
{
private:
	RectangleShape Sqr;
public:
	Square()
	{
		Sqr.setOutlineThickness(2);
		Sqr.setSize(Vector2f(20.0, 20.0));
	}

	Square(Vector2f pos, Color col)
	{
		Sqr.setPosition(pos);
		Sqr.setFillColor(col);
		Sqr.setOutlineColor(col);
		Sqr.setOutlineThickness(2);
		Sqr.setSize(Vector2f(20.0, 20.0));

	}

	void setColor(Color fillColor, Color outlineColor)
	{
		Sqr.setFillColor(fillColor);
		Sqr.setOutlineColor(outlineColor);
	}

	void setPos(Vector2f pos)
	{
		Sqr.setPosition(pos);
	}

	void setSize(int x, int y)
	{
		Sqr.setSize(Vector2f(x, y));
	}

	void setOutline(int thickness)
	{
		Sqr.setOutlineThickness(thickness);
	}

	FloatRect getBounds()
	{
		return Sqr.getGlobalBounds();
	}

	Vector2f getPos()
	{
		return Sqr.getPosition();
	}

	void draw(RenderWindow * win)
	{
		win->draw(Sqr);
	}
};



