NAME = libftprintf.a
LIBFT = libft.a
PRINTF_FILES = ft_printf.c conversions.c ft_printf_utils.c
CFLAGS = -Wall -Wextra -Werror
HEADER_FILES = ft_printf.h

PRINTF = $(PRINTF_FILES:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft/

$(NAME): $(PRINTF)
	cp libft/$(LIBFT) $@
	ar rsc $@ $^

%.o: %.c $(HEADER_FILES)
	gcc $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(PRINTF)
	make fclean -C libft/
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
