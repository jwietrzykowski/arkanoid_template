#pragma once

#include "Physics.h"

namespace Inf
{
	class Rectangle : public Physics
	{
	public:
		Rectangle(double iwidth, double iheight, double red, double green, double blue);
		~Rectangle();

		void draw();

	private:
		double width;
		double height;
	};
}
