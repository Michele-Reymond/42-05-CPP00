SRCS	= 	main.cpp \
			PhoneBook.cpp
CFLAGS	= -Wall -Werror -Wextra -std=c++98
CC		= c++
NAME	= phonebook
OBJS	= ${SRCS:.cpp=.o}
RM		= rm -f

all:	${NAME}

$(NAME): ${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re