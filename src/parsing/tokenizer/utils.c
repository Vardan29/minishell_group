#include "minishell.h"

t_token	create_token(t_positions positions, t_token	token,
			char *value, t_token_type type)
{
	token.type = type;
	token.value = ft_strdup(value);
	*positions.cur_pos = positions.it_pos;
	if (type != WORD)
		*positions.cur_pos += ft_strlen(value);
	if (type == SINGLE_QUOTE || type == DOUBLE_QUOTE)
		*positions.cur_pos += 2;
	return (token);
}

t_token	get_symbol_token(t_working_tokens tokens,
			t_positions positions, t_input input)
{
	char	symbol[3];

	if (check_double_char(input.str, positions.it_pos, ">>"))
		ft_strcpy(symbol, ">>");
	else if (check_double_char(input.str, positions.it_pos, "<<"))
		ft_strcpy(symbol, "<<");
	else
		symbol[0] = input.str[positions.it_pos];
	return (create_token(positions, tokens.token, symbol, SYMBOL));
}

t_token	get_symbol_or_word_token(t_working_tokens tokens,
			t_positions positions, t_input input)
{
	if (tokens.cw_token.size > 0)
		return (create_token(positions, tokens.token,
				tokens.cw_token.token, WORD));
	return (get_symbol_token(tokens, positions, input));
}

void	read_quoted_string(char **buffer, char quote,
			t_positions positions, t_input input)
{
	size_t	buffer_size;

	buffer_size = 0;
	++positions.it_pos;
	while (positions.it_pos < input.len && input.str[positions.it_pos] != quote)
		(*buffer)[buffer_size++] = input.str[positions.it_pos++];
	(*buffer)[buffer_size] = '\0';
}
