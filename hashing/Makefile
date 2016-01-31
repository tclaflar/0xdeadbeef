CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp hash.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hashing

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
test:
	./$(EXECUTABLE)
clean:
	rm -f *.o $(EXECUTABLE)
