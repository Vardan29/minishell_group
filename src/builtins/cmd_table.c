#include "minishell.h"

void    initialize_cmd_table(t_ht *cmd_table)
{
    ht_init_map(cmd_table, 15);
    ht_set(cmd_table, "cd", cd);
    ht_set(cmd_table, "env", env);
    ht_set(cmd_table, "pwd", pwd);
    ht_set(cmd_table, "unset", unset);
    ht_set(cmd_table, "export", export);
    ht_set(cmd_table, "echo", custom_echo);
    // ht_set(cmd_table, ">", redirect_to);
    // ht_set(cmd_table, "<", read_from);
    // ht_set(cmd_table, ">>", append_to);
    // ht_set(cmd_table, "<<", open_heredoc);
    // ht_set(cmd_table, "|", open_pipe);
}
