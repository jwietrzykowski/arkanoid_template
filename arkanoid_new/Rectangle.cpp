#include "Rectangle.h"

#define NDEBUG
#include <GL/freeglut.h>

using namespace Inf;

Rectangle::Rectangle(double iwidth, double iheight, double red, double green, double blue) 
	: Physics(),
	width(iwidth), height(iheight)
{
	//setBorders(
	//	-width / 2, -height/2,
	//	width / 2, height / 2
	//	);

	cR = red;
	cG = green;
	cB = blue;
}

Rectangle::~Rectangle()
{
}

void Rectangle::draw()
{
	if (flagShow)
	{
		glPushMatrix();
		{
			glTranslated(pos.x, pos.y, 0.0);
			glRotated(rotZ, 0.0, 0.0, 1.0);

			glColor3d(cR, cG, cB);

			glBegin(GL_POLYGON);
			{
				glVertex3d(-width / 2, height / 2, 0);
				glVertex3d(width / 2, height / 2, 0);
				glVertex3d(width / 2, -height / 2, 0);
				glVertex3d(-width / 2, -height / 2, 0);
			}
			glEnd();
		}
		glPopMatrix();
	}
}