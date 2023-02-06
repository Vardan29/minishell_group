#include "minishell.h"

bool	is_symbol(char c)
{
	return (c == '>' || c == '<' || c == '|'
		|| c == '&' || c == '(' || c == ')');
}

bool	is_quote(char c)
{
	return (c == '\"' || c == '\'');
}

bool	check_double_char(char *input, int it_pos, char dc[2])
{
	return (!ft_strncmp(&input[it_pos], dc, 2));
}
