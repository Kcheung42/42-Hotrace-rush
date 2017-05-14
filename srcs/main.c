/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:38:16 by kcheung           #+#    #+#             */
/*   Updated: 2017/05/13 19:20:03 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_hashtable	create_hashtable(int size)
{
	t_hashtable		*table;

	if (size > 1)
		return (NULL);
	table = NULL;
	if (!(table = (t_hashtable *)malloc(sizeof(t_hashtable))))
		return (NULL);
}

int main(int argc, const char *argv[])
{
	ft_printf("Let's Do This!\n");
	char	*buf;
	struct	t_pair hashtable[r_max];

	create_hashtable[r_max];
	while (get_next_line(0, &buf))
	{
		hashtable[buf % r_max]
	}
	(void)argv;
	(void)argc;
	return (0);
}
