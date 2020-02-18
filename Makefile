CXX 		:= g++
CXXFLAGS 	:= -g
LDFLAGS 	:=
TARGET 		:= main
SRC 		:= $(wildcard *.cpp)
OBJ 		:= $(SRC:%.cpp=%.o)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJ)
	@rm *.o

clean:
	rm *.o $(TARGET)
