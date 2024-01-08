OUT := program
SRC := main_mxv.c
SRC_MXV := main_mxv.c
SRC_PI := main_pi.c
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
	OMP_NUM_THREADS=4 ./$(OUT)

mxv:
	@echo "Building..."
	@rm -f $(OUT)
	@gcc $(SRC) -o $(OUT) -std=gnu99 -O3
	@echo "O3:"
	./$(OUT)
	@gcc $(SRC_MXV) -o $(OUT) -std=gnu99 -O3 $(AUTO)
	@echo "O3 + auto:"
	./$(OUT)
	@gcc $(SRC) -o $(OUT) -std=gnu99 -O3 $(OMP)
	@echo "O3 + OMP:"
	OMP_NUM_THREADS=4 ./$(OUT)

pi:
	@echo "Building..."
	@rm -f $(OUT)
	@gcc $(SRC_PI) -o $(OUT) -std=gnu99 -O3 -ffast-math
	@echo "O3:"
	./$(OUT)
	@gcc $(SRC_PI) -o $(OUT) -std=gnu99 -O3 $(AUTO)
	@echo "O3 + auto:"
	./$(OUT)
	@gcc $(SRC_PI) -o $(OUT) -std=gnu99 -O3 $(OMP)
	@echo "O3 + OMP:"
	OMP_NUM_THREADS=4 ./$(OUT)
