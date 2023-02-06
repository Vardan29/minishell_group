#ifndef UTILS_H
# define UTILS_H

void		resize_map(t_ht *map);
void		update_node_value(t_ht_node *node, void *value);
void		add_new_node(t_ht *map, size_t index,
				const char *key, void *value);
void		rehash_nodes(t_ht *map, t_ht_node **new_table, size_t new_size);
void		update_or_add_node(t_ht *map, unsigned int index,
				const char *key, void *value);
void		print_error_and_set_status(int code, char *cmd,
				char *reason, char *args);
void		remove_node(t_ht *map, t_ht_node *node, t_ht_node *prev,
				size_t index);

bool		is_quote(char c);
bool		is_symbol(char c);
bool		check_double_char(char *input, int it_pos, char dc[2]);

t_ht_node	*find_node(t_ht *map, const char *key,
				t_ht_node **prev, size_t index);
t_ht_node	**create_new_table(size_t size);

#endif
