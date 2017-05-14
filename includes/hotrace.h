/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:50:21 by kcheung           #+#    #+#             */
/*   Updated: 2017/05/13 19:14:37 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H 

#include "libft.h"
# define r_max = 100;

typedef struct	s_pair
{
	char			*value;
	int				key;
	struct s_pair	*next;
}				t_pair;

typedef struct	s_hashtable
{
	int			size;
	s_pair		**table;
}				t_hashtable;
#endif
