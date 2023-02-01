# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thrio <thrio@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 11:14:21 by thrio             #+#    #+#              #
#    Updated: 2023/02/01 14:18:15 by thrio            ###   ########.fr        #
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

NAMECLIENT	= client
NAMESERVER	= server

all:	${NAMESERVER} ${NAMECLIENT}

${NAMESERVER}: ${SERVER_O}
		${MAKE} -C Libft/
		${CC} ${CFLAGS} ${SERVER_O} Libft/libft.a -o server

${NAMECLIENT}: ${CLIENT_O}
		${MAKE} -C Libft/
		${CC} ${CFLAGS} ${CLIENT_O} Libft/libft.a -o client
		
bonus	:	all

clean:
		${RM} ${CLIENT_O} ${SERVER_O}
		${MAKE} clean -C Libft/
		

fclean:		clean
		${RM} server client
		${MAKE} fclean -C Libft/

re:		fclean all

.PHONY:		all clean fclean re norminette bonus ser cli libft minitalk
