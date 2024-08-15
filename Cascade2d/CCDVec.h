#pragma once

#include "CCDSize.h"


namespace cascade {
	class Vec {
	public:
		float x;
		float y;
		Vec() : x(0), y(0) {}
		Vec(float x, float y) : x(x), y(y) {}

		Vec operator / (float num) {
			return Vec(x / num, y / num);
		}

		Vec(Size size) : x(size.width), y(size.height) {}

		bool operator == (Vec v) {
			return (v.x == x && v.y == y);
		}
		bool operator != (Vec v) {
			return (v.x != x || v.y != y);
		}
	};
}