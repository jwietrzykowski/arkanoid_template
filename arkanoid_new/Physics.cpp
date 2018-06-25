#include "Physics.h"

#define _USE_MATH_DEFINES
#include <cmath>
#include <algorithm>

using namespace Inf;


Physics::Physics()
	: Figure(0.5, 0.5, 0.5)
{

}

Physics::~Physics()
{
}

//zmienia polozenie obiektu na podstawie aktualnego czasu
void Physics::update(int curTime) 
{
	double dt = curTime - prevTime;

	pos = pos + vel * dt + grav * (dt * dt / 2.0);

	vel = vel + grav * dt;

	prevTime = curTime;
}

void Physics::initParams(int curTime, const Vec2d &iv, const Vec2d &ig)
{
	prevTime = curTime;

	vel = iv;
	grav = ig;
}

void Physics::setBorder(const Border &nborder)
{
	border = nborder;
}

//wykrywanie kolizji z innym obiektem i aktualizacja prêdkoœci (funkcja zwraca true gdy jest kolizja, a false w przeciwnym razie)
bool Physics::collision(const Physics& other) 
{
	// const value used for floating point comparison
	static const double eps = 1.0e-6;

	bool flagCollision = false;

	// coordinates of a recatangle that is an intersection of two rectangles
	double minX = std::max(border.lowerLeftPt.x, other.border.lowerLeftPt.x);
	double maxX = std::min(border.upperRightPt.x, other.border.upperRightPt.x);
	double minY = std::max(border.lowerLeftPt.y, other.border.lowerLeftPt.y);
	double maxY = std::min(border.upperRightPt.y, other.border.upperRightPt.y);

	// relative velocity
	Vec2d relVel = vel - other.vel;
	Vec2d relPos = pos - other.pos;

	// dot product of relative position and relative velocity
	// if objects are moving closer to each other this value is greater than 0.0
	// prevents multiple rebounds
	double velPosDot = dot(relVel, relPos);

	// if the area of the intersection is greater than 0.0
	if (maxX - minX > 0.0 && maxY - minY > 0.0 && velPosDot > 0.0) {
		flagCollision = true;

		Vec2d norm;

		double intLenX = maxX - minX;
		double intLenY = maxY - minY;
		if (intLenY >= intLenX) {
			// if intersection starts at left border
			if (abs(border.lowerLeftPt.x - minX) < eps) {
				norm = Vec2d(-1.0, 0.0);
			}
			else if (abs(border.upperRightPt.x - maxX) < eps) {
				norm = Vec2d(1.0, 0.0);
			}
		}
		else {
			if (abs(border.lowerLeftPt.y - minY) < eps) {
				norm = Vec2d(0.0, -1.0);
			}
			else if (abs(border.upperRightPt.y - maxY) < eps) {
				norm = Vec2d(0.0, 1.0);
			}
		}

		rebound(norm);
	}

	return flagCollision;
}

// odbicie od sciany charakteryzowanej za pomoca normalnej
void Physics::rebound(const Vec2d &norm)
{
	double velNorm = dot(norm, vel);
	vel = vel + 2 * velNorm * norm;
}

