CC = g++
TARGET = book
CFLAGS= -c -Wall -Wextra

all: $(TARGET)

$(TARGET): library.o main.o
	$(CC) -g -Wall -Wextra -o $(TARGET) main.o library.o

library.o: library.cpp library.h
	$(CC) $(CFLAGS) library.cpp

main.o: main.cpp library.h
	$(CC) $(CFLAGS) main.cpp
clean:
	$(RM) $(TARGET) *.o *~
