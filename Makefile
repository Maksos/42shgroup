NAME = 42sh

HEADER = -I ./inc

SRC = ./src/main.c\
			./src/tools.c\
			./src/tools_term.c\
			./src/tools_2_term.c\
			./src/ft_free.c\
			./src/termcaps_init.c\
			./src/termread.c\
			./src/arrows.c\
			./src/copypastecut.c\
			./src/ctrl_shift.c\
			./src/ft_signal.c\
			./src/ft_error.c\
			./src/pp.c\
			./src/fill_pp.c\
			./src/pp_in.c\
			./src/pp_red.c\
			./src/exec_pp.c\
			./src/pipe.c\
			./src/red_fd.c\
			./src/exec_it.c\
			./src/check_data.c\
			./src/lred.c\
			./src/rred.c\
			./src/tab.c\
			./src/built_in.c\
			./src/ft_env.c\
			./src/ft_cd.c\
			./src/ft_un_set_env.c\
			./src/ft_export.c

CFLAG = -Wall -Werror -Wextra

OBJ= $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make re -C libft
	clang $(CFLAG) $(OBJ) $(HEADER) -o $(NAME) ./libft/libft.a -ltermcap

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all
