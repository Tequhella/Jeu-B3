CC = g++

CFLAGS = -Wall -g

LIBS = -lsfml-graphics -lsfml-window -lsfml-system

SRCS = sources/

OBJS = obj/

HEADERS = headers/

all: $(OBJS)main.o $(OBJS)matrix.o $(OBJS)interface.o $(OBJS)button.o
	$(CC) $(CFLAGS) -o app $(OBJS)main.o $(OBJS)matrix.o $(OBJS)interface.o $(OBJS)button.o $(LIBS)

$(OBJS)main.o: $(SRCS)main.cpp $(HEADERS)matrix.h $(HEADERS)interface.h $(HEADERS)button.h
ifneq ($(wildcard obj/.*),)
	@echo "Found obj."
else
	@echo "Did not find obj."
	mkdir obj
endif
	$(CC) $(CFLAGS) -c $(SRCS)main.cpp -o $(OBJS)main.o

$(OBJS)matrix.o: $(SRCS)matrix.cpp $(HEADERS)matrix.h
	$(CC) $(CFLAGS) -c $(SRCS)matrix.cpp -o $(OBJS)matrix.o

$(OBJS)interface.o: $(SRCS)interface.cpp $(HEADERS)interface.h
	$(CC) $(CFLAGS) -c $(SRCS)interface.cpp -o $(OBJS)interface.o

$(OBJS)button.o: $(SRCS)button.cpp $(HEADERS)button.h
	$(CC) $(CFLAGS) -c $(SRCS)button.cpp -o $(OBJS)button.o

packages:
	sudo apt install libsfml-dev -y

launch:
	./app

clean:
	rm -f $(OBJS)*.o app