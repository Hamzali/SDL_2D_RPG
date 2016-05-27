CC =g++
CFLAGS=-g
LDFLAGS=-lSDL2 -lSDL2_image -lSDL2_ttf -lalut
OPENALLIB=-L/usr/local/opt/openal-soft/lib
OPENALINC=-I/usr/local/opt/openal-soft/include
SDLINC=-I/usr/local/include
SDLLIB=-L/usr/local/lib

SRC=main.cpp \
	Game.cpp \
	AudioManager.cpp \
	GameStateMachine.cpp \
	GameManager.cpp \
	TextureManager.cpp \
	SDLGameObject.cpp \
	InputHandler.cpp \
	MenuState.cpp \
	button.cpp \


all: main

main:
	 $(CC)  $(CFLAGS) $(SRC) $(SDLINC) $(SDLLIB) $(OPENALINC) $(OPENALLIB) $(LDFLAGS) -o bin/pr
