/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 17:43:08 by kcheung           #+#    #+#             */
/*   Updated: 2017/05/14 18:01:30 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}

char	*ft_strchr(const char *s, int c)
{
	char *catch;

	catch = (char *)s;
	while (*catch != c)
	{
		if (*catch == '\0')
			return (NULL);
		catch++;
	}
	return (catch);
}

char	*ft_strcpy(char *dst, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}


void	*ft_memset(void *b, int c, size_t len)
{
	char	*changer;
	size_t	i;

	changer = b;
	i = 0;
	while (i < len)
		changer[i++] = c;
	return (b);
}

char	*ft_strnew(size_t size)
{
	char *fresh_string;

	fresh_string = (char *)malloc(sizeof(char) * size + 1);
	if (fresh_string == NULL)
		return (NULL);
	else
	{
		ft_memset(fresh_string, '\0', size + 1);
		return (fresh_string);
	}
}

size_t	ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

void	ft_strdel(char **as)
{
	if (as)
	{
		free(*as);
		*as = NULL;
	}
}

char	*ft_strdup(const char *s1)
{
	char	*s2;

	if ((s2 = ft_strnew(ft_strlen(s1))))
		ft_strcpy(s2, (char *)s1);
	return (s2);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;

	if (!s1 || !s2)
		return (0);
	if ((tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		ft_strcat(ft_strcpy(tmp, (char *)s1), s2);
	return (tmp);
}

int		check_previous(char **leftovers, char **line)
{
	char		*tmp;
	char		*swap;

	if ((tmp = ft_strchr(*leftovers, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(*leftovers);
		swap = ft_strdup(tmp + 1);
		ft_strdel(leftovers);
		*leftovers = ft_strdup(swap);
		ft_strdel(&swap);
		tmp = NULL;
		return (1);
	}
	return (0);
}

int		check_current(char *buffer, char **leftovers, char **line)
{
	char		*tmp;
	char		*swap;

	if ((tmp = ft_strchr(buffer, '\n')))
	{
		*tmp = '\0';
		*line = ft_strjoin(*leftovers, buffer);
		swap = ft_strdup(tmp + 1);
		ft_strdel(leftovers);
		*leftovers = ft_strdup(swap);
		ft_strdel(&swap);
		tmp = NULL;
		ft_strdel(&buffer);
		return (1);
	}
	return (0);
}

int		find_return(int size, char *buffer, char **leftovers, char **line)
{
	if (size < 0)
		return (-1);
	ft_strdel(&buffer);
	if (**leftovers)
	{
		*line = ft_strdup(*leftovers);
		ft_strdel(leftovers);
		return (1);
	}
	*line = NULL;
	ft_strdel(leftovers);
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char	*leftovers;
	char		*buffer;
	int			size;
	char		*swap;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	if (!leftovers)
		leftovers = ft_strnew(0);
	else if (check_previous(&leftovers, line))
		return (1);
	buffer = ft_strnew(BUFF_SIZE);
	while ((size = (read(fd, buffer, BUFF_SIZE))) > 0)
	{
		buffer[size] = '\0';
		if (check_current(buffer, &leftovers, line))
			return (1);
		swap = ft_strjoin(leftovers, buffer);
		ft_strdel(&leftovers);
		leftovers = ft_strdup(swap);
		ft_strdel(&swap);
	}
	return (find_return(size, buffer, &leftovers, line));
}
