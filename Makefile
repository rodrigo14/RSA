SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib

CC = g++

CFLAGS = -W -Wall -pedantic -ansi -MMD -lm -g3
INCLUDES = -Iinclude
LIBS =  -lntl

GAME = rsa
GAME_MAIN = $(SRC_DIR)/*.cpp

SRC = ${wildcard $(SRC_DIR)/*.cpp}
OBJ = ${addprefix $(OBJ_DIR)/, ${notdir ${SRC:.cpp=.o}}}

.PHONY: clean depend

all:
	@mkdir -p $(OBJ_DIR)
	@$(MAKE) $(GAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

$(GAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJ) $(LIBS)

it_simple:
	g++ -o rsa src/main.cpp -lntl -g -pedantic -lm -Iinclude

clean:
	@echo Cleaning...
	@rm -rf obj/ bin/ *~

-include $(OBJ:.o=.d)
