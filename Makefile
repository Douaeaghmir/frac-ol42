NAME = fractol
NAME_BONUS = fractol_bonus
CC = cc
FLAGS = -Wall -Wextra -Werror -Wunreachable-code -fsanitize=address -O3 -g -Iincludes

SRCS = mandatory/color.c mandatory/hooks_event.c mandatory/julia.c mandatory/main.c \
	mandatory/mandelbrot.c mandatory/util3s.c mandatory/utils.c mandatory/utils2.c 

SRCS_BONUS = bonus/color_bonus.c bonus/hooks_event_bonus.c bonus/main_bonus.c \
	bonus/Tricorn_bonus.c bonus/utils_bonus_2.c bonus/utils_bonus1.c

RM = rm -rf
NPROC = $(shell nproc)
HEADER = mandatory/fractol.h
HEADER_BONUS = bonus/fractol_bonus.h
MLX_LIB = MLX42/build/libmlx42.a
OS = $(shell uname -s)

ifeq ($(OS), Linux)
	LINK = -IMLX42/include -ldl -lglfw -pthread -lm
else
	LINK = -lglfw -ldl -L/Users/$(USER)/.brew/opt/glfw/lib
endif

OBJ_DIR = obj
OBJ_DIR_MANDATORY = $(OBJ_DIR)/mandatory
OBJ_DIR_BONUS = $(OBJ_DIR)/bonus

OBJS = $(addprefix $(OBJ_DIR_MANDATORY)/, $(SRCS:mandatory/%.c=%.o))
OBJS_BONUS = $(addprefix $(OBJ_DIR_BONUS)/, $(SRCS_BONUS:bonus/%.c=%.o))

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(FLAGS) $(OBJS) $(MLX_LIB) $(LINK) -o $@

$(NAME_BONUS): $(OBJS_BONUS) $(MLX_LIB)
	$(CC) $(FLAGS) $(OBJS_BONUS) $(MLX_LIB) $(LINK) -o $@

$(MLX_LIB):
	@cmake -S MLX42 -B MLX42/build
	@make -C MLX42/build -j$(NPROC)

$(OBJ_DIR_MANDATORY)/%.o: mandatory/%.c $(HEADER)
	@mkdir -p $(OBJ_DIR_MANDATORY)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: bonus/%.c $(HEADER_BONUS)
	@mkdir -p $(OBJ_DIR_BONUS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all