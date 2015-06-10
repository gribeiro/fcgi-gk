CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=-lfcgi++ -lfcgi
SOURCES=main.cpp gkFCGIRunner.cpp gkFCGI.cpp eigenRunner.cpp
OBJECTS=$(SOURCES:.cpp=.o)
	EXECUTABLE=eigen

all: $(SOURCES) $(EXECUTABLE)
	    
$(EXECUTABLE): $(OBJECTS) 
	    $(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	    $(CC) $(CFLAGS) $< -o $@
clean:
	@rm -f $(EXECUTABLE) $(OBJECTS)
