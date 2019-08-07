NAME = ft_ls
# HEADER = -c
FLAGS = -g -Wall -Wextra -Werror -fsanitize=address
CONFIG = gcc $(FLAGS) $(SRC) $(LIBFT) -o $(NAME)
# CONFIG2 = ar rc $(NAME) $(OBJ) $(PRINTF)
# CONFIG3 = ranlib $(NAME)
LIBFT = libft/libft.a
SRC = dir_list.c ls_helper.c len.c print.c sort.c ft_ls.c
OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME) $(LIBFT)

$(LIBFT): libft/*.c
	make -C libft/

$(NAME): $(SRC) $(LIBFT)
	$(CONFIG)
	# $(CONFIG2)
	# $(CONFIG3)

clean:
	/bin/rm -f $(OBJ)
	make clean -C libft/

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C libft/

re: fclean all
