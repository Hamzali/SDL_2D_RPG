#ifndef _VECTOR_2D_
#define _VECTOR_2D_

#include <math.h>

class Vector2D{
public:
    // Constructor and Destructor.
    Vector2D() : m_x(0), m_y(0) {}
    Vector2D(int x, int y){m_x = (float)x; m_y = (float)y;}
    Vector2D(float x, float y) : m_x(x), m_y(y) { }
    Vector2D(const Vector2D& v) {m_x = v.getX(); m_y = getY();}

    ~Vector2D(){}

    // Getters and Setters
    float getX() const {return m_x;}
    float getY() const {return m_y;}

    void setX(const float x) {m_x = x;}
    void setY(const float y) {m_y = y;}

    void setX(const int x) {m_x = (float)x;}
    void setY(const int y) {m_y = (float)y;}

    //Static members.


    // Member Functions.
    float length() const {return sqrt(m_x * m_x + m_y * m_y);}

    void normalize() {
        float l = length();
        if(l > 0) (*this) *= 1 / l;
    }

    // Operator overloades.
    // Sum
    Vector2D operator+(const Vector2D& v) const
    {
        return Vector2D(m_x + v.m_x , m_y + v.m_y);
    }

    friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2 )
    {
        v1.m_x += v2.m_x;
        v1.m_y += v2.m_y;
        return v1;
    }
    // Multipication by a scalar.
    Vector2D operator*(float scalar)
    {
        return Vector2D(m_x * scalar, m_y * scalar);
    }

    Vector2D& operator*=(float scalar)
    {
        m_x *= scalar;
        m_y *= scalar;
        return *this;
    }
    // Substruction.
    Vector2D operator-(const Vector2D& v) const
    {
        return Vector2D(m_x - v.m_x , m_y - v.m_y);
    }

    friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2 )
    {
        v1.m_x -= v2.m_x;
        v1.m_y -= v2.m_y;
        return v1;
    }

    // Divison.
    Vector2D operator/(float scalar)
    {
        return Vector2D(m_x / scalar, m_y / scalar);
    }

    Vector2D& operator/=(float scalar)
    {
        m_x /= scalar;
        m_y /= scalar;
        return *this;
    }




private:
    float m_x;
    float m_y;
};


#endif
