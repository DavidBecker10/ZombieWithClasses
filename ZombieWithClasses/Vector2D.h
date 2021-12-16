#pragma once
#include "Serialize.h"

template <typename T>
class Vector2D : public Serialize {
public:
    T x, y;

    Vector2D(T X = 0.0, T Y = 0.0);
    Vector2D(nlohmann::json j);
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

    float operator *(Vector2D v) const;
    T absoluteValue() const;
    Vector2D verse() const;
    //Projection of this vector on v direction
    //Conteudo de grau superior
    Vector2D orthogonalProjection(Vector2D v) const;

    nlohmann::json convertJSON() override;

};

typedef Vector2D<float> Vector2F;
typedef Vector2D<unsigned> Vector2U;

template <typename T>
std::ostream& operator <<(std::ostream& out, const Vector2D<T>& v);

#include "Vector2DImplement.h"