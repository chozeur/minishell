/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:19:38 by tbrebion          #+#    #+#             */
/*   Updated: 2022/04/25 18:31:03 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_tok	*parse_input(char *input)
{
	int		i;
	/*int		j;
	int		cmpt;*/
	char	**in_tab;
	t_tok	*token_tab;

	i = 0;
	in_tab = ft_split(input, ' ');
	while (in_tab[i])
		i++;
	if (!(token_tab = malloc(sizeof(t_tok) * (i + (i - 1)))))
		return (NULL); // ft_exit ??
	return (token_tab);
}

int main(void)
{
    char    buffer[BUFF_SIZE];

    while(1)
    {
        printf("<Prompt>:");
        scanf("%s",buffer);
        if (ft_strncmp("exit", buffer, 4)==0)
            exit(0);
        else
            printf("Commande inconnue ...\n");
    }
	return (0);
}
