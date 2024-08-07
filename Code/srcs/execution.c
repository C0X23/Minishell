/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:48:18 by francis           #+#    #+#             */
/*   Updated: 2024/07/19 15:15:33 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Minishell.h"

ft_execution()
{
	if (ft_has_pipe)
	{

		list commands = ft_split_pipe();
		ft_execute_pipes(commands);
	}
	else
		{
			if (ft_has_redir())
				fd = ft_execute_redir(); // redir error handling ?
			ft_execute_command(commands);
		}

}

ft_has_redir(struct token *head)
{
	while (head)
	{
		if (head->type == REDIR)
			return (1);
		head = head->next;
	}
	return (0);
}