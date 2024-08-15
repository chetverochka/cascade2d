#include "CCDMath.h"
#include <cmath>
float cascade::math::radiansToDegrees(float num) {
	return (num * 180) / 3.14;
}
float cascade::math::degreesToRadians(float num) {
	return (num * 3.14) / 180;
}

cascade::Vec cascade::math::rotatePoint(cascade::Vec point, float degrees) {
	float angleRadians = degrees * 3.14f / 180.0f;
	float cosTheta = std::cos(angleRadians);
	float sinTheta = std::sin(angleRadians);

	float x_new = point.x * cosTheta - y * sinTheta;
	float y_new = point.x * sinTheta + y * cosTheta;

	return cascade::Vec(x_new, y_new);
}