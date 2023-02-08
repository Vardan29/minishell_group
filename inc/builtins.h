#ifndef BUILTINS_H
# define BUILTINS_H

void	cd(char **options, char **args, t_ht *map);
void	pwd(char **options, char **args, t_ht *map);
void	env(char **options, char **args, t_ht *map);
void	unset(char **options, char **args, t_ht *map);
void	export(char **options, char **args, t_ht *map);
void	custom_echo(char **options, char **args, t_ht *map);

#endif
