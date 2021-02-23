SRC := src/
LIB := lib/
COMPILER := g++
FLAGS := -Wall
OUTPUT := main
RM := rm

compile:
	$(COMPILER) $(FLAGS) -I$(LIB) $(SRC)*.cpp -o $(OUTPUT)

clean: clear
clear:
	$(RM) $(OUTPUT)
