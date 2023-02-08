#include "minishell.h"

void	export(char **options, char **args, t_ht *map)
{
	(void)options;
	ht_set(map, args[0], args[1]);
}
