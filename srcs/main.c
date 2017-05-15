/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:38:16 by kcheung           #+#    #+#             */
/*   Updated: 2017/05/14 22:58:50 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

/******************************************************/
/**              funtion prototypes                  **/
/******************************************************/
t_hashtbl *create_hashtable(int size);
int ft_hash(t_hashtbl *hash_table, char *key);
t_entry *add_entry(char *value, char *key);
void set_hash(t_hashtbl *hash_table, char *key, char *value);
char *ht_get(t_hashtbl *hash_table, char *key);
int in_list(const char *line, char c);
char *ft_strtok(char *s1, const char *s2);

t_hashtbl	*create_hashtable(int size)
{
	t_hashtbl	*hash_table;
	int			i;

	i = 0;
	if (size < 1)
		return (NULL);
	hash_table = NULL;
	if (!(hash_table = (t_hashtbl *)malloc(sizeof(t_hashtbl))))
		return (NULL);
	if (!(hash_table->table = (t_entry **)malloc(sizeof(t_entry *) * size)))
		return (NULL);
	while (i < size)
	{
		hash_table->table[i] = NULL;
		i++;
	}
	hash_table->size = size;
	return (hash_table);
}

int            ft_hash(t_hashtbl *hash_table, char *key)
{
    unsigned long int    hashval;
    int                    i;

    hashval = 0;
    while ((i = *key++))
        hashval = i + (hashval << 6) + (hashval << 16) - hashval;
    return (hashval % hash_table->size);
}

t_entry		*add_entry(char *value, char *key)
{
	t_entry *new;

	if (!(new = (t_entry *)malloc(sizeof(t_entry))))
		return (NULL);
	if (!(new->value = strdup(value)))
		return (NULL);
	if (!(new->key = strdup(key)))
		return (NULL);
	new->next = NULL;
	return (new);
}

void		set_hash(t_hashtbl *hash_table, char *key, char *value)
{
	t_entry		*cur;
	t_entry		*last;
	t_entry		*new_entry;
	int			bin;
	
	last = NULL;
	new_entry = NULL;
	cur = NULL;
	bin = ft_hash(hash_table, key);
	cur = hash_table->table[bin];
	while (cur != NULL && cur->key != NULL && strcmp(key, cur->key) != 0)
	{
		last = cur;
		cur = cur->next;
	}
	if(cur != NULL && cur->key != NULL && strcmp(key, cur->key) == 0)
	{
		free(cur->key);
		cur->key = strdup(key);
	}
	else
	{
		new_entry = add_entry(value, key);
		if (cur == hash_table->table[bin])
		{
			new_entry->next = cur;
			hash_table->table[bin] = new_entry;
		}
		else if (cur == NULL)
			last->next = new_entry;
		else
		{
			new_entry->next = cur;
			last->next = new_entry;
		}
	}
}

char		*ht_get(t_hashtbl *hash_table, char *key)
{
	int		bin;
	t_entry	*cur;

	bin = ft_hash(hash_table, key);
	cur = hash_table->table[bin];

	while (cur != NULL && cur->key != NULL  && strcmp(key, cur->key) != 0)
		cur = cur->next;
	if (cur == NULL || cur->key == NULL || strcmp(key, cur->key) != 0)
		return (NULL);
	else
		return (cur->value);
}

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
	static int	i;
	char		*ret;

	if (s1)
		ptr = s1;
	if (*ptr == '\0')
		return (NULL);
	if (*ptr == '\n')
	{
		i++;
		ptr++;
		return ("\n");
	}
	ret = ptr;
	while (*ptr && !in_list(s2, *ptr))
	{
		i++;
		ptr++;
	}
	if (in_list(s2, *ptr))
		*ptr = '\0';
	ptr++;
	i++;
	return (ret);
}

int			main(void)
{
	char		*key;
	char		*value;
	char		*buffer;
	char		*file;
	int			ret;
	int			buf_count;
	t_hashtbl	*hash_table;

	buf_count = 0;
	buffer = ft_strnew(BUFF_SIZE);
	file = ft_strnew(BUFF_SIZE);
	hash_table = create_hashtable(r_max);
	ret = 0;
	while((ret = read(0, buffer, BUFF_SIZE)) > 1)
	{
		if (ret < 0)
			return (0);
		buf_count += ret;
		file = ft_strcat(file,buffer);
		if (ret == BUFF_SIZE)
			file = ft_realloc(file, buf_count + BUFF_SIZE + 1);
		ft_bzero(buffer, BUFF_SIZE);
	}
	key = ft_strtok(file, "\n");
	if(!(value = ft_strtok(NULL, "\n")))
		return (0);
	set_hash(hash_table, key, value);
	while ((key = ft_strtok(NULL, "\n")) && strcmp(key, "\n"))
	{
		if ((value = ft_strtok(NULL, "\n")))
			set_hash(hash_table, key, value);
	}
	while ((key = ft_strtok(NULL, "\n")))
	{
		if ((value = ht_get(hash_table, key)) != NULL)
		{
			ft_putstr(value);
			ft_putchar('\n');
		}
		else
		{
			ft_putstr(key);
			ft_putstr(": Not found.\n");
		}
	}
	free(file);
	return (0);
}
