#pragma once
#include <cmath>
#include <ostream>
#include "Vector2D.h"

template<typename T>
class Vector2D
{
public:
	T x, y;

	Vector2D(T xi = 0.0, T yi = 0.0);
	~Vector2D();
	Vector2D operator+(Vector2D v);
	Vector2D operator-(Vector2D v);
	Vector2D operator*(int i);
	Vector2D operator*(float f);
	Vector2D operator*(double d);
	void operator+=(Vector2D v);
	void operator-=(Vector2D v);
	Vector2D operator*=(int i);
	Vector2D operator*=(float f);
	Vector2D operator*=(double d);
	bool operator==(Vector2D v);
	T operator*(Vector2D v);
	T absValue();
	Vector2D verse();
	Vector2D orthogonalProjection(Vector2D v);
};

typedef Vector2D<float> Vector2F;
typedef Vector2D<unsigned> Vector2U;

template<typename T>
std::ostream& operator <<(std::ostream& out, const Vector2D<T> v)
{
	out << "(" << v.x << " , " << v.y << ")";
	return out;
}

template<typename T>
Vector2D<T>::Vector2D(T xi, T yi):
	x(xi),
	y(yi)
{
}

template<typename T>
Vector2D<T>::~Vector2D()
{
}

template<typename T>
Vector2D<T> Vector2D<T>::operator +(Vector2D<T> v)
{
	return Vector2D<T>(x + v.x, y + v.y);
}

template<typename T>
Vector2D<T> Vector2D<T>::operator -(Vector2D<T> v)
{
	return Vector2D<T>(x - v.x, y - v.y);
}

template<typename T>
Vector2D<T> Vector2D<T>::operator *(int i)
{
	return Vector2D<T>(x * i, y * i);
}

template<typename T>
Vector2D<T> Vector2D<T>::operator *(float f)
{
	return Vector2D(x * f, y * f);
}

template<typename T>
Vector2D<T> Vector2D<T>::operator *(double d)
{
	return Vector2D<T>(x * d, y * d);
}

template<typename T>
void Vector2D<T>::operator +=(Vector2D<T> v)
{
	(x + v.x, y + v.y);
}

template<typename T>
void Vector2D<T>::operator -=(Vector2D<T> v)
{
	(x - v.x, y - v.y);
}

template<typename T>
Vector2D<T> Vector2D<T>::operator *=(int i)
{
	return Vector2D<T>(x * i, y * i);
}

template<typename T>
Vector2D<T> Vector2D<T>::operator *=(float f)
{
	return Vector2D<T>(x * f, y * f);
}

template<typename T>
Vector2D<T> Vector2D<T>::operator *=(double d)
{
	return Vector2D<T>(x * d, y * d);
}

template<typename T>
bool Vector2D<T>::operator ==(Vector2D<T> v)
{
	return (v.x == x && v.y == y);
}

template<typename T>
T Vector2D<T>::operator *(Vector2D<T> v)
{
	return (x*v.x + y*v.y);
}

template<typename T>
T Vector2D<T>::absValue()
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

template<typename T>
Vector2D<T> Vector2D<T>::verse()
{
	return this->operator*(1.0/absValue());
}

template<typename T>
Vector2D<T> Vector2D<T>::orthogonalProjection(Vector2D<T> v)
{
	return v*(this->operator*(v)/pow(v.absValue(), 2));
}
