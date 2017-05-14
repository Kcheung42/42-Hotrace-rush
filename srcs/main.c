/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:38:16 by kcheung           #+#    #+#             */
/*   Updated: 2017/05/13 21:45:10 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
/******************************************************/
/**              funtion prototypes                  **/
/******************************************************/
t_hashtbl *create_hashtable(int size);
int ft_hash(t_hashtbl *hash_table, char *key);
void set_hash(t_hashtbl *hash_table, char *key, char *value);
char *ht_get(t_hashtbl *hash_table, char *key);
t_entry *add_entry(char *value, char *key);

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

int			ft_hash(t_hashtbl *hash_table, char *key)
{
	unsigned long int	hashval;
	int					i;

	hashval = 0;
	i = 0;
	while (hashval < ULONG_MAX && *key)
	{
		hashval = hashval << 5;
		hashval += *key;
		key++;
	}
	return (hashval % hash_table->size);
}

t_entry	*add_entry(char *value, char *key)
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

void	set_hash(t_hashtbl *hash_table, char *key, char *value)
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
	while (cur != NULL && cur->key != NULL && ft_strcmp(key, cur->key) != 0)
	{
		last = cur;
		cur = cur->next;
	}
	if(cur != NULL && cur->key != NULL && ft_strcmp(key, cur->key) == 0)
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

char	*ht_get(t_hashtbl *hash_table, char *key)
{
	int		bin;
	t_entry	*cur;

	bin = ft_hash(hash_table, key);
	cur = hash_table->table[bin];

	while (cur != NULL && cur->key != NULL  && ft_strcmp(key, cur->key) != 0)
		cur = cur->next;
	if (cur == NULL || cur->key == NULL || ft_strcmp(key, cur->key) != 0)
		return (NULL);
	else
		return (cur->value);
}

int main(int argc, const char *argv[])
{
	ft_printf("Let's Do This!\n");
	char		*buf;
	int			i;
	char		*key;
	t_hashtbl	*hash_table;

	i = 0;
	hash_table = create_hashtable(r_max);
	while (get_next_line(0, &buf))
	{
		i += 1;
		key = ft_itoa(i);
		set_hash(hash_table, key, buf);
	}
	printf("%s\n", ht_get(hash_table, "1"));
	printf("%s\n", ht_get(hash_table, "2"));
	printf("%s\n", ht_get(hash_table, "3"));
	printf("%s\n", ht_get(hash_table, "4"));

	(void)argv;
	(void)argc;
	return (0);
}
