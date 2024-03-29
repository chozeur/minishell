/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limiter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:02:39 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/30 07:51:20 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	here_doc_other_supply(char *line, char *ret)
{
	if (!line)
	{
		free(ret);
		write(2, "\n", 1);
		exit(EXIT_SUCCESS);
	}
}

static void	del_last_backslash_n(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	if (str[i] == '\n')
		str[i] = 127;
}

static void	hd_supply(char *ret, char *tmp)
{
	if (tmp)
	{
		free(ret);
		if (ft_strcmp(tmp, "env") == 1)
		{
			print_env(g_data.my_env);
			exit(0);
		}
		else if (is_builtin(tmp))
		{
			builtin_manager(0);
			is_cd();
			is_unset();
			is_export();
			exit(0);
		}
		else
			execute(0);
	}
}

static void	here_doc_supply(char *tmp)
{
	char	*line;
	char	*ret;
	char	*exp;
	int		i_lim;

	ret = ft_strdup("");
	exp = NULL;
	reinit_sig();
	i_lim = 0;
	line = NULL;
	ret = here_doc_supply_loop(line, ret, exp, i_lim);
	del_last_backslash_n(ret);
	hd_supply(ret, tmp);
	ft_putstr(ret);
	free(ret);
	free_split(g_data.limiters);
	exit(0);
}

void	here_doc(void)
{
	pid_t	pid1;
	int		status;
	char	*tmp;

	tmp = NULL;
	tmp = is_cmd_in_hd(tmp);
	while (g_data.lst->content->type != I_D_INREDIR)
		g_data.lst = g_data.lst->next;
	if (!g_data.lst->next || check_meta_char() == 1 || !g_data.limiters)
	{
		ft_putstr_fd("syntax error\n", 0);
		g_data.error_status = 2;
		exit(g_data.error_status);
		return ;
	}
	ignore_sig();
	pid1 = fork();
	if (pid1 == 0)
		here_doc_supply(tmp);
	waitpid(-1, &status, 0);
	g_data.error_status = WEXITSTATUS(status);
	exit(g_data.error_status);
}
