#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <algorithm>

#include "Physics.h"

using namespace Inf;


Physics::Physics()
	: Figure(0.5, 0.5, 0.5)
{

}

Physics::~Physics()
{
}

void Physics::update(int curTime) 
{
	double dt = (curTime - prevTime) / 1000.0;

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

void Physics::setBBox(const BBox &nborder)
{
	border = nborder;
}


bool Physics::collision(const Physics& other) 
{
	// const value used for floating point comparison
	static const double eps = 1.0e-6;

	bool flagCollision = false;

	// coordinates of a recatangle that is an intersection of two rectangles
	double minX = std::max(pos.x + border.lowerLeftPt.x, other.pos.x + other.border.lowerLeftPt.x);
	double maxX = std::min(pos.x + border.upperRightPt.x, other.pos.x + other.border.upperRightPt.x);
	double minY = std::max(pos.y + border.lowerLeftPt.y, other.pos.y + other.border.lowerLeftPt.y);
	double maxY = std::min(pos.y + border.upperRightPt.y, other.pos.y + other.border.upperRightPt.y);

	// relative velocity
	Vec2d relVel = vel - other.vel;
	Vec2d relPos = pos - other.pos;

	// dot product of relative position and relative velocity
	// if objects are moving closer to each other this value is greater than 0.0
	// prevents multiple rebounds
	double velPosDot = dot(relVel, relPos);

	if (maxX - minX > 0.0 && maxY - minY > 0.0) {
		std::cout << "maxX - minX = " << maxX - minX << std::endl;
		std::cout << "maxY - minY = " << maxY - minY << std::endl;
		std::cout << "velPosDot = " << velPosDot << std::endl;
	}
	// if the area of the intersection is greater than 0.0
	if (maxX - minX > 0.0 && maxY - minY > 0.0/* && velPosDot < 0.0*/) {
		std::cout << "Collision detected" << std::endl;

		flagCollision = true;

		Vec2d norm(0, 0);

		double intLenX = maxX - minX;
		double intLenY = maxY - minY;
		if (intLenY >= intLenX) {
			// if intersection starts at left border
			if (pos.x + border.lowerLeftPt.x < minX) {
				norm = Vec2d(-1.0, 0.0);
			}
			else if (pos.x + border.upperRightPt.x > maxX) {
				norm = Vec2d(1.0, 0.0);
			}
		}
		else {
			if (pos.y + border.upperRightPt.y > maxY) {
				norm = Vec2d(0.0, 1.0);
			}
			else if (pos.y + border.lowerLeftPt.y < minY) {
				norm = Vec2d(0.0, -1.0);
			}
		}

		std::cout << "norm = (" << norm.x << ", " << norm.y << ")" << std::endl;
		rebound(norm);
	}

	return flagCollision;
}

void Physics::rebound(const Vec2d &norm)
{
	std::cout << "vel = (" << vel.x << ", " << vel.y << ")" << std::endl;
	double velNorm = dot(norm, vel);
	std::cout << "velNorm = " << velNorm << std::endl;
	vel = vel - 2 * velNorm * norm;
}

