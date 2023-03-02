#ifndef TYPES_H
# define TYPES_H

typedef enum e_token_type		t_token_type;

typedef struct s_ht_node		t_ht_node;
typedef struct s_ht				t_ht;
typedef struct stat				t_stat;
typedef struct s_token			t_token;
typedef struct s_input			t_input;
typedef struct s_positions		t_positions;
typedef struct s_cw_token		t_cw_token;
typedef struct s_token_arr		t_token_arr;
typedef struct s_working_tokens	t_working_tokens;
typedef void (*t_builtin_func)(char **options, char **args, t_ht *map);


struct s_ht_node
{
	char		*key;
	void		*value;
	t_ht_node	*next;
};

struct s_ht
{
	size_t		size;
	size_t		num_elements;
	t_ht_node	**table;
};

struct s_token
{
	t_token_type	type;
	char			*value;
};

struct s_input
{
	char	*str;
	size_t	len;
};

struct s_positions
{
	size_t	it_pos;
	size_t	*cur_pos;
};

struct s_token_arr
{
	t_token	*arr;
	size_t	size;
};

struct s_cw_token
{
	char	*token;
	size_t	size;
};

struct s_working_tokens
{
	t_token		token;
	t_cw_token	cw_token;
};

#endif
