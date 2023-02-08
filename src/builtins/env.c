#include "minishell.h"

void	env(char **options, char **args, t_ht *map)
{
	t_ht_node	*node;
	size_t		i;

	(void)options;
	(void)args;
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
