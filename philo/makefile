LIBFT 	=	libft/ft_strlen.c \
			libft/ft_atoi.c \
			libft/ft_split.c \
			libft/ft_isdigit.c \
			libft/ft_putendl_fd.c \

UTILITY =	utils.c

ALGO =	

SRCS =	init.c \
		$(LIBFT) \
		$(UTILITY) \
		philosophers.c \
		main.c

NAME	=	philosophers
CC		=	gcc
FLAGS	=	-Wall -Werror -Wextra -pthread -fsanitize=address
INCLUDE =	-I include
OBJS	=		$(SRCS:.c=.o)
EXEC = philo

RM		=		@rm -f

.c.o:
			@$(CC) $(FLAGS) -c -I include $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@$(CC) $(FLAGS) $(OBJS) -o $(EXEC)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(EXEC)

re:			fclean all