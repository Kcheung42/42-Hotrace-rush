/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:50:21 by kcheung           #+#    #+#             */
/*   Updated: 2017/05/13 22:52:51 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H 

# define r_max 1000000
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

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
