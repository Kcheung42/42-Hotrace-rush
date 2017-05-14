/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:26:12 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/18 15:15:25 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		in_list(const char *line, char c)
{
	while (*line)
	{
		if (*line == c)
			return (1);
		line++;
	}
	return (0);
}

char	*ft_strtok(char *s1, const char *s2)
{
	static char	*ptr;
	char		*ret;

	if (s1)
		ptr = s1;
	if (!ptr)
		return (NULL);
	ret = ptr;
	while (*ptr && !in_list(s2, *ptr))
		ptr++;
	if (*ptr)
	{
		*ptr = '\0';
		ptr++;
	}
	return (ret);
}
