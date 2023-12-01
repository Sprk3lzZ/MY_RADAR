##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME := my_radar
SRC := $(shell find src/ -type f -name "*.c")
OBJ := $(SRC:%.c=obj/%.o)

all:
	@$(MAKE) -s -j12 $(NAME)

clean:
	@rm -rf obj/

fclean: clean
	@rm -f $(NAME)

re: fclean all

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) -lm -lcsfml-graphics -lcsfml-window \
		-lcsfml-system -lcsfml-audio

obj/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) -o $@ -c $< -Iinclude -Wall -Wextra -Wpedantic
