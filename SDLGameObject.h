#ifndef __SDL_GAME_OBJECT__
#define  __SDL_GAME_OBJECT__

#include "GameObject.h"
#include "TextureManager.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject {
public:
    SDLGameObject(const LoaderParams* pParams);

    // Abstract functions derived from GameObject class.
    virtual void draw();
    virtual void update();
    virtual void clean();

    // Getters and Setters.
    void setPosition(const Vector2D& v) {m_Position = v;}
    void setPosition(float x, float y) {m_Position.setX(x);m_Position.setY(y);}

    void setVelocity(const Vector2D& v) {m_Velocity = v;}
    void setVelocity(float x, float y) {m_Velocity.setX(x);m_Velocity.setY(y);}

    void setAccel(const Vector2D& v) {m_Accel = v;}
    void setAccel(float x, float y) {m_Accel.setX(x); m_Accel.setY(y);}

    Vector2D getPosition() const{return m_Position;}
    Vector2D getVelocity() const {return m_Velocity;}
    Vector2D getAccel() const {return m_Accel;}



protected:
    Vector2D m_Position;
    Vector2D m_Velocity;
    Vector2D m_Accel;

    int m_width;
    int m_height;

    int m_currentRow;
    int m_currentFrame;

    std::string m_textureID;
};

#endif
