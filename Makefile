
NAME			:= fdf
BONUSNAME		:= fdf_bonus
CC				:= cc
RM		    	:= rm -f
FLAGS			:= -Wall -Wextra -Werror
DEBUG			:= -g

HEADDIR			:= ./includes/
HEADLIST		:= fdf.h
HEADERS			:= $(addprefix ${HEADDIR}, ${HEADLIST})

SRCSDIR			:= ./src/
SRCSLIST		:= main.c \
					hooks.c \
					file_handling.c \
					file_handling2.c \
					draw.c \
					math_helpers.c \
					lines.c \
					color_handling.c \
					generate_maps.c \

SRCS			:= $(addprefix ${SRCSDIR}, ${SRCSLIST})
BONUSSRCSLIST	:= main.c \
					hooks_bonus.c \
					file_handling.c \
					file_handling2.c \
					draw.c \
					math_helpers.c \
					lines.c \
					color_handling.c \
					generate_maps.c \

BONUSSRCS		:= $(addprefix ${SRCSDIR}, ${BONUSSRCSLIST})

OBJSDIR			:= ./obj/
OBJSLIST		:= ${SRCSLIST:.c=.o}
OBJS			:= $(addprefix ${OBJSDIR}, ${OBJSLIST})
BONUSOBJSLIST	:= ${BONUSSRCSLIST:.c=.o}
BONUSOBJS		:= $(addprefix ${OBJSDIR}, ${BONUSOBJSLIST})

LIBFTDIR		:= ./libft/
LIBFT			:= ${LIBFTDIR}libft.a

MLXDIR			:= ./minilibx-linux/
MLX				:= ${MLXDIR}libmlx.a

LIBS			:= -L${LIBFTDIR} -L${MLXDIR} -lft -lmlx -lXext -lX11 -lm
INCS			:= -I${HEADDIR} -I${LIBFTDIR} -I${MLXDIR}

CYAN			:= \033[0;36m
RESET			:= \033[0m

${NAME}:		${MLX} ${LIBFT} ${OBJSDIR} ${OBJS}
				@echo ""
				@echo "${CYAN}Compiling ${NAME} ...${RESET}"
				${CC} ${FLAGS} ${DEBUG} ${OBJS} -o ${NAME} ${LIBS} ${INCS}
				@echo ""
				@echo "${CYAN}$(NAME) Created${RESET}"

${BONUSNAME}:	${MLX} ${LIBFT} ${OBJSDIR} ${BONUSOBJS}
				@echo ""
				@echo "${CYAN}Compiling ${BONUSNAME} ...${RESET}"
				${CC} ${FLAGS} ${DEBUG} ${BONUSOBJS} -o ${BONUSNAME} ${LIBS} ${INCS}
				@echo ""
				@echo "${CYAN}$(BONUSNAME) Created${RESET}"

${LIBFT}:
				make -C ${LIBFTDIR}

${MLX}:
				@echo ""
				@echo "${CYAN}Compiling ${MLX} ...${RESET}"
				git submodule init
				git submodule update
				make -C ${MLXDIR}

${OBJSDIR}%.o:	${SRCSDIR}%.c ${HEADERS} compiling
				${CC} ${FLAGS} ${DEBUG} ${INCS} -c $< -o $@

${OBJSDIR}:
				mkdir -p ${OBJSDIR}

.PHONY:			all clean fclean re bonus test bonustest

.INTERMEDIATE:	compiling

compiling:
				@echo ""
				@echo "${CYAN}Compiling Objects ...${RESET}"

all:			${NAME}

clean:
				@echo ""
				@echo "${CYAN}Deleting $(NAME) Objects ...${RESET}"
				${RM} -r ${OBJSDIR}
				make -C ${LIBFTDIR} clean
				make -C ${MLXDIR} clean

fclean:			clean
				@echo ""
				@echo "${CYAN}Deleting $(NAME) Executable ...${RESET}"
				${RM} ${NAME}
				@echo "${CYAN}Deleting $(BONUSNAME) Executable ...${RESET}"
				${RM} ${BONUSNAME}
				make -C ${LIBFTDIR} fclean

re:				fclean all

bonus:			${BONUSNAME}

test:			all
				./${NAME} test_maps/42.fdf

bonustest:		bonus
				./${BONUSNAME} test_maps/42.fdf