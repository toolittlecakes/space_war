#include "vector2d.h"



Vector2D Vector2D::linear_operations(const char ch, const Vector2D & vector2) const
{
	Vector2D new_vector;
	if (ch == '+') {
		new_vector.x = x + vector2.x;
		new_vector.y = x + vector2.y;
	}
	else if(ch =='-') {
		new_vector.x = x - vector2.x;
		new_vector.y = x - vector2.y;
	}
	return new_vector;
}

Vector2D Vector2D::operator+(const Vector2D & vector2) const
{
	return linear_operations('+', vector2);
}

Vector2D Vector2D::operator-(const Vector2D & vector2) const
{
	return linear_operations('-', vector2);
}

Vector2D & Vector2D::operator+=(const Vector2D & vector2)
{
	*this = *this + vector2;
	return *this;
}

Vector2D & Vector2D::operator-=(const Vector2D & vector2)
{
	*this = *this - vector2;
	return *this;
}
