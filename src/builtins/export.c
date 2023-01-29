#include "minishell.h"

void	export(t_ht *map, const char *key, void *value)
{
	ht_set(map, key, value);
}
