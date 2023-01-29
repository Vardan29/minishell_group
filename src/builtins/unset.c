#include "minishell.h"

void	unset(t_ht *map, const char *key)
{
	ht_remove_entry(map, key);
}
