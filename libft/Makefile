NAME = libft.a
SO = libft.so
CC = gcc
INCLUDES = includes
SRC = srcs
LIBFT = libft
FLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c\
	   if_forest.c\
	   number.c\
	   unsigned.c\
	   string.c\
	   char.c\
	   params.c\
	   pointer.c\
	   long.c\
	   other.c
OBJS = $(SRCS:.c=.o)

.PHONY: clean fclean all re norme

all: $(NAME)

$(LIBFT)/libft.a:
	@echo "\033[0m\033[44m\033[37m\033[1m[printf]\033[40m\033[1m making libft"
	@make -C $(LIBFT)
	@echo "\033[0m\033[44m\033[37m\033[1m[printf]\033[40m\033[1m done"
	@cp $(LIBFT)/$(NAME) $(NAME)

$(NAME): $(LIBFT)/libft.a $(OBJS)
	@echo "\033[0m\033[44m\033[37m\033[1m[printf]\033[40m\033[1m adding printf"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[0m\033[44m\033[37m\033[1m[printf]\033[40m\033[1m done"

%.o: $(SRC)/%.c
	@echo "\033[0m\033[44m\033[37m\033[1m[printf]\033[0m\033[40m\033[33m making '$@'"
	@$(CC) $(FLAGS) -I $(INCLUDES) -c $^

clean:
	@echo "\033[0m\033[44m\033[37m\033[1m[printf]\033[0m\033[40m\033[36m cleaning sub-directories"
	@make -C $(LIBFT) clean
	@echo "\033[0m\033[44m\033[37m\033[1m[printf]\033[0m\033[40m\033[36m done"
	@echo "\033[0m\033[44m\033[37m\033[1m[printf]\033[0m\033[40m\033[36m cleaning objects"
	@rm -f $(OBJS)
	@echo "\033[0m\033[44m\033[37m\033[1m[printf]\033[0m\033[40m\033[36m done"

fclean: clean
	@echo "\033[0m\033[44m\033[37m\033[1m[printf]\033[0m\033[40m\033[34m cleaning sub-directories"
	@make -C $(LIBFT) fclean
	@echo "\033[0m\033[44m\033[37m\033[1m[printf]\033[0m\033[40m\033[34m done"
	@echo "\033[0m\033[44m\033[37m\033[1m[printf]\033[0m\033[40m\033[34m cleaning archive"
	@rm -f $(NAME)
	@echo "\033[0m\033[44m\033[37m\033[1m[printf]\033[0m\033[40m\033[34m done"

norme:
	@echo "\033[0m\033[44m\033[37m\033[1m[printf]\033[40m\033[1m making norme\033[32m"
	@make -C $(LIBFT) norme
	@norminette $(SRC) $(INCLUDES)
	@echo "\033[0m\033[44m\033[1m[printf]\033[40m\033[1m done"

re: fclean all
