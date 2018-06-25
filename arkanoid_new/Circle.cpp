#define _USE_MATH_DEFINES

#include "Circle.h"

#define NDEBUG
#include <GL/freeglut.h>


#include <cmath>

using namespace Inf;

Circle::Circle(double irad, double red, double green, double blue)
	: Physics(),
	rad(irad)
{
	//setBorders(
	//	-rad, -rad,
	//	rad, rad
	//	);

	cR = red;
	cG = green;
	cB = blue;
}

Circle::~Circle()
{
}

void Circle::draw()
{
	if (flagShow)
	{
		glPushMatrix();
		{
			glTranslated(pos.x, pos.y, 0.0);
			glRotated(rotZ, 0.0, 0.0, 1.0);

			glColor3d(cR, cG, cB);

			glBegin(GL_TRIANGLE_FAN);
			{

				for (int i = 0; i <= 360; i++)
				{
					// 180 - pi
					// i - degInRad

					double degInRad = i*M_PI / 180;
					glVertex2f(cos(degInRad)*rad, sin(degInRad)*rad);
				}
			}
			glEnd();

		}
		glPopMatrix();
	}
}

