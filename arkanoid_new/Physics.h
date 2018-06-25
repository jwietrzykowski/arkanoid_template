#pragma once

#include <vector>

#include "Figure.h" // #include "Figura.h"

namespace Inf
{

	struct Border {
		Border() : lowerLeftPt(0, 0), upperRightPt(0, 0) {}
		Border(const Vec2d &ilowerLeftPt, const Vec2d &iupperRightPt) :
			lowerLeftPt(ilowerLeftPt), upperRightPt(iupperRightPt)
		{}
		Vec2d lowerLeftPt, upperRightPt;
	};

	class Physics : public Figure
	{
	protected:
		int prevTime; //czas ostatniej aktualizacji
		Border border; //granice obiektu
		//polozenie srodka masy - odziedziczone po Figure
		Vec2d vel;
		Vec2d grav;

	public:
		Physics();
		~Physics();

		//zmienia polozenie obiektu na podstawie aktualnego czasu
		void update(int curTime);
		
		//ustawia poczatkowy czas, predkosc oraz przyspieszenie
		void initParams(int curTime, const Vec2d &iv, const Vec2d &ig);

		//wykrywanie kolizji z innym obiektem i aktualizacja prêdkoœci (funkcja zwraca true gdy jest kolizja, a false w przeciwnym razie)
		virtual bool collision(const Physics& X);

	protected:
		void setBorder(const Border &nborder);

	private:
		//odbicie od sciany charakteryzowanej za pomoca normalnej
		void rebound(const Vec2d &norm);
	};
}
