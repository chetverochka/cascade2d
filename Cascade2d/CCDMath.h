#pragma once

#include "CCDVec.h"

namespace cascade { // создание класса тут лишнее, но надо
	struct math {
		static float radiansToDegrees(float num);
		static float degreesToRadians(float num);

		static cascade::Vec rotatePoint(cascade::Vec point, float degrees);
	};
}