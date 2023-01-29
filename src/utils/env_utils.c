#include "minishell.h"

void	char_array_to_ht(char *env[], t_ht *map)
{
	int		i;
	char	*key;
	char	*value;

	i = -1;
	while (env[++i])
	{
		ft_split_by_first_appearance(env[i], '=', &key, &value);
		ht_set(map, key, value);
	}
}

char	*create_key_value_pair(const char *key, const char *value)
{
	char	*tmp;
	char	*pair;

	tmp = ft_strjoin(key, "=");
	pair = ft_strjoin(tmp, value);
	free(tmp);
	return (pair);
}

char	**ht_to_char_array(t_ht *map)
{
	char		**array;
	size_t		i;
	size_t		count;
	t_ht_node	*node;

	array = (char **)malloc(sizeof(char *) * (map->num_elements + 1));
	count = -1;
	i = -1;
	while (++i < map->size)
	{
		node = map->table[i];
		while (node != NULL)
		{
			array[++count] = create_key_value_pair(node->key,
					(char *)node->value);
			node = node->next;
		}
	}
	array[count] = NULL;
	return (array);
}
