CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp node.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=linklist

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
test:
	./$(EXECUTABLE)
clean:
	rm -f *.o $(EXECUTABLE)
