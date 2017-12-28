CXX = g++-5 -std=c++11
CXXFLAGS = -Wall -O -g -MMD # use -MMD to generate dependencies
LIBFLAGS = # no external libraries required
SOURCES = $(wildcard *.cpp)  # list of all .cpp files in the current directory
OBJECTS = $(SOURCES:.cpp=.o) # .o files depend upon .cpp files with same names
DEPENDS = ${OBJECTS:.o=.d}   # .d file is list of dependencies for corresponding .cpp file
EXEC=chessAI

# First target in the makefile is the default target.
# Note that the LIBFLAGS must come last in the command
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXEC)  $(LIBFLAGS)

%.o: %.cc
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(LIBFLAGS)

-include ${DEPENDS}

.PHONY: clean
clean:
	rm  -f $(OBJECTS) $(DEPENDS) $(EXEC)
