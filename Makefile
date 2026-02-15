# Variables
CXX = g++
CXXFLAGS = -g -O0 -Wall -Wextra
TARGET = output
SRC = main.cpp

# Recipes
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Cleaning
.PHONY: clean
clean:
	rm -f $(TARGET)
