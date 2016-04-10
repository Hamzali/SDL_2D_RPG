#ifndef __LOADER_PARAMS__
#define  __LOADER_PARAMS__

class LoaderParams{

public:
    LoaderParams(int x, int y, int width, int height, std::string textureID) :
     m_x(x), m_y(y), m_width(width), m_height(height), m_textureID(textureID) {}

     int getX() const {return m_x;}
     int getY() const {return m_x;}
     int getWidth() const {return m_width;}
     int getHeight() const {return m_height;}
     std::string getTextureID() const {return m_textureID;}


private:
    std::string m_textureID;

    // Location of the object.
    int m_x;
    int m_y;

    // Size of the object.
    int m_width;
    int m_height;

    int m_currentRow;
    int m_currentFrame;
};


#endif
