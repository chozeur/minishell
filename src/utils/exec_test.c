/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:45:14 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/06 10:56:28 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*find_path(char *cmd, char **my_paths)
{
	int		i;
	char	*part_path;
	char	*path;

	i = 0;
	if (access(cmd, F_OK) == 0)
		return (cmd);
	while (my_paths[i])
	{
		part_path = ft_strjoin(my_paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		//free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (my_paths[++i])
		free(my_paths[i]);
	free(my_paths);
	return (0);
}

void	execute(char *av, char **my_env)
{
	int		i;
	char	**cmd;
	char	*path;

	i = -1;
	cmd = ft_split(av, ' ');
	path = find_path(cmd[0], get_path(my_env));
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		exit_shell(my_env);
		//error();
	}
	if (execve(path, cmd, my_env) == -1)
		exit_shell(my_env);
}
