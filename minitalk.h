/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 07:39:00 by thrio             #+#    #+#             */
/*   Updated: 2023/02/01 14:25:10 by thrio            ###   ########.fr       */
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

typedef struct s_struct
{
	unsigned int		bit;
	char				symbol;
	unsigned long int	len;
	char				*message;
}						t_struct;

t_struct			g_bits;

#endif