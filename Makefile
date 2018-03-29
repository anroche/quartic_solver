NAME = quartic_solver

SRC = src/ft_main.c\
	  src/ft_cubic.c\
	  src/ft_quartic.c\
	  src/ft_max.c\

FLAGS=-Wall -Wextra -Werror


all: $(NAME)


$(NAME): $(OBJ)
	clear
	number=1 ; while [[ $$number -le 10 ]] ; do \
		   cat cow/cow.txt; \
		   sleep 0.3;\
		   clear; \
		   cat cow/cow1.txt; \
		   sleep 0.3; \
		   clear; \
		   ((number = number + 1)) ; \
		   done; \ & 

	@make -C libft/ fclean && make -C libft/
	@gcc -o $(NAME) $(FLAG) $(SRC) libft/libft.a 

clean:
	clear
	@rm -rf $(OBJ)

fclean: clean
	clear
	@rm -rf $(NAME)

re: fclean all
