OUT := program
SRC := $(wildcard *.c)


build:
	@echo "Building..."
	@rm -f $(OUT)
	@gcc $(SRC) -o $(OUT) -std=gnu99
	@echo "Build complete -> $(OUT)"
