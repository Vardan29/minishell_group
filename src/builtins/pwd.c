#include "minishell.h"

void	pwd(char **options, char **args, t_ht *map)
{
	char	cwd[PATH_MAX];

	(void)map;
	(void)args;
	(void)options;
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		printf("%s\n", cwd);
	else
		perror("minishell: pwd");
}
