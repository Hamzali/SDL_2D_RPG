#ifndef _VECTOR_2D_
#define _VECTOR_2D_

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <string>

#define PI 3.141592
#define DEG_TO_RAD 0.017453
#define RAD_TO_DEG 57.295779


class Vector2D{
public:
    // Constructor and Destructor.
    Vector2D(){m_x = 0;m_y = 0;m_cosin = false;sw = 0; sh = 0;}
    Vector2D(int x, int y){m_x = (float)x; m_y = (float)y; sw = 0; sh = 0;m_cosin = false;}
    Vector2D(float x, float y){m_x = x; m_y = y; sw = 0; sh = 0;m_cosin = false;}
    Vector2D(const Vector2D& v) {m_x = v.getX(); m_y = v.getY();sw = 0; sh = 0;m_cosin = false;}

    ~Vector2D(){}

    // Getters and Setters
    float getX() const {return m_x;}
    float getY() const {return m_y;}

    void setX(float x) {m_x = x;}
    void setY(float y) {m_y = y;}

    void setX(int x) {m_x = (float)x;}
    void setY(int y) {m_y = (float)y;}

    void set(const Vector2D& v) {m_x = v.getX(); m_y = v.getY();}

    //Static members.
    
    /*
    static std::vector<float> m_c;
    static std::vector<float> m_s;

    static void loadCosin() {
        std::ifstream cosin;
        std::string val;
        cosin.open("assets/cosin.bin");
        for(int i = 0; i < 360; ++i) {
            getline(cosin, val, ',');
            Vector2D::m_s.push_back(atof(val.c_str()));
            getline(cosin, val, ',');
            Vector2D::m_c.push_back(atof(val.c_str()));
        }
        printf("Loaded sin/cos\n");
    }
    */
    

    // Member Functions.
    float length() const {return sqrt(m_x * m_x + m_y * m_y);}

    void normalize() {
        float l = length();
        if(l > 0) (*this) *= 1 / l;
    }

    void loadCosin() {
        std::ifstream cosin;
        std::string val;
        cosin.open("assets/cosin.bin");
        for(int i = 0; i < 360; ++i) {
            getline(cosin, val);
            m_s.push_back(atof(val.c_str()));
            getline(cosin, val);
            m_c.push_back(atof(val.c_str()));
            
        }
        cosin.close();
        m_cosin = true;
    }

    float getSin(int angle) {return m_s.at(angle);}
    float getCos(int angle) {return m_c.at(angle);}

    int angleTo(const Vector2D& v) {
        return RAD_TO_DEG * atan2((v.m_y-m_y), (v.m_x - m_x));
    }
    

    void setToDistance(const Vector2D& v, float distance, int angle) {

        if(!m_cosin) return;
        //printf("LOL\n");
        int pmx = m_x;
        int pmy = m_y;
        m_x = v.m_x + distance * getCos(angle);//cos(DEG_TO_RAD * angle);
        m_y = v.m_y + distance * getSin(angle);//sin(DEG_TO_RAD * angle);
        if(sw > 0 && sh > 0){
            if(m_x > sw || m_x < 0 || m_y > sh || m_y < 0) {
                m_x = pmx;
                m_y = pmy;
            }
        }
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

    int sw;
    int sh;



private:
    float m_x;
    float m_y;

    bool m_cosin;


    std::vector<float> m_c;
    std::vector<float> m_s;
};
#endif
