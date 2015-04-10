CC=clang++
CFLAGS=-c -Wall
TARGET=jm

ATTR=-std=c++11

OBJECTS=jm.o JMObject.o JMParser.o JMString.o JMNum.o JMInterpreter.o JMMethodCall.o FileManager.o JMArray.o JMDefFunc.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(ATTR) $(OBJECTS) -o $(TARGET)
jm.o: jm.cpp
	$(CC) $(CFLAGS) $(ATTR) jm.cpp
JMObject.o: JMObject.cpp
	$(CC) $(CFLAGS) $(ATTR) JMObject.cpp
JMParser.o: JMParser.cpp
	$(CC) $(CFLAGS) $(ATTR) JMParser.cpp
JMString.o: JMString.cpp
	$(CC) $(CFLAGS) $(ATTR) JMString.cpp
JMNum.o: JMNum.cpp
	$(CC) $(CFLAGS) $(ATTR) JMNum.cpp
JMInterpreter.o: JMInterpreter.cpp
	$(CC) $(CFLAGS) $(ATTR) JMInterpreter.cpp
JMMethodCall.o: JMMethodCall.cpp
	$(CC) $(CFLAGS) $(ATTR) JMMethodCall.cpp
FileManager.o: FileManager.cpp
	$(CC) $(CFLAGS) $(ATTR) FileManager.cpp
JMArray.o: JMArray.cpp
	$(CC) $(CFLAGS) $(ATTR) JMArray.cpp
JMDefFunc.o: JMDefFunc.cpp
	$(CC) $(CFLAGS) $(ATTR) JMDefFunc.cpp

clean:
	rm -Rf *.o $(TARGET)
