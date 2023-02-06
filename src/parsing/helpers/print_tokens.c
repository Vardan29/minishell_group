#include "minishell.h"

void print_tokens(t_token_arr *tokens)
{
    size_t i = -1;

    while (++i < tokens->size)
        printf("%s\n", tokens->arr[i].value);
}