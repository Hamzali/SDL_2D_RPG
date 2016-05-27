CC =g++
CFLAGS=-g -Wall
LDFLAGS=-lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
INC=-I/usr/local/include
LIB=-L/usr/local/lib

SRC=main.cpp \
	Game.cpp \
	AudioManager.cpp \
	GameStateMachine.cpp \
	GameManager.cpp \
	TextureManager.cpp \
	SDLGameObject.cpp \
	InputHandler.cpp \

all: main

main:
	 $(CC)  $(CFLAGS) $(SRC) $(INC) $(LIB) $(LDFLAGS) -o bin/pr
