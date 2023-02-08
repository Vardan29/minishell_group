#include "minishell.h"

void	unset(char **options, char **args, t_ht *map)
{
	(void)map;
	(void)args;
	(void)options;
	ht_remove_entry(map, args[0]);
}
