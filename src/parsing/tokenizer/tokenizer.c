#include "minishell.h"

t_token	get_quoted_token(t_working_tokens tokens, char quote,
			t_positions positions, t_input input)
{
	t_token_type	type;

	if (quote == '\'')
		type = SINGLE_QUOTE;
	else
		type = DOUBLE_QUOTE;

	char *buffer = ft_calloc(input.len + 1, sizeof(char));
	read_quoted_string(&buffer, quote, positions, input);
	tokens.cw_token.token = buffer;
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
			return (get_quoted_or_word_token(tokens, input.str[positions.it_pos], positions, input));
		if (ft_isspace(input.str[positions.it_pos]))
		{
			++positions.it_pos;
			continue ;
		}
		if (tokens.cw_token.size == 0)
			tokens.cw_token.token = ft_calloc(input.len + 1, sizeof(char));
		tokens.cw_token.token[tokens.cw_token.size++] = input.str[positions.it_pos];
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
	tokens->arr = ft_calloc(inp.len, sizeof(t_token));
	while (current_pos < inp.len)
		tokens->arr[tokens->size++] = get_next_token(inp, &current_pos);
}
