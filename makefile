CC = g++

CFLAGS = -Wall -g

SRCS = sources/

OBJS = obj/

HEADERS = headers/

DLLEXT = .o

ifeq ($(OS),Windows_NT)
	LIB = -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
	INCL = -Isrc/include
else
	LIB = -lsfml-graphics -lsfml-window -lsfml-system
	INCL =
endif

all: $(OBJS)main$(DLLEXT) $(OBJS)matrix$(DLLEXT) $(OBJS)acteur$(DLLEXT) $(OBJS)acteurs/protagoniste$(DLLEXT) $(OBJS)acteurs/marchandise$(DLLEXT) $(OBJS)acteurs/ennemi$(DLLEXT) $(OBJS)interface$(DLLEXT)
	$(CC) $(CFLAGS) -o app $(OBJS)main$(DLLEXT) $(OBJS)matrix$(DLLEXT) $(OBJS)acteur$(DLLEXT) $(OBJS)acteurs/protagoniste$(DLLEXT) $(OBJS)acteurs/marchandise$(DLLEXT) $(OBJS)acteurs/ennemi$(DLLEXT) $(OBJS)interface$(DLLEXT) $(LIB)

$(OBJS)main$(DLLEXT): $(SRCS)main.cpp $(HEADERS)matrix.h $(HEADERS)acteur.h $(HEADERS)acteurs/protagoniste.h $(HEADERS)acteurs/marchandise.h $(HEADERS)acteurs/ennemi.h $(HEADERS)interface.h
ifneq ($(wildcard obj/.*),)
	@echo "Found obj."
else
	@echo "Did not find obj."
	mkdir obj
endif	
	$(CC) $(CFLAGS) -c $(INCL) $(SRCS)main.cpp -o $(OBJS)main$(DLLEXT)

$(OBJS)matrix$(DLLEXT): $(SRCS)matrix.cpp $(HEADERS)matrix.h
	$(CC) $(CFLAGS) -c $(INCL) $(SRCS)matrix.cpp -o $(OBJS)matrix$(DLLEXT)

$(OBJS)acteur$(DLLEXT): $(SRCS)acteur.cpp $(HEADERS)acteur.h
ifneq ($(wildcard obj/acteurs/.*),)
	@echo "Found obj/acteurs."
else
	@echo "Did not find obj/acteurs."
	mkdir obj/acteurs
endif
	$(CC) $(CFLAGS) -c $(INCL) $(SRCS)acteur.cpp -o $(OBJS)acteur$(DLLEXT)

$(OBJS)acteurs/protagoniste$(DLLEXT): $(SRCS)acteurs/protagoniste.cpp $(HEADERS)acteurs/protagoniste.h
	$(CC) $(CFLAGS) -c $(INCL) $(SRCS)acteurs/protagoniste.cpp -o $(OBJS)acteurs/protagoniste$(DLLEXT)

$(OBJS)acteurs/marchandise$(DLLEXT): $(SRCS)acteurs/marchandise.cpp $(HEADERS)acteurs/marchandise.h
	$(CC) $(CFLAGS) -c $(INCL) $(SRCS)acteurs/marchandise.cpp -o $(OBJS)acteurs/marchandise$(DLLEXT)

$(OBJS)acteurs/ennemi$(DLLEXT): $(SRCS)acteurs/ennemi.cpp $(HEADERS)acteurs/ennemi.h
	$(CC) $(CFLAGS) -c $(INCL) $(SRCS)acteurs/ennemi.cpp -o $(OBJS)acteurs/ennemi$(DLLEXT)

$(OBJS)interface$(DLLEXT): $(SRCS)interface.cpp $(HEADERS)interface.h
	$(CC) $(CFLAGS) -c $(INCL) $(SRCS)interface.cpp -o $(OBJS)interface$(DLLEXT) 

packages:
	sudo apt install libsfml-dev -y

clean:
	rm -f $(OBJS)*$(DLLEXT) $(OBJS)acteurs/*$(DLLEXT)  app
