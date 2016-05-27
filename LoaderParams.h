#ifndef __LOADER_PARAMS__
#define  __LOADER_PARAMS__

class LoaderParams{

public:
    LoaderParams(int x, int y, int width, int height, std::string textureID) :
     m_x(x), m_y(y), m_width(width), m_height(height), m_textureID(textureID) {}

    LoaderParams(int x, int y) :
     m_x(x), m_y(y), m_width(0), m_height(0), m_textureID("") {}

    LoaderParams(int x, int y, int width, int height) :
     m_x(x), m_y(y), m_width(width), m_height(height), m_textureID("") {}

     int getX() const {return m_x;}
     int getY() const {return m_y;}
     int getWidth() const {return m_width;}
     int getHeight() const {return m_height;}
     std::string getTextureID() const {return m_textureID;}


private:
    // Location of the object.
    int m_x;
    int m_y;

    // Size of the object.
    int m_width;
    int m_height;

    std::string m_textureID;

    int m_currentRow;
    int m_currentFrame;
};


#endif
