/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:14:37 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/21 15:05:04 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sigint_handler(int signo) // CTRL+c
{
	if (signo == SIGINT)
	{
		ft_putstr_fd("\n", 2);
		ft_printf("🚭\e[0m \e[1;31m\e[3;43m minishell \e[0m  \e[1;36mLamala \
\e[5;33m⚡\e[0m \e[1;30mChoZeur 🏁\e[0m ");
		//kill(0, SIGINT);
		//exit(EXIT_FAILURE);
	}
}

void	sigquit_handler(int signo) // "CTRL+\"
{
	if (signo == SIGQUIT)
		return ;
}

void	ctrld_handler(char *input) // "CTRL+d"
{
	if (input == NULL)
		exit(EXIT_FAILURE);
}
