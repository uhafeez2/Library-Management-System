# Makefile for Library
CXXFLAGS = -w -std=c++11
LDFLAGS = -L/usr/local/lib -lXext -lm -Wl,-Bsymbolic-functions -lfltk_images -lfltk -lX11

all: main

debug: CXXFLAGS += -g
debug: main

rebuild: clean main

main: main.cpp controller.cpp view.cpp library.cpp publication.cpp patron.cpp
	$(CXX) $(CXXFLAGS) $(fltk-config --use-images --cxxflags) -o main main.cpp controller.cpp view.cpp library.cpp publication.cpp patron.cpp $(LDFLAGS)

cli: library_cli.cpp
	$(CXX) $(CXXFLAGS) -o cli library_cli.cpp

clean:
	-rm -f *.o main cli

