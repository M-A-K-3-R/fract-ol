NAME = fractol

CC = gcc 

CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

RM = rm -f

SRC = main.c tools.c Mandelbrot.c mlx_hooks.c Julia.c tools_2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(MLX) $(OBJ) -o $(NAME)
		
clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all
