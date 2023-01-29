#include "minishell.h"

void	cd(char *path, t_ht *map)
{
	char	*error;
	char	pwd[PATH_MAX];
	char	old_pwd[PATH_MAX];

	getcwd(old_pwd, sizeof (old_pwd));
	ht_set(map, "OLDPWD", old_pwd);
	if (path && chdir(path) != -1)
	{
		getcwd(pwd, sizeof(pwd));
		ht_set(map, "PWD", pwd);
	}
	else
	{
		error = ft_strjoin("minishell: cd: ", path);
		perror(error);
		free(error);
	}
}
