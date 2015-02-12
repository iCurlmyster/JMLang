CC=clang++
CFLAGS=-c -Wall
TARGET=jm

ATTR=-std=c++11

OBJECTS=jm.o JMParser.o JMString.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(ATTR) $(OBJECTS) -o $(TARGET)
jm.o: jm.cpp
	$(CC) $(CFLAGS) $(ATTR) jm.cpp
JMParser.o: JMParser.cpp
	$(CC) $(CFLAGS) $(ATTR) JMParser.cpp
JMString.o: JMString.cpp
	$(CC) $(CFLAGS) $(ATTR) JMString.cpp
clean:
	rm -Rf *.o $(TARGET)
