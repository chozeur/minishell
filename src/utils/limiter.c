/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limiter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:02:39 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/20 14:41:08 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	here_doc_other_supply(char *line, char *ret)
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

static void	here_doc_supply(char *limiter, char *tmp)
{
	char	*line;
	char	*ret;

	ret = ft_strdup("");
	reinit_sig();
	while (1)
	{
		line = readline("> ");
		here_doc_other_supply(line, ret);
		if ((ft_strncmp(line, limiter, \
		ft_max((ft_strlen(line) - 1), ft_strlen(limiter))) == 0))
		{
			ret = ft_strjoin(ret, "\n");
			free(line);
			break ;
		}
		ret = ft_strjoin(ret, expand_str(line));
		ret = ft_strjoin(ret, "\n");
	}
	del_last_backslash_n(ret);
	hd_supply(ret, tmp);
	ft_putstr(ret);
	free(ret);
	exit(0);
}

void	here_doc(void)
{
	pid_t	pid1;
	int		status;
	char	*tmp;

	tmp = NULL;
	if (g_data.lst->content->type != I_D_INREDIR && \
	ft_strcmp(g_data.lst->content->val, "cat") != 1)
		tmp = g_data.lst->content->val;
	while (g_data.lst->content->type != I_D_INREDIR)
		g_data.lst = g_data.lst->next;
	if (!g_data.lst->next)
	{
		ft_putstr_fd("syntax error\n", 0);
		g_data.error_status = 2;
		exit(g_data.error_status);
		return ;
	}
	ignore_sig();
	pid1 = fork();
	if (pid1 == 0)
		here_doc_supply(g_data.lst->next->content->val, tmp);
	waitpid(-1, &status, 0);
	g_data.error_status = WEXITSTATUS(status);
	exit(g_data.error_status);
}
