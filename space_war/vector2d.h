#pragma once

class Vector2D final {
private:
	Vector2D linear_operations(const char ch, const Vector2D &vector2) const;
public:
	double x, y;
	Vector2D() {}
	Vector2D(double _x, double _y) : x(_x), y(_y) {}
	Vector2D operator+(const Vector2D &vector2) const;
	Vector2D operator-(const Vector2D &vector2) const;
	Vector2D& operator+=(const Vector2D &vector2);
	Vector2D& operator-=(const Vector2D &vector2);
};