CXX = g++
LD = g++
CXXFLAGS = -Wall `sdl-config --cflags`
LDFLAGS = -O2 -s `sdl-config --libs` -lSDL_net -lSDL_mixer -lSDL_ttf
RM   = /bin/rm -f
OBJS = src/main.o src/client.o src/framework.o src/game.o src/menu.o src/player.o src/server.o src/sound.o src/sprite.o
PROG = openpong
VERS = 0.1.0

.PHONY: clean distclean
all: $(PROG)
$(PROG): $(OBJS)
	$(LD) $(LDFLAGS) -o $(PROG) $(OBJS)
clean:
	$(RM) *~ $(OBJS) $(PROG)
.PHONY: clean
