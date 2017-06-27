INCLUDES = -I "../Grimoire/src"

PROG = ../Grimoire/bin/exe
CC = g++
CPPFLAGS = -Wall -W -pedantic -g -std=c++11
OBJS = src/monster.o src/grimoire.o src/page.o src/main.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

monster.o: monster.cpp
	$(CC) $(CPPFLAGS) $(INCLUDES) -c monster.cpp

grimoire.o : grimoire.cpp
	$(CC) $(CPPFLAGS) $(INCLUDES) -c grimoire.cpp

page.o : page.cpp
	$(CC) $(CPPFLAGS) $(INCLUDES) -c page.cpp

main.o : main.cpp
	$(CC) $(CPPFLAGS) $(INCLUDES) -c main.cpp

clean:
	rm *.o