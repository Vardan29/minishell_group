#include "minishell.h"

int	g_exit_code = 0;

void	parse_prompt(void)
{
	printf("gg\n");
	exit(0);
}

// void	shell_loop(char *env[])
// {
// 	while (TRUE)
// 		parse_prompt();
// }

int	main(int argc, char *argv[], char *env[])
{
	t_ht	map;
	t_token_arr tokens;
	char 	*line = readline("minishell $>");
	if (line[0])
		add_history(line);
	else
		exit(0);

	(void)argc;
	(void)argv;
	ht_init_map(&map, 20);
	char_array_to_ht(env, &map);
	tokenize(line, &tokens);
	print_tokens(&tokens);
	return (0);
}
