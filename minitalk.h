/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 07:39:00 by thrio             #+#    #+#             */
/*   Updated: 2023/01/22 12:50:25 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdint.h>
# include "Libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>

# define BUFFSIZE 1024

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

typedef struct	s_struct
{
	unsigned int	bit;
	char			symbol;
}				t_struct;

t_struct			s_bits;

#endif