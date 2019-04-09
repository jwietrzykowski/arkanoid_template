#pragma once

#include <vector>

#include "Figure.h"

namespace Inf
{

	struct BBox {
		BBox() : lowerLeftPt(0, 0), upperRightPt(0, 0) {}
		BBox(const Vec2d &ilowerLeftPt, const Vec2d &iupperRightPt) :
			lowerLeftPt(ilowerLeftPt), upperRightPt(iupperRightPt)
		{}
		Vec2d lowerLeftPt, upperRightPt;
	};

	class Physics : public Figure
	{
	public:
		Physics();
		Physics(const Vec2d &ipos, double icR, double icG, double icB, const BBox &ibbox);
		~Physics();

		// changes position of the object using current time, velocity, and gravity.
		void update(int curTime);
		
		// sets initial time, velocity, and gravity
		void initParams(int curTime, const Vec2d &iv, const Vec2d &ig);

		// detects whether there is a collision with X object and rebounds object if necessary
		// returns true if collision occured
		virtual bool collision(const Physics& X);

	protected:
		void setBBox(const BBox &nborder);


		// time of the last update
		int prevTime;
		// bounding box of the object
		BBox bbox;
		// position of the mass center - inherited from Figure

		// velocity
		Vec2d vel;
		// gravity vector
		Vec2d grav;
	private:
		// rebound from the wall characterized by the normal vector
		void rebound(const Vec2d &norm);
	};
}
