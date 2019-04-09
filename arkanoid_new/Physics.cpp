#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <algorithm>

#include "Physics.h"

using namespace Inf;


Physics::Physics()
{

}

Inf::Physics::Physics(const Vec2d &ipos, double icR, double icG, double icB, const BBox &ibbox)
	: Figure(ipos, icR, icG, icB), bbox(ibbox)
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
	bbox = nborder;
}


bool Physics::collision(const Physics& other) 
{
	// const value used for floating point comparison
	static const double eps = 1.0e-6;

	bool flagCollision = false;

	// coordinates of a recatangle that is an intersection of two rectangles
	double minX = std::max(pos.x + bbox.lowerLeftPt.x, other.pos.x + other.bbox.lowerLeftPt.x);
	double maxX = std::min(pos.x + bbox.upperRightPt.x, other.pos.x + other.bbox.upperRightPt.x);
	double minY = std::max(pos.y + bbox.lowerLeftPt.y, other.pos.y + other.bbox.lowerLeftPt.y);
	double maxY = std::min(pos.y + bbox.upperRightPt.y, other.pos.y + other.bbox.upperRightPt.y);
	double intLenX = maxX - minX;
	double intLenY = maxY - minY;

	// relative velocity
	Vec2d relVel = vel - other.vel;

	//if (maxX - minX > 0.0 && maxY - minY > 0.0) {
	//	std::cout << "maxX - minX = " << maxX - minX << std::endl;
	//	std::cout << "maxY - minY = " << maxY - minY << std::endl;
	//	std::cout << "relVel = (" << relVel.x << ", " << relVel.y << ")" << std::endl;
	//	std::cout << "vel = (" << vel.x << ", " << vel.y << ")" << std::endl;
	//}

	if (intLenX > 0.0 && intLenY > 0.0) {
		Vec2d norm(0, 0);

		// collision on vertical wall
		if (intLenY >= intLenX) {
			// if intersection starts at right wall and relative horizontal velocity is positive
			if (pos.x + bbox.lowerLeftPt.x < minX && relVel.x > 0.0) {
				norm = Vec2d(-1.0, 0.0);
				flagCollision = true;
			}
			// if intersection starts at left wall and relative horizontal velocity is negative
			else if (pos.x + bbox.upperRightPt.x > maxX && relVel.x < 0.0) {
				norm = Vec2d(1.0, 0.0);
				flagCollision = true;
			}
		}
		// collision on horizontal edge
		else {
			// if intersection starts at lower wall and relative vertical velocity is negative
			if (pos.y + bbox.upperRightPt.y > maxY && relVel.y < 0.0) {
				norm = Vec2d(0.0, 1.0);
				flagCollision = true;
			}
			// if intersection starts at upper wall and relative vertical velocity is positive
			else if (pos.y + bbox.lowerLeftPt.y < minY && relVel.y > 0.0) {
				norm = Vec2d(0.0, -1.0);
				flagCollision = true;
			}
		}
		if (flagCollision) {
			//std::cout << "norm = (" << norm.x << ", " << norm.y << ")" << std::endl;
			rebound(norm);
		}
	}

	return flagCollision;
}

void Physics::rebound(const Vec2d &norm)
{
	double velNorm = dot(norm, vel);
	// reverse movement direction in normal direction
	vel = vel - 2 * velNorm * norm;
}

