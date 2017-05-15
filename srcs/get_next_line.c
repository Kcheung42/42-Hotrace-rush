/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 16:03:41 by kcheung           #+#    #+#             */
/*   Updated: 2017/05/14 22:57:01 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

/******************************************************/
/**              funtion prototypes                  **/
/******************************************************/
t_fd *ft_fd_add(t_fd **head, int fd);
int ft_strlen_n(char *str);
void *ft_memset(void *str, int c, size_t len);
void ft_bzero(void *s, size_t n);
void *ft_memalloc(size_t size);
void ft_memdel(void **ap);
char *ft_strnew(size_t size);
void *ft_memcpy(void *dst, void *src, size_t n);
void *ft_realloc(void *ptr, size_t size);
char *ft_strcpy(char *dst, const char *src);
char *ft_strcat(char *s1, const char *s2);
void ft_putstr(char const *str);
void ft_putchar(char c);

t_fd	*ft_fd_add(t_fd **head, int fd)
{
	t_fd	*new;
	t_fd	*temp;

	temp = *head;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	if (temp == NULL)
	{
		new = (t_fd *)malloc(sizeof(t_fd));
		new->fd = fd;
		new->ptr = NULL;
		new->stock = NULL;
		new->next = *head;
		*head = new;
	}
	return (*head);
}

int		ft_strlen_n(char *str)
{
	if (*str == '\n' || *str == '\0')
		return (0);
	return (1 + ft_strlen_n(str + 1));
}

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*temp;
	unsigned int	i;
	unsigned char	uc;

	temp = (unsigned char *)str;
	i = 0;
	uc = c;
	while (i < len)
	{
		temp[i] = uc;
		i++;
	}
	return ((void*)str);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memalloc(size_t size)
{
	void	*new_memory;

	new_memory = malloc(size);
	if (new_memory)
		ft_bzero(new_memory, size);
	return (new_memory);
}

void	ft_memdel(void **ap)
{
	if (!ap)
		return ;
	else if (*ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

char	*ft_strnew(size_t size)
{
	return (ft_memalloc(size + 1));
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	void	*temp;
	int		i;
	char	*cdst;
	char	*csrc;

	cdst = (char *)dst;
	csrc = (char *)src;
	/* printf("here\n"); */
	/* printf("%c\n",csrc[0]); */
	/* printf("here\n"); */
	i = 0;
	temp = cdst;
	while (n > 0 && csrc[i])
	{
		cdst[i] = csrc[i];
		i++;
		n--;
	}
	return (temp);
}

void	*ft_realloc(void *ptr, size_t size)
{
	char *temp;

	if (!size && ptr)
	{
		if (!(temp = (char *)malloc(1)))
			return (0);
		ft_memdel(&ptr);
		return (temp);
	}
	if (!(temp = ft_strnew(size)))
		return (0);
	if (ptr)
	{
		ft_memcpy(temp, ptr, size);
		ft_memdel(&ptr);
	}
	return (temp);
}

char	*ft_strcpy(char *dst, const char *src)
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

char	*ft_strcat(char *s1, const char *s2)
{
	char *temp;

	temp = s1;
	while (*temp)
		temp++;
	while (*s2)
	{
		*temp = *s2;
		temp++;
		s2++;
	}
	*temp = '\0';
	return (s1);
}

void	ft_putstr(char const *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
