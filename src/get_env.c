/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:25:02 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/02 13:56:05 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	init_env(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
		i++;
	if (!(g_env = malloc(sizeof(char *) * i + 1)))
		exit_shell();//return (NULL);
	i = 0;
	while (envp[i])
	{
		if (!(g_env[i] = ft_strdup(envp[i])))
			exit_shell();
		i++;
	}
}

char	**get_path(void)
{
	int		i;
	char	**my_paths;

	i = 0;
	while (ft_strnstr(g_env[i], "PATH", 4) == 0)
		i++;
	my_paths = ft_split(g_env[i] + 5, ':');
	return (my_paths);
}
