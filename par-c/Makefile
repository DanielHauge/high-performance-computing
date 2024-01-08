OUT := program
SRC := $(wildcard *.c)
OMP := -fopenmp -ffast-math
AUTO := -ftree-parallelize-loops=4 -ffast-math

build:
	@echo "Building..."
	@rm -f $(OUT)
	@gcc $(SRC) -o $(OUT) -std=gnu99 -O3
	@echo "O3:"
	./$(OUT)
	@gcc $(SRC) -o $(OUT) -std=gnu99 -O3 $(AUTO)
	@echo "O3 + auto:"
	./$(OUT)
	@gcc $(SRC) -o $(OUT) -std=gnu99 -O3 $(OMP)
	@echo "O3 + OMP:"
	./$(OUT)

