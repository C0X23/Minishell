/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:00:54 by cmegret           #+#    #+#             */
/*   Updated: 2024/09/13 19:21:37 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/Minishell.h"

// returns the number of tokens in our linked list
int	ft_count_token_list_args(struct s_token *tok)
{
	int	i;

	i = 0;
	while (tok)
	{
		i++;
		tok = tok->next;
	}
	return (i);
}

// prints each token's contents (tok->str)
void	ft_print_all_token_strings(struct s_token **head)
{
	struct s_token	*iterator;

	iterator = *head;
	while (iterator != 0)
	{
		printf("token: %s\n", iterator->str);
		iterator = iterator->next;
	}
}

// Traverses the linked list of tokens and prints each token's type, if any
void	ft_tokenization_checker(struct s_token *head)
{
	const char	*token_type_strings[9] = {
		"UNDEFINED TOKEN", "WORD", "NEWLINE", "REDIR_INPUT", "REDIR_OUTPUT",
		"REDIR_APPEND", "REDIR_HEREDOC", "PIPE", "END_OF_INPUT"
	};

	while (head)
	{
		if (head->str && head->type)
			printf("string: {%s} – token type: %s\n",
				head->str, token_type_strings[head->type]);
		else
		{
			printf("type or string not found: ");
			if (head->type)
				printf("head-type: %s, head->str not found\n",
					token_type_strings[head->type]);
			if (head->str)
				printf("head-str: %s, head->type not found\n", head->str);
			else
				printf("nor head->str nor head-type found\n");
		}
		head = head->next;
	}
}
