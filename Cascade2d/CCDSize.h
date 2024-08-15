#pragma once

namespace cascade {
	class Size {
	public:
		float width;
		float height;
		Size() : width(0), height(0) {}
		Size(float width, float height) : width(width), height(height) {}

		Size operator / (float num){
			return Size(width / num, height / num);
		}

		bool operator == (Size s) {
			return (s.width == width && s.height == height);
		}
	};
}