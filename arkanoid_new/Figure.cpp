#include "Figure.h"

using namespace Inf;

Vec2d Inf::operator+(const Vec2d & v1, const Vec2d &v2)
{
	return Vec2d(v1.x + v2.x, v1.y + v2.y);
}

Vec2d Inf::operator-(const Vec2d & v1, const Vec2d &v2)
{
	return Vec2d(v1.x - v2.x, v1.y - v2.y);
}

Vec2d Inf::operator*(const Vec2d & v1, double c)
{
	return Vec2d(c * v1.x, c * v1.y);
}

Vec2d Inf::operator*(double c, const Vec2d & v1)
{
	return v1 * c;
}

double Inf::dot(const Vec2d & v1, const Vec2d &v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

Vec2d Inf::cross(const Vec2d & v1, const Vec2d &v2)
{
	return Vec2d();
}

Figure::Figure(double red, double green, double blue)
	: cR(red), cG(green), cB(blue)
{
	pos.x = 0.0;
	pos.y = 0.0;
	rotZ = 0.0;
	flagShow = true;
}

Figure::~Figure()
{
}

void Figure::show()
{
	flagShow = true;
}

void Figure::hide()
{
	flagShow = false;
}

void Figure::move(double dx, double dy)
{
	pos.x += dx;
	pos.y += dy;
}

void Figure::setPosition(double x, double y)
{
	pos.x = x;
	pos.y = y;
}

void Figure::rotate(double drotZ)
{
	rotZ += drotZ;
}

void Figure::changeColour(double r, double g, double b)
{
	cR = r;
	cG = g;
	cB = b;
}