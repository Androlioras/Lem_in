LEM_IN = lem_in
LIBFT = libft
SMLX = smlx
VISU = visualisateur

.PHONY: all clean fclean re $(LIBFT) $(SMLX) $(LEM_IN) $(VISU)

all: $(LIBFT) $(SMLX) $(LEM_IN) $(VISU)

$(LIBFT):
	@echo "\033[0m\033[41m\033[1m[---lem_in---]\033[0m\033[1m making libft\033[0m"
	@make -C $(LIBFT) all
	@echo "\033[0m\033[41m\033[1m[---lem_in---]\033[0m\033[1m done\033[0m"

$(SMLX):
	@echo "\033[0m\033[41m\033[1m[---lem_in---]\033[0m\033[1m making libsmlx\033[0m"
	@make -C $(SMLX) all
	@echo "\033[0m\033[41m\033[1m[---lem_in---]\033[0m\033[1m done\033[0m"

$(LEM_IN):
	@echo "\033[0m\033[41m\033[1m[---lem_in---]\033[0m\033[1m making lem-in\033[0m"
	@make -C $(LEM_IN)
	@echo "\033[0m\033[41m\033[1m[---lem_in---]\033[0m\033[1m done\033[0m"
	@cp $(LEM_IN)/lem-in ./

$(VISU):
	@echo "\033[0m\033[41m\033[1m[---lem_in---]\033[0m\033[1m making visu\033[0m"
	@make -C $(VISU)
	@echo "\033[0m\033[41m\033[1m[---lem_in---]\033[0m\033[1m done\033[0m"
	@cp $(VISU)/visu ./

clean:
	@echo "\033[0m\033[41m\033[1m[---lem_in---]\033[0m\033[1m cleaning directories\033[0m"
	@make -C $(LIBFT) clean
	@make -C $(SMLX) clean
	@make -C $(LEM_IN) clean
	@make -C $(VISU) clean
	@echo "\033[0m\033[41m\033[1m[---lem_in---]\033[0m\033[1m done\033[0m"

fclean: clean
	@echo "\033[0m\033[41m\033[1m[---lem_in---]\033[0m\033[1m cleaning executables and libraries\033[0m"
	@make -C $(LIBFT) fclean
	@make -C $(SMLX) fclean
	@make -C $(LEM_IN) fclean
	@make -C $(VISU) fclean
	@rm -f lem-in
	@rm -f visu
	@echo "\033[0m\033[41m\033[1m[---lem_in---]\033[0m\033[1m done\033[0m"

re: fclean all

norme:
	@make -C $(LIBFT) norme
	@make -C $(SMLX) norme
	@make -C $(LEM_IN) norme
	@make -C $(VISU) norme