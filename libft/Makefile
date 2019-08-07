NAME = libft.a
HEADER = -c
FLAGS = -g -Wall -Wextra -Werror -fsanitize=address
CONFIG = gcc $(HEADER) $(FLAGS) $(SRC)
CONFIG2 = ar rc $(NAME) $(OBJ) $(PRINTF)
CONFIG3 = ranlib $(NAME)
PRINTF = ft_printf/*.o
SRC = *.c
OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME) $(PRINTF)

$(PRINTF):
	make -C ft_printf/

$(NAME): $(SRC) $(PRINTF)
	$(CONFIG)
	$(CONFIG2)
	$(CONFIG3)

clean:
	/bin/rm -f $(OBJ)
	make clean -C ft_printf/

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C ft_printf/

re: fclean all
