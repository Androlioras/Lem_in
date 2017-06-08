NAME = lem-in
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = ../libft
INCLUDES = includes
SRC = srcs
SRCS =  lem_in.c\
	   init_struct.c\
	   del_struct.c\
	   build.c\
	   algo.c\
	   algo_2.c
OBJS = $(SRCS:%.c=%.o)

.PHONY: clean fclean all re norme

all: $(NAME)

%.o: $(SRC)/%.c
	@echo "\033[0m\033[41m\033[37m\033[1m[lem_in]\033[0m\033[40m\033[33m making '$@'"
	@$(CC) $(FLAGS) -I $(INCLUDES) -I $(LIBFT)/includes -c $^

$(NAME): $(OBJS)
	@echo "\033[0m\033[41m\033[37m\033[1m[lem_in]\033[0m\033[40m\033[33m compiling executable"
	@$(CC) $(FLAGS) -o $(NAME) -I $(INCLUDES) -I $(LIBFT)/includes $(OBJS) $(LIBFT)/libft.a
	@echo "\033[0m\033[41m\033[37m\033[1m[lem_in]\033[0m\033[40m\033[1m done"

clean:
	@echo "\033[0m\033[41m\033[37m\033[1m[lem_in]\033[0m\033[40m\033[36m cleaning objects"
	@rm -f $(OBJS)
	@echo "\033[0m\033[41m\033[37m\033[1m[lem_in]\033[0m\033[40m\033[1m done"

fclean: clean
	@echo "\033[0m\033[41m\033[37m\033[1m[lem_in]\033[0m\033[40m\033[34m cleaning archive"
	@rm -f $(NAME)
	@echo "\033[0m\033[41m\033[37m\033[1m[lem_in]\033[0m\033[40m\033[34m done"

norme:
	@echo "\033[0m\033[41m\033[37m\033[1m[lem_in]\033[40m\033[1m making norme\033[32m"
	@norminette $(SRC) $(INCLUDES)
	@echo "\033[0m\033[41m\033[37m\033[1m[lem_in]\033[0m\033[40m\033[1m done"

re: fclean all
