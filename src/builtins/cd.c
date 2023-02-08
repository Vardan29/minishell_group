#include "minishell.h"

void	cd(char **options, char **args, t_ht *map)
{
	char	*error;
	char	pwd[PATH_MAX];
	char	old_pwd[PATH_MAX];

	(void)options;
	getcwd(old_pwd, sizeof (old_pwd));
	ht_set(map, "OLDPWD", old_pwd);
	if (args[0] && chdir(args[0]) != -1)
	{
		getcwd(pwd, sizeof(pwd));
		ht_set(map, "PWD", pwd);
	}
	else
	{
		error = ft_strjoin("minishell: cd: ", args[0]);
		perror(error);
		free(error);
	}
}
