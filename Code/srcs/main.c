/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:48:17 by francis           #+#    #+#             */
/*   Updated: 2024/08/01 15:21:45 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Minishell.h"

int	main(int argc, char **envp)
{
	char	*prompt;

	(void)argc;
	while ((prompt = readline("Minishell : ")) != NULL)
	{
		if (*prompt) // verify if chain is not empty
		{
			add_history(prompt); // Move it later when here doc will be implemented, to avoid to add the here doc in the history
			execute_cmd(ft_parse(ft_tokenize(prompt)), envp);
			
		}
		// if (i % 5 == 0) // clean history 
		// 	rl_clear_history();

		free(prompt); // free the memory allocated by readline
	}
	return 0;
}
