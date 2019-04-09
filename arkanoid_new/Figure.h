#pragma once

namespace Inf
{
	struct Vec2d {
		Vec2d() : x(0), y(0) {}
		Vec2d(double ix, double iy) : x(ix), y(iy) {}

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
		Figure();
		Figure(const Vec2d &ipos, double icR, double icG, double icB);
		~Figure();

		void show();
		void hide();
		void move(double dx, double dy);
		void setPosition(double x, double y);
		void rotate(double dtheta);
		void changeColor(double r, double g, double b);

		virtual void draw() = 0;

	protected:
		Vec2d pos;

		double theta;

		double cR;
		double cG;
		double cB;

		bool flagShow;
	};
}
