#pragma once
template <typename T>
class Vector2D {
public:
    T x, y;

    Vector2D(T X = 0.0, T Y = 0.0);
    ~Vector2D();
    Vector2D operator +(Vector2D v) const;
    Vector2D operator -(Vector2D v) const;
    Vector2D operator *(int i) const;
    Vector2D operator *(float f) const;
    Vector2D operator *(double d) const;

    void operator +=(Vector2D v);
    void operator -=(Vector2D v);
    void operator *=(int i);
    void operator *=(float f);
    void operator *=(double d);

    T operator *(Vector2D v);
    T absoluteValue();
    Vector2D verse();
    //Projection of this vector on v direction
    Vector2D orthogonalProjection(Vector2D v);

};

typedef Vector2D<float> Vector2F;
typedef Vector2D<unsigned> Vector2U;

#include "Vector2DImplement.h"