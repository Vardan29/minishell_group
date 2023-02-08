#include "minishell.h"

void	custom_echo(char **options, char **args, t_ht *map)
{
	int	i;

	(void)map;
	i = -1;
	while (args[++i])
		printf("%s ", args[i]);
	if (options[0])
		printf("\n");
}
