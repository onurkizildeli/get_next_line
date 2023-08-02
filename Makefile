SRCS			=	get_next_line.c main.c get_next_line_utils\


OBJS			= $(SRCS:.c=.o)


CC				= gcc
RM				= rm -f
#CFLAGS			= -Wall -Wextra -Werror

NAME			= get_next_line.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus