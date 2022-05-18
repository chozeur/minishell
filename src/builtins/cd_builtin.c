/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:27:23 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/18 13:44:24 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	cd_builtin(t_data *data, int i)
{
	char	*cwd;

	cwd = NULL;
	cwd = getcwd(cwd, 4096);
	closedir((DIR *)cwd);
	if (chdir(get_n_lst(data->Tokens, i + 1)->content->val) == -1)
		return ;
}

