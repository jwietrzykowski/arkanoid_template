#pragma once

namespace Inf
{
	struct Vec2d {
		Vec2d() : x(0), y(0) {}
		Vec2d(double ix, double iy) : x(ix), y(iy) {}

		//Vec2d operator+(const Vec2d &v1);
		//Vec2d operator*(double c);

		//double dot(const Vec2d &v1);
		//Vec2d cross(const Vec2d &v1);

		double x, y;
	};

	Vec2d operator+(const Vec2d &v1, const Vec2d &v2);
	Vec2d operator-(const Vec2d &v1, const Vec2d &v2);
	Vec2d operator*(const Vec2d &v1, double c);
	Vec2d operator*(double c, const Vec2d &v1);

	double dot(const Vec2d &v1, const Vec2d &v2);
	Vec2d cross(const Vec2d &v1, const Vec2d &v2);

	class Figure
	{
	public:
		Figure(double red, double green, double blue);
		~Figure();

		void show();
		void hide();
		void move(double dx, double dy);
		void setPosition(double x, double y);
		void rotate(double dgamma);
		void changeColour(double r, double g, double b);

		virtual void draw() = 0;

	protected:
		Vec2d pos;

		double rotZ;

		double cR;
		double cG;
		double cB;

		bool flagShow;
	};
}
