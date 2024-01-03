OUT := program
SRC := $(wildcard *.c)


build:
	@echo "Building..."
	@rm -f $(OUT)
	@gcc $(SRC) -o $(OUT) -L /usr/lib64/atlas -lsatlas  -std=gnu99
	@echo "Build complete -> $(OUT)"


