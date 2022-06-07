/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:54:47 by flcarval          #+#    #+#             */
/*   Updated: 2022/06/07 16:14:51 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_list	*get_n_lst(t_list **Tokens, int n)
{
	t_list	*lst;

	lst = *Tokens;
	while (lst && n)
	{
		lst = lst->next;
		n--;
	}
	return (lst);
}
