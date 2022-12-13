CC = g++

CFLAGS = -Wall -g

LIB = -lsfml-graphics -lsfml-window -lsfml-system

SRCS = sources/

OBJS = obj/

HEADERS = headers/

ifeq ($(OS),Windows_NT)
	DLLEXT = .dll
else
	DLLEXT = .so
endif

ifeq ($(OS),Windows_NT)
all: $(OBJS)main$(DLLEXT) $(OBJS)matrix$(DLLEXT) $(OBJS)acteur$(DLLEXT) $(OBJS)interface$(DLLEXT)
	$(CC) $(CFLAGS) -o app.exe $(OBJS)main$(DLLEXT) $(OBJS)matrix$(DLLEXT) $(OBJS)acteur$(DLLEXT) $(OBJS)interface$(DLLEXT) $(LIB)
else
all: $(OBJS)main$(DLLEXT) $(OBJS)matrix$(DLLEXT) $(OBJS)acteur$(DLLEXT) $(OBJS)interface$(DLLEXT)
	$(CC) $(CFLAGS) -o app $(OBJS)main$(DLLEXT) $(OBJS)matrix$(DLLEXT) $(OBJS)acteur$(DLLEXT) $(OBJS)interface$(DLLEXT) $(LIB)
endif

$(OBJS)main$(DLLEXT): $(SRCS)main.cpp $(HEADERS)matrix.h $(HEADERS)acteur.h $(HEADERS)interface.h
	$(CC) $(CFLAGS) -c $(SRCS)main.cpp -o $(OBJS)main$(DLLEXT)

$(OBJS)matrix$(DLLEXT): $(SRCS)matrix.cpp $(HEADERS)matrix.h
	$(CC) $(CFLAGS) -c $(SRCS)matrix.cpp -o $(OBJS)matrix$(DLLEXT)

$(OBJS)acteur$(DLLEXT): $(SRCS)acteur.cpp $(HEADERS)acteur.h
	$(CC) $(CFLAGS) -c $(SRCS)acteur.cpp -o $(OBJS)acteur$(DLLEXT)

$(OBJS)interface$(DLLEXT): $(SRCS)interface.cpp $(HEADERS)interface.h
	$(CC) $(CFLAGS) -c $(SRCS)interface.cpp -o $(OBJS)interface$(DLLEXT) 

packages:
	sudo apt install libsfml-dev -y

clean:
	rm -f $(OBJS)*$(DLLEXT) main