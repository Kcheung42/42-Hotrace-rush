/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:38:16 by kcheung           #+#    #+#             */
/*   Updated: 2017/05/14 14:30:49 by kcheung          ###   ########.fr       */
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
	while (cur != NULL && cur->key != NULL && sse_strcmp(key, cur->key) != 0)
	{
		last = cur;
		cur = cur->next;
	}
	if(cur != NULL && cur->key != NULL && sse_strcmp(key, cur->key) == 0)
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

	while (cur != NULL && cur->key != NULL  && sse_strcmp(key, cur->key) != 0)
		cur = cur->next;
	if (cur == NULL || cur->key == NULL || sse_strcmp(key, cur->key) != 0)
		return (NULL);
	else
		return (cur->value);
}

int			main(int argc, const char *argv[])
{
	/* clock_t begin = clock(); */
	char		*buf1;
	char		*buf2;
	size_t		len;
	char		*value;
	t_hashtbl	*hash_table;

	len = 0;
	hash_table = create_hashtable(r_max);
	buf1 = NULL;
	buf2 = NULL;
	while (getline(&buf1, &len, stdin) != -1)
	{
		if (*buf1 == '\n')
			break;
		getline(&buf2, &len, stdin);
		set_hash(hash_table, buf1, buf2);
	}
	while (getline(&buf1, &len, stdin) != -1)
	{
		if ((value = ht_get(hash_table, buf1)) != NULL)
			printf("%s", value);
		else
		{
			buf1 = strtok(buf1, "\n");
			printf("%s Not found.\n", buf1);
		}
	}
	/* clock_t end = clock(); */
	/* double time_spent = (double)(end - begin) / CLOCKS_PER_SEC; */
	/* printf("time:%f\n", time_spent); */
	(void)argv;
	(void)argc;
	return (0);
}
