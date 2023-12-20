SRC = drill.cpp Graph.cpp GUI.cpp Simple_window.cpp Window.cpp
CXX = g++
CXXFLAGS = $(shell fltk-config --cxxflags --use-images) 

LFLAGS = $(shell fltk-config --ldstaticflags --use-images)

OBJS = $(SRC:.cpp=.o)

%.o: %.cpp
		$(CXX) $(CXXFLAGS) -c $(<) -o $(@)

EXE = drill

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