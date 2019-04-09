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

Figure::Figure()
	: pos(Vec2d(0.0, 0.0)), cR(0.0), cG(0.0), cB(0.0), theta(0.0), flagShow(true)
{
}

Figure::Figure(const Vec2d & ipos, double icR, double icG, double icB)
	: pos(ipos), cR(icR), cG(icG), cB(icB), theta(0.0), flagShow(true)
{
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

void Figure::rotate(double dtheta)
{
	theta += dtheta;
}

void Figure::changeColor(double r, double g, double b)
{
	cR = r;
	cG = g;
	cB = b;
}