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

all: $(OBJS)main$(DLLEXT) $(OBJS)matrix$(DLLEXT) $(OBJS)entitee$(DLLEXT) $(OBJS)entitees/marchandise$(DLLEXT) $(OBJS)entitees/strands$(DLLEXT) $(OBJS)entitees/acteur$(DLLEXT) $(OBJS)entitees/acteurs/protagoniste$(DLLEXT) $(OBJS)entitees/acteurs/mules$(DLLEXT) $(OBJS)interface$(DLLEXT)
	$(CC) $(CFLAGS) -o app $(OBJS)main$(DLLEXT) $(OBJS)matrix$(DLLEXT) $(OBJS)entitee$(DLLEXT) $(OBJS)entitees/marchandise$(DLLEXT) $(OBJS)entitees/strands$(DLLEXT) $(OBJS)entitees/acteur$(DLLEXT) $(OBJS)entitees/acteurs/protagoniste$(DLLEXT) $(OBJS)entitees/acteurs/mules$(DLLEXT) $(OBJS)interface$(DLLEXT) $(LIB)

$(OBJS)main$(DLLEXT): $(SRCS)main.cpp $(HEADERS)matrix.h $(HEADERS)entitee.h $(HEADERS)entitees/marchandise.h $(HEADERS)entitees/strands.h $(HEADERS)entitees/acteur.h $(HEADERS)entitees/acteurs/protagoniste.h $(HEADERS)entitees/acteurs/mules.h $(HEADERS)interface.h
ifneq ($(wildcard obj/.*),)
	@echo "Found obj."
else
	@echo "Did not find obj."
	mkdir obj
endif
ifneq ($(wildcard obj/entitees/.*),)
	@echo "Found obj/entitees."
else
	@echo "Did not find obj/entitees."
	mkdir obj/entitees
endif
ifneq ($(wildcard obj/entitees/acteurs/.*),)
	@echo "Found obj/entitees/acteurs."
else
	@echo "Did not find obj/entitees/acteurs."
	mkdir obj/entitees/acteurs
endif
	$(CC) $(CFLAGS) -c $(INCL) $(SRCS)main.cpp -o $(OBJS)main$(DLLEXT)

$(OBJS)matrix$(DLLEXT): $(SRCS)matrix.cpp $(HEADERS)matrix.h
	$(CC) $(CFLAGS) -c $(INCL) $(SRCS)matrix.cpp -o $(OBJS)matrix$(DLLEXT)

$(OBJS)entitee$(DLLEXT): $(SRCS)entitee.cpp $(HEADERS)entitee.h $(HEADERS)entitees/acteur.h
	$(CC) $(CFLAGS) -c $(INCL) $(SRCS)entitee.cpp -o $(OBJS)entitee$(DLLEXT)

$(OBJS)entitees/marchandise$(DLLEXT): $(SRCS)entitees/marchandise.cpp $(HEADERS)entitees/marchandise.h
	$(CC) $(CFLAGS) -c $(INCL) $(SRCS)entitees/marchandise.cpp -o $(OBJS)entitees/marchandise$(DLLEXT)

$(OBJS)entitees/strands$(DLLEXT): $(SRCS)entitees/strands.cpp $(HEADERS)entitees/strands.h
	$(CC) $(CFLAGS) -c $(INCL) $(SRCS)entitees/strands.cpp -o $(OBJS)entitees/strands$(DLLEXT)

$(OBJS)entitees/acteur$(DLLEXT): $(SRCS)entitees/acteur.cpp $(HEADERS)entitees/acteur.h
	$(CC) $(CFLAGS) -c $(INCL) $(SRCS)entitees/acteur.cpp -o $(OBJS)entitees/acteur$(DLLEXT)

$(OBJS)entitees/acteurs/protagoniste$(DLLEXT): $(SRCS)entitees/acteurs/protagoniste.cpp $(HEADERS)entitees/acteurs/protagoniste.h
	$(CC) $(CFLAGS) -c $(INCL) $(SRCS)entitees/acteurs/protagoniste.cpp -o $(OBJS)entitees/acteurs/protagoniste$(DLLEXT)

$(OBJS)entitees/acteurs/mules$(DLLEXT): $(SRCS)entitees/acteurs/mules.cpp $(HEADERS)entitees/acteurs/mules.h
	$(CC) $(CFLAGS) -c $(INCL) $(SRCS)entitees/acteurs/mules.cpp -o $(OBJS)entitees/acteurs/mules$(DLLEXT)

$(OBJS)interface$(DLLEXT): $(SRCS)interface.cpp $(HEADERS)interface.h
	$(CC) $(CFLAGS) -c $(INCL) $(SRCS)interface.cpp -o $(OBJS)interface$(DLLEXT) 

packages:
	sudo apt install libsfml-dev -y

clean:
	rm -f $(OBJS)*$(DLLEXT) $(OBJS)entitees/*$(DLLEXT) $(OBJS)entitees/acteurs/*$(DLLEXT) app
