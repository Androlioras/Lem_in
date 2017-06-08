NAME = visu
FLAGS = -Wall -Wextra -Werror
FLAGS2 = -lmlx -framework OpenGL -framework AppKit
LIBFT = ../libft
SMLX = ../smlx
INCLUDES = includes
SRC = srcs
SRCS =  visu.c\
	   init_struct.c\
	   del_struct.c\
	   build.c\
	   main_draw.c\
	   draw_anthill.c\
	   draw_ants.c\
	   keys.c
OBJS = $(SRCS:%.c=%.o)

.PHONY: clean fclean all re norme

all: $(NAME)

%.o: $(SRC)/%.c
	@echo "\033[0m\033[41m\033[37m\033[1m[visu]\033[0m\033[40m\033[33m making '$@'"
	@$(CC) $(FLAGS) -I $(INCLUDES) -I $(LIBFT)/includes -I $(SMLX)/include -c $^

$(NAME): $(OBJS)
	@echo "\033[0m\033[41m\033[37m\033[1m[visu]\033[0m\033[40m\033[33m compiling executable"
	@$(CC) $(FLAGS) -o $(NAME) -I $(INCLUDES) -I $(LIBFT)/includes -I $(SMLX)/include $(OBJS) $(LIBFT)/libft.a $(SMLX)/libsmlx.a $(FLAGS2)
	@echo "\033[0m\033[41m\033[37m\033[1m[visu]\033[0m\033[40m\033[1m done"

clean:
	@echo "\033[0m\033[41m\033[37m\033[1m[visu]\033[0m\033[40m\033[36m cleaning objects"
	@rm -f $(OBJS)
	@echo "\033[0m\033[41m\033[37m\033[1m[visu]\033[0m\033[40m\033[1m done"

fclean: clean
	@echo "\033[0m\033[41m\033[37m\033[1m[visu]\033[0m\033[40m\033[34m cleaning archive"
	@rm -f $(NAME)
	@echo "\033[0m\033[41m\033[37m\033[1m[visu]\033[0m\033[40m\033[34m done"

norme:
	@echo "\033[0m\033[41m\033[37m\033[1m[visu]\033[40m\033[1m making norme\033[32m"
	@norminette $(SRC) $(INCLUDES)
	@echo "\033[0m\033[41m\033[37m\033[1m[visu]\033[0m\033[40m\033[1m done"

re: fclean all
