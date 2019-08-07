NAME = printf.a
HEADER = -c
FLAGS = -Wall -Wextra -Werror
CONFIG = gcc -g $(HEADER) $(FLAGS) $(SRC)
CONFIG2 = ar rc $(NAME) $(OBJ)
CONFIG3 = ranlib $(NAME)
# INCLUDES = -I libft/ 
# CONFIG4 = gcc $(FLAGS) $(SRC) $(CONFIG2) $(LIBFT) -o $(NAME)
SRC = str_char_pointer.c dispatch_table.c num1.c helper.c length.c \
ft_printf.c dispatch.c flags.c length2.c flag_fun.c num2.c
OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(SRC)
	$(CONFIG)
	$(CONFIG2)
	$(CONFIG3)
	
clean:
	/bin/rm -f $(OBJ)
	
fclean: clean
	/bin/rm -f $(NAME)
	
re: fclean all
