CC = g++

CFLAGS = -Wall -g

LIB = -lsfml-graphics -lsfml-window -lsfml-system

SRCS = sources/

OBJS = obj/

HEADERS = headers/

all: $(OBJS)main.o $(OBJS)matrix.o $(OBJS)acteur.o $(OBJS)interface.o
	$(CC) $(CFLAGS) -o app $(OBJS)main.o $(OBJS)matrix.o $(OBJS)acteur.o $(OBJS)interface.o $(LIB)

$(OBJS)main.o: $(SRCS)main.cpp $(HEADERS)matrix.h $(HEADERS)acteur.h $(HEADERS)interface.h
	$(CC) $(CFLAGS) -c $(SRCS)main.cpp -o $(OBJS)main.o

$(OBJS)matrix.o: $(SRCS)matrix.cpp $(HEADERS)matrix.h 
	$(CC) $(CFLAGS) -c $(SRCS)matrix.cpp -o $(OBJS)matrix.o

$(OBJS)acteur.o: $(SRCS)acteur.cpp $(HEADERS)acteur.h
	$(CC) $(CFLAGS) -c $(SRCS)acteur.cpp -o $(OBJS)acteur.o

$(OBJS)interface.o: $(SRCS)interface.cpp $(HEADERS)interface.h
	$(CC) $(CFLAGS) -c $(SRCS)interface.cpp -o $(OBJS)interface.o 

packages:
	sudo apt install libsfml-dev -y

clean:
	rm -f $(OBJS)*.o app