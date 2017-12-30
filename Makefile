CXX = g++-5 -std=c++11
CXXFLAGS = -Wall -O -g -MMD # use -MMD to generate dependencies
LIBFLAGS = # no external libraries required

SRCDIR = src
OBJDIR = obj
BINDIR = bin

SOURCES = $(wildcard $(SRCDIR)/*.cpp)  # list of all .cpp files in the src directory
INCLUDES := $(wildcard $(SRCDIR)/*.h) # list of all .h files in the src directory
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o) # .o files depend upon .cpp files with same names
DEPENDS = ${OBJECTS:$(OBJDIR)/%.o=$(OBJDIR)/%.d}   # .d file is list of dependencies for corresponding .cpp file

TARGET=chessAI

$(BINDIR)/$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(BINDIR)/$(TARGET)  $(LIBFLAGS)

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(LIBFLAGS)

-include ${DEPENDS}

.PHONY: clean
clean:
	rm  -f $(OBJECTS) $(DEPENDS) $(BINDIR)/$(TARGET)
