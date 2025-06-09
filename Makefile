CXX = g++
CXXFLAGS = -Wall -Wextra -g3 -Iincludes
SRC = src/almacen.cpp src/mochila.cpp src/rutas.cpp src/utils.cpp

MAIN = main.cpp
BIN = output/main

all: $(BIN)

$(BIN): $(MAIN) $(SRC)
	$(CXX) $(CXXFLAGS) $(MAIN) $(SRC) -o $(BIN)

run: all
	./$(BIN)

clean:
	rm -f output/main

