NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
HEADER = -I./include
SRC = src/ft_printf.c src/format.c src/utils.c
OBJ = $(SRC:src/%.c=obj/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

obj/%.o: src/%.c
	make -C libft/
	mkdir -p $(dir $@)
	cc $(CFLAGS) $(HEADER) -c $< -o $@ 

clean:
	make clean -C libft/
	rm -rf obj

fclean: clean
	make fclean -C libft/
	rm -rf $(NAME)

re: fclean all