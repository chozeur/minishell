/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:32:37 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/11 17:03:06 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exit_shell(char **my_env, int stat)
{
	ft_putstr_fd("exit", 0);
	if (my_env)
		free_split(my_env);
	if (g_data.previous_dir)
		free(g_data.previous_dir);
	exit(stat);
}
