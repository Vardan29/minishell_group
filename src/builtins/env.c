#include "minishell.h"

void	env(t_ht *map)
{
	t_ht_node	*node;
	size_t		i;

	i = -1;
	while (++i < map->size)
	{
		node = map->table[i];
		while (node != NULL)
		{
			printf("%s=%s\n", node->key, node->value);
			node = node->next;
		}
	}
}
