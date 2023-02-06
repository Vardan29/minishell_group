#include "minishell.h"

t_token	create_token(t_positions positions, t_token	token,
			char *value, int type)
{
	token.type = type;
	ft_strcpy(token.value, value);
	*positions.cur_pos = positions.it_pos;
	if (type != WORD)
		*positions.cur_pos += ft_strlen(value);
	if (type == SINGLE_QUOTE || type == DOUBLE_QUOTE)
		++*positions.cur_pos;
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

void	read_quoted_string(char *buffer, char quote,
			t_positions positions, t_input input)
{
	size_t	buffer_size;

	buffer_size = 0;
	++positions.it_pos;
	while (positions.it_pos < input.len && input.str[positions.it_pos] != quote)
		buffer[buffer_size++] = input.str[positions.it_pos++];
	buffer[buffer_size] = '\0';
}

t_token	get_quoted_token(t_working_tokens tokens, char quote,
			t_positions positions, t_input input)
{
	t_token_type	type;

	if (quote == '\'')
		type = SINGLE_QUOTE;
	else
		type = DOUBLE_QUOTE;

	read_quoted_string(tokens.cw_token.token, quote, positions, input);
	return (create_token(positions, tokens.token,
			tokens.cw_token.token, type));
}

t_token	get_quoted_or_word_token(t_working_tokens tokens, char quote,
			t_positions positions, t_input input)
{
	if (tokens.cw_token.size > 0)
		return (create_token(positions, tokens.token,
				tokens.cw_token.token, WORD));
	return (get_quoted_token(tokens, quote, positions, input));
}

t_token	get_next_token(t_input input, size_t *current_pos)
{
	t_working_tokens	tokens;
	t_positions			positions;

	tokens.cw_token.size = 0;
	positions.it_pos = *current_pos;
	positions.cur_pos = current_pos;
	while (positions.it_pos < input.len)
	{
		if (ft_isspace(input.str[positions.it_pos]) && tokens.cw_token.size > 0)
			return (create_token(positions, tokens.token,
					tokens.cw_token.token, WORD));
		if (is_symbol(input.str[positions.it_pos]))
			return (get_symbol_or_word_token(tokens, positions, input));
		if (is_quote(input.str[positions.it_pos]))
			return (get_quoted_or_word_token(tokens, input.str[positions.it_pos],
					positions, input));
		if (ft_isspace(input.str[positions.it_pos]))
		{
			++positions.it_pos;
			continue ;
		}
		tokens.cw_token.token[tokens.cw_token.size++]
			= input.str[positions.it_pos];
		tokens.cw_token.token[tokens.cw_token.size] = '\0';
		++positions.it_pos;
	}
	if (tokens.cw_token.size > 0)
		return (create_token(positions, tokens.token,
				tokens.cw_token.token, WORD));
	return (tokens.token);
}

void	tokenize(char *input, t_token_arr *tokens)
{
	size_t	current_pos;
	t_input	inp;

	current_pos = 0;
	tokens->size = 0;
	inp.str = input;
	inp.len = strlen(input);
	while (current_pos < inp.len)
		tokens->arr[tokens->size++] = get_next_token(inp, &current_pos);
}
