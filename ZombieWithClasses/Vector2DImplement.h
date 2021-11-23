#ifndef ZOMBIEWITHCLASSES_VECTOR2DIMPLEMENT_H
#define ZOMBIEWITHCLASSES_VECTOR2DIMPLEMENT_H
#include<cmath>

template <typename T>
class Vector2D;

template <typename T>
Vector2D<T>::Vector2D(T X, T Y) :x{ X }, y{ Y } {

}

template <typename T>
Vector2D<T>::~Vector2D() {

}

template <typename T>
Vector2D<T> Vector2D<T>::operator +(Vector2D v) const {
    return Vector2D<T>(x + v.x, y + v.y);
}

template <typename T>
Vector2D<T> Vector2D<T>::operator -(Vector2D v) const {
    return Vector2D<T>(x - v.x, y - v.y);
}

template <typename T>
Vector2D<T> Vector2D<T>::operator *(int i) const {
    return Vector2D<T>(x * i, y * i);
}

template <typename T>
Vector2D<T> Vector2D<T>::operator *(float f) const {
    return Vector2D<T>(x * f, y * f);
}

template <typename T>
Vector2D<T> Vector2D<T>::operator *(double d) const {
    return Vector2D<T>(x * d, y * d);
}
template <typename T>
void Vector2D<T>::operator +=(Vector2D<T> v) {
    x += v.x;
    y += v.y;
}

template <typename T>
void Vector2D<T>::operator -=(Vector2D<T> v) {
    x -= v.x;
    y -= v.y;
}

template <typename T>
void Vector2D<T>::operator *=(int i) {
    x *= i;
    y *= i;
}

template <typename T>
void Vector2D<T>::operator *=(float f) {
    x *= f;
    y *= f;
}

template <typename T>
void Vector2D<T>::operator *=(double d) {
    x *= d;
    y *= d;
}

template <typename T>
T Vector2D<T>::operator *(Vector2D v) {
    return x * v.x + y * v.y;
}

template <typename T>
T Vector2D<T>::absoluteValue() {
    return sqrt(pow(x, 2) + pow(y, 2));
}

template <typename T>
Vector2D<T> Vector2D<T>::verse() {
    return this->operator*(1.0 / absoluteValue());
}

template <typename T>
Vector2D<T> Vector2D<T>::orthogonalProjection(Vector2D v) {
    return v * (this->operator*(v) / pow(v.absoluteValue(), 2));
}

#endif //ZOMBIEWITHCLASSES_VECTOR2DIMPLEMENT_H
