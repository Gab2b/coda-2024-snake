# Makefile

NAME = snake

SRCS = sdl.c\
	   snake.c\
	   corps.c\
	   main.c

all :  $(NAME)

$(NAME): $(SRCS)
	gcc -fdiagnostics-color=always -g $(SRCS) -o $(NAME) -lSDL2 -lSDL2_image

fclean:
	rm -f $(NAME)

re: fclean all