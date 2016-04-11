CC =g++
CFLAGS=-Wall -g
LDFLAGS=-lSDL2 -lSDL2_image
SRC=main.cpp Game.cpp TextureManager.cpp SDLGameObject.cpp Player.cpp Enemy.cpp

all: main Game TextureManager SDLGameObject Player Enemy

main:
	 $(CC)  $(CFLAGS) $(SRC) $(LDFLAGS) -o pr
