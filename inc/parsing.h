#ifndef PARSING_H
# define PARSING_H

# include "types.h"

t_token	create_token(t_positions positions, t_token	token,
			char *value, t_token_type type);
t_token	get_symbol_token(t_working_tokens tokens,
			t_positions positions, t_input input);
t_token	get_symbol_or_word_token(t_working_tokens tokens,
			t_positions positions, t_input input);
void	read_quoted_string(char **buffer, char quote,
			t_positions positions, t_input input);
void	tokenize(char *input, t_token_arr *tokens);
void    print_tokens(t_token_arr *tokens);

# endif