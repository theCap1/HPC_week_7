BUILD_DIR = ./build
OPTIONS = -march=armv8-a+sve

$(shell mkdir -p $(BUILD_DIR))

KERNELS = ./kernels/triad_low.s
OBJ_FILES = $(patsubst kernels/%.s, $(BUILD_DIR)/%.o, $(KERNELS))

test: $(OBJ_FILES) triad_driver.cpp
	g++ ${OPTIONS} -g -pedantic -Wall -Wextra -Werror -O2 -fopenmp $^ -o $(BUILD_DIR)/triad_low