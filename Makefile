BUILD_DIR = ./build
OPTIONS = -march=armv8-a+sve2

$(shell mkdir -p $(BUILD_DIR))

KERNELS = ./kernels/sve_example_fmlalt.s ./kernels/sve_example_fmlalb.s ./kernels/sve_example_eor.s
OBJ_FILES = $(patsubst kernels/%.s, $(BUILD_DIR)/%.o, $(KERNELS))

test: $(OBJ_FILES) sve2_driver.cpp
	g++ ${OPTIONS} -g -pedantic -Wall -Wextra -Werror -O2 -fopenmp $^ -o $(BUILD_DIR)/sve2