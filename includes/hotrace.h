/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:50:21 by kcheung           #+#    #+#             */
/*   Updated: 2017/05/13 18:53:06 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H 

#include "libft.h"

typedef struct	s_pair
{
	char			*value;
	int				key;
	struct s_pair	*next;
}				t_pair;

#endif
