#include "minishell.h"

extern int g_exit_code;

void	print_error_and_set_status(int code, char *cmd,
			char *args, char *reason)
{
	g_exit_code = code;
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(args, 2);
	ft_putstr_fd(reason, 2);
}
