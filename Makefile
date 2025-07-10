NAME		:= fdf
BONUSNAME	:= fdf_bonus
CC			:= cc
RM			:= rm -f
FLAGS		:= -Wall -Wextra -Werror
DEBUG		:= -g

HEADDIR		:= ./includes/
HEADLIST	:= fdf.h
HEADERS		:= $(addprefix $(HEADDIR), $(HEADLIST))

SRCSDIR		:= ./src/
SRCSLIST	:= main.c \
						hooks.c \
						file_handling.c \
						gile_handling2.c \
						color_handling.c \
						lines.c \
						math_helpers.c \
						transform.c \
						transform2.c \
						draw.c \
						generate_map.c \
SRCS		:= $(addprefix $(SRCSDIR), $(SRCSLIST))
BONUSSRCSLIST	:= main.c \
						hooks.c \
						file_handling.c \
						gile_handling2.c \
						color_handling.c \
						lines.c \
						math_helpers.c \
						transform.c \
						transform2.c \
						draw.c \
						generate_map.c \
BONUSSRCS		:= $(addprefix $(SRCSDIR), $(BONUSSRCSLIST))

OBJSDIR			:= ./obj/
OBJSLIST		:= $(SRCSLIST:.c=.o)
OBJS			:= $(addprefix $(OBJSDIR), $(OBJSLIST))
BONUSOBJSLIST	:= $(BONUSSRCSLIST:.c=.o)
BONUSOBJS		:= $(addprefix $(OBJSDIR), $(BONUSOBJSLIST))

LIBFTDIR		:= ./libft/
LIBFT			:= $(LIBFTDIR)libft.a

MLXDIR			:= ./minilibx-linux/
MLX				:= $(MLXDIR)libmlx.a

LIBS			:= -L$(LIBFTDIR) -L$(MLXDIR) -lft -lmlx -lXext -lX11 -lm
INCS			:= -I$(HEADDIR) -I$(LIBFTDIR) -I$(MLXDIR)

$(NAME):		$(MLX) $(LIBFT) $(OBJSDIR) $(OBJS)
				$(CC) $(FLAGS) $(DEBUG) $(OBJS) -o $(NAME) $(LIBS) $(INCS)

$(BONUSNAME):	$(MLX) $(LIBFT) $(OBJSDIR) $(BONUSOBJS)
				$(CC) $(FLAGS) $(DEBUG) $(BONUSOBJS) -o $(BONUSNAME) $(LIBS) $(INCS)

$(LIBFT):
				make -C $(LIBFTDIR)

$(MLX):
				git submodule init
				git submodule update
				make -C $(MLXDIR)

$(OBJSDIR)%.o:	$(SRCSDIR)%.c $(HEADERS)
				$(CC) $(FLAGS) $(DEBUG) $(INCS) -c $< -o $@

$(OBJSDIR):
				mkdir -p $(OBJSDIR)

.PHONY:			all clean fclean re bonus test bonustest


all:			$(NAME)

clean:
				$(RM) -r $(OBJSDIR)
				make -C $(LIBFTDIR) clean
				make -C $(MLXDIR) clean

fclean:			clean
				$(RM) $(NAME)
				$(RM) $(BONUSNAME)
				make -C $(LIBFTDIR) fclean

re:				fclean all

bonus:			$(BONUSNAME)

test:			all
				./$(NAME) test_maps/42.fdf

bonustest:		bonus
				./$(BONUSNAME) test_maps/42.fdf