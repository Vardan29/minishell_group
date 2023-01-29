#ifndef BUILTINS_H
# define BUILTINS_H

void	pwd(void);
void	env(t_ht *map);
void	cd(char *path, t_ht *map);
void	unset(t_ht *map, const char *key);
void	custom_echo(int new_line, char **args);
void	export(t_ht *map, const char *key, void *value);

#endif
