/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:35:41 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/27 11:08:15 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	if (!s1)
		return (-1);
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	while (i < n && (s1[i] || s2[i]))
	{
		t = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (t != 0)
			return (t);
		i++;
	}
	return (t);
}
