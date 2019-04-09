#pragma once

#include "Physics.h"

namespace Inf
{
	class Circle : public Physics
	{
	public:
		Circle();
		Circle(double ix, double iy, double irad, double red, double green, double blue);
		~Circle();

		void draw();

	private:
		double rad;
	};
}

