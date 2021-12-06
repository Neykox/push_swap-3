SRCS = check.c main.c movers.c sort_big_p1.c sort_big_p2.c sort_big_p3.c sort_small_p1.c sort_small_p2.c sort_five.c
C.O = ${SRCS:.c=.o}
H = push_swap.h
NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

leak :
	$(CC) $(FLAGS) $(SRCS) -fsanitize=address -o $(NAME)

clean :
	rm -f $(C.O)

fclean : clean
	rm -f $(NAME)

re : fclean all
