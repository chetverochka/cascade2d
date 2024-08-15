#pragma once
#include <cstdint>

using colorInt = uint8_t;

namespace cascade {
	class ColorRGBA {
	public:
		colorInt r;
		colorInt g;
		colorInt b;
		colorInt a;

		ColorRGBA() : r(255), g(255), b(255), a(255) {}
		ColorRGBA(colorInt r, colorInt g, colorInt b, colorInt a) : r(r), g(g), b(b), a(a) {}
		ColorRGBA(colorInt r, colorInt g, colorInt b) : r(r), g(g), b(b), a(255) {}

		static const ColorRGBA CCD_TRANSPARENT;
		static const ColorRGBA BLACK;
		static const ColorRGBA YELLOW;
		static const ColorRGBA BLUE;
		static const ColorRGBA WHITE;
		static const ColorRGBA RED;
	};

	class Color4F {
	public:
		float r;
		float g;
		float b;
		float a;
		Color4F() : r(0), g(0), b(0), a(1) {}
		Color4F(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}
		Color4F(float r, float g, float b) : r(r), g(g), b(b), a(1) {}
	};
}