# Variables
CXX = g++
TARGET = output
SRC = main.cpp

# Recipies
$(TARGET): $(SRC)
	$(CXX) $(SRC) -o $(TARGET)

# Cleaning
.PHONY: clean
clean:
	rm -f $(TARGET)
