#include "minishell.h"

size_t	ht_hash(const char *key, int size)
{
	size_t	hash;
	size_t	i;

	i = -1;
	hash = 0;
	while (++i < ft_strlen(key))
		hash = (hash + key[i]) % size;
	return (hash);
}

void	ht_init_map(t_ht *map, size_t size)
{
	size_t	i;

	map->table = (t_ht_node **)malloc(sizeof(t_ht_node *) * size);
	i = -1;
	while (++i < size)
		map->table[i] = NULL;
	map->size = size;
	map->num_elements = 0;
}

void	ht_set(t_ht *map, const char *key, void *value)
{
	size_t	index;

	if (map->num_elements >= map->size * 0.7)
		resize_map(map);
	index = ht_hash(key, map->size);
	update_or_add_node(map, index, key, value);
	map->num_elements++;
}

void	*ht_get(t_ht *map, const char *key)
{
	size_t		index;
	t_ht_node	*node;

	index = ht_hash(key, map->size);
	node = map->table[index];
	while (node != NULL)
	{
		if (ft_strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}

void	ht_remove_entry(t_ht *map, const char *key)
{
	size_t		index;
	t_ht_node	*prev;
	t_ht_node	*node;

	index = ht_hash(key, map->size);
	node = find_node(map, key, &prev, index);
	if (node)
		remove_node(map, node, prev, index);
}
