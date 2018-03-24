NAME = quartic_solver

SRC = src/ft_main.c\
	   src/ft_cubic.c\
		src/ft_quartic.c\
		src/ft_max.c\

FLAGS=-Wall -Wextra -Werror


all: $(NAME)
	

$(NAME): $(OBJ)
	clear
	@make -C libft/ fclean && make -C libft/
	@gcc -o $(NAME) $(FLAG) $(SRC) libft/libft.a 
	
clean:
	clear
	@rm -rf $(OBJ)

fclean: clean
	clear
	@rm -rf $(NAME)

re: fclean all
