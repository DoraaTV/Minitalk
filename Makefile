# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thrio <thrio@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 11:14:21 by thrio             #+#    #+#              #
#    Updated: 2023/01/21 17:29:16 by thrio            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT		= client.c

SERVER		= server.c

CLIENT_O	= ${CLIENT:.c=.o}

SERVER_O	= ${SERVER:.c=.o}

NAME		= minitalk

CC			= cc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -g3

all	:	${NAME}

${NAME}:	lib server client

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

lib:
	cd Libft && make && cd ..

server: ${SERVER_O}
		${CC} ${CFLAGS} ${SERVER_O} Libft/libft.a -o server

client: ${CLIENT_O}
		${CC} ${CFLAGS} ${CLIENT_O} Libft/libft.a -o client
		
bonus	:	${NAME}

clean:
		${RM} ${CLIENT_O} ${SERVER_O}
		cd Libft && make clean && cd ..
		

fclean:		clean
		${RM} server client
		cd Libft && make fclean && cd ..

re:		fclean all

.PHONY:		all clean fclean re norminette bonus server client libft minitalk
