#include "minishell.h"

void	custom_echo(int new_line, char **args)
{
	int	i;

	i = -1;
	while (args[++i])
		printf("%s ", args[i]);
	if (new_line)
		printf("\n");
}
