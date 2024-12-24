/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:40:16 by cmegret           #+#    #+#             */
/*   Updated: 2024/12/24 10:41:09 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/Minishell.h"

/**
 * Creates a formatted prompt message for the shell
 *
 * @param last_folder Current working directory's last folder name
 *
 * @details
 * Builds a prompt string in the format:
 * "➜  {last_folder} (Minishell) : "
 *
 * @note Memory management:
 * - Returns newly allocated string
 * - Caller must free the returned string
 * - Handles intermediate memory allocations internally
 *
 * @return Formatted prompt string, or NULL if allocation fails
 */
static char	*ft_create_message_prompt(char *last_folder)
{
	char	*message;
	char	*tmp;

	message = ft_strjoin("➜  ", last_folder);
	tmp = ft_strjoin(message, " (");
	free(message);
	message = ft_strjoin(tmp, "Minishell");
	free(tmp);
	tmp = ft_strjoin(message, ") : ");
	free(message);
	return (tmp);
}

/**
 * Generates the shell prompt based on context
 *
 * @param type REDIR_HEREDOC for heredoc prompt, 0 for normal prompt
 *
 * @details
 * Creates one of two prompts:
 * 1. Simple heredoc prompt ("> ")
 * 2. Full prompt with current directory: "➜  {folder} (Minishell) : "
 *
 * Error handling:
 * - Returns "minishell: " if getcwd fails
 * - Handles null/invalid paths gracefully
 *
 * @note Memory management:
 * - Returns newly allocated string from readline
 * - Caller must free the returned string
 *
 * @return User input string, or NULL on EOF
 */
char	*ft_prompt(int type)
{
	char	*prompt;
	char	*message;
	char	cwd[1024];
	char	*last_folder;

	if (type == REDIR_HEREDOC)
		return (readline("> "));
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		last_folder = ft_strrchr(cwd, '/');
		if (last_folder != NULL)
			last_folder++;
		message = ft_create_message_prompt(last_folder);
		prompt = readline(message);
		free(message);
		return (prompt);
	}
	return (readline("minishell: "));
}
