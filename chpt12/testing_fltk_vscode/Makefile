SRC = main.cpp
CXX = g++
CXXFLAGS = -std=c++14 -Wall $(shell fltk-config --cxxflags)

LFLAGS = $(shell fltk-config --ldstaticflags)

OBJS = $(SRC:.cpp=.o)

%.o: %.cpp
		$(CXX) $(CXXFLAGS) -c $(<) -o $(@)

EXE = main

all: $(EXE)

$(EXE): $(OBJS)
		$(CXX) -o $@ $^ $(LFLAGS)

%.o: %.cpp *.h
		$(CXX) -o $@ -c $< $(CXXFLAGS)

depend:
		makedepend -- $(CXXFLAGS) -- $(SRC)

strip: $(EXE)
		strip --strip-all $(EXE)

clean:
		rm -f $(EXE) $(OBJS)