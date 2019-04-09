#define _USE_MATH_DEFINES
#include <cmath>

#define NDEBUG
#include <GL/freeglut.h>

#include "Circle.h"

using namespace Inf;

Circle::Circle()
	: rad(0.5)
{

}

Circle::Circle(double ix, double iy, double irad, double red, double green, double blue)
	: Physics(Vec2d(ix, iy), red, green, blue, BBox(Vec2d(-irad, -irad), Vec2d(irad, irad))),
	rad(irad)
{

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
			glRotated(theta, 0.0, 0.0, 1.0);

			glColor3d(cR, cG, cB);

			glBegin(GL_POLYGON);
			{

				for (int i = 0; i <= 360; i++)
				{
					// rotation angle in radians
					double ang = i * M_PI / 180;
					glVertex2f(cos(ang)*rad, sin(ang)*rad);
				}
			}
			glEnd();

		}
		glPopMatrix();
	}
}

