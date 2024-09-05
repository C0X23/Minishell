/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:30:52 by cmegret           #+#    #+#             */
/*   Updated: 2024/09/04 20:41:28 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*prompt;

	ft_check_args(argc, argv);
	prompt = readline("Minishell : ");
	while (prompt != NULL)
	{
		add_history(prompt);
		execute_cmd(ft_parse(ft_tokenize(prompt)), envp);
		free(prompt);
		prompt = readline("Minishell : ");
	}
	return (0);
}
