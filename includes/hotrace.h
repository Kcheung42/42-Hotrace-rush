/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:50:21 by kcheung           #+#    #+#             */
/*   Updated: 2017/05/13 21:42:35 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H 

#include "libft.h"
# define r_max 1000000

typedef struct	s_entry
{
	char			*value;
	char			*key;
	struct s_entry	*next;
}				t_entry;

typedef struct	s_hashtbl
{
	int				size;
	struct s_entry	**table;
}				t_hashtbl;
#endif
