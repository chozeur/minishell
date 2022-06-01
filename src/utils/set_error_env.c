/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_error_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:58:04 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/01 16:39:05 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	set_error_env(void)
{
	int		j;
	char	**spl;
	char	*exp;
	int		k;

	j = 0;
	spl = NULL;
	exp = ft_strjoin(ft_strdup("?="), ft_itoa(data.error_status));
	/////////////////////////////////////////
	// ft_printf("-------\nexp = %s\n-------\n", exp);
	/////////////////////////////////////////
	while (data.my_env[j])
	{
		spl = ft_split(data.my_env[j], '=');
		if (!ft_strncmp(spl[0], exp, ft_strlen(spl[0])) && \
			exp[ft_strlen(spl[0])] == '=')
		{
			free(data.my_env[j]);
			data.my_env[j] = ft_strdup(exp);
			k = -1;
			while (spl[++k])
				free(spl[k]);
			free(spl);
			return ;
		}
		j++;
	}
	data.my_env[j] = ft_strdup(exp);
}
