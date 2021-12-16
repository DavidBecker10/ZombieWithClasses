#ifndef ZOMBIEWITHCLASSES_VECTOR2DIMPLEMENT_H
#define ZOMBIEWITHCLASSES_VECTOR2DIMPLEMENT_H
#include<cmath>

template <typename T>
class Vector2D;

template <typename T>
Vector2D<T>::Vector2D(T X, T Y) :x{ X }, y{ Y } {

}

template <typename T>
Vector2D<T>::Vector2D(nlohmann::json j) : x{ static_cast<T>(j["x"]) }, y{ static_cast<T>(j["y"]) } {

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

template<typename T>
nlohmann::json Vector2D<T>::convertJSON() {
    return { {"x", x}, {"y", y} };
}

template <typename T>
float Vector2D<T>::operator *(Vector2D v) const {
    return x * v.x + y * v.y;
}

template <typename T>
T Vector2D<T>::absoluteValue()const {
    return sqrt(pow(x, 2) + pow(y, 2));
}

template <typename T>
Vector2D<T> Vector2D<T>::verse()const {
    return this->operator*(1.0 / absoluteValue());
}

template <typename T>
Vector2D<T> Vector2D<T>::orthogonalProjection(Vector2D v)const {
    return v * (this->operator*(v) / pow(v.absoluteValue(), 2));
}

template <typename T>
std::ostream& operator <<(std::ostream& out, const Vector2D<T>& v) {
    out << '(' << v.x << " , " << v.y << ')';
    return out;
}
#endif //ZOMBIEWITHCLASSES_VECTOR2DIMPLEMENT_H
