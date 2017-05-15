/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:50:21 by kcheung           #+#    #+#             */
/*   Updated: 2017/05/14 22:57:36 by kcheung          ###   ########.fr       */
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
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
# define BUFF_SIZE 9999999

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

typedef	struct		s_fd
{
	int				fd;
	char			*stock;
	char			*ptr;
	struct s_fd		*next;
}					t_fd;

int		sse_strcmp(const char *s1, const char *s2);

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
t_hashtbl *create_hashtable(int size);
int ft_hash(t_hashtbl *hash_table, char *key);
t_entry *add_entry(char *value, char *key);
void set_hash(t_hashtbl *hash_table, char *key, char *value);
char *ht_get(t_hashtbl *hash_table, char *key);
int in_list(const char *line, char c);
char *ft_strtok(char *s1, const char *s2);

#endif
