/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:19:38 by tbrebion          #+#    #+#             */
/*   Updated: 2022/04/26 16:51:22 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
void	parse_input(char *input)
{
	int		i;
	char	**in_tab;
	t_tok	*token_tab;

	i = 0;
	in_tab = ft_split(input, ' ');
	while (in_tab[i])
		i++;
	if (!(token_tab = malloc(sizeof(t_tok) * (i + (i - 1)))))
		return ; 
	i = 0;
	while (in_tab[i])
	{
		printf("%s\n", in_tab[i]);
		i++;
	}

}*/


int main(int ac, char **av, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	if (!(g_env = malloc(sizeof(char *) * i + 1)))
		return (0);
	i = 0;
	while (envp[i])
	{
		g_env[i] = ft_strdup(envp[i]/*, ft_strlen(env[i]*/);
		i++;
	}
	g_env[i] = 0;
    /*while(1)
    {
        printf("<Prompt>:");
        //scanf("%s", buffer);
		prompt = readline();	
		printf("%s\n", prompt);
    }*/
	i = 0;
	while (g_env[i])
	{
		printf("%s\n", g_env[i]);
		i++;
	}
	return (0);
}
