/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_redir_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:37:29 by francis           #+#    #+#             */
/*   Updated: 2024/12/24 10:36:23 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/Minishell.h"

/**
 * @brief Checks if a filename is valid according to naming conventions.
 *
 * This function checks that the filename adheres to length and character
 * constraints.
 * A valid filename must have a length between 1 and NAME_MAX, and must
 * only contain
 * alphanumeric characters, dots (.), hyphens (-), and underscores (_).
 * Additionally,
 * the filename must not start with a hyphen (-).
 *
 * @param filename The filename to check.
 * @return 1 if the filename is valid, 0 otherwise.
 */
int	is_valid_filename(const char *filename)
{
	size_t	len;
	size_t	i;

	if (filename[0] == '-')
		return (0);
	len = ft_strlen(filename);
	if (len == 0 || len > NAME_MAX)
	{
		printf("minishell: %s: File name too long\n", filename);
		return (0);
	}
	i = 0;
	while (i < len)
	{
		if (!ft_isalnum(filename[i]) && filename[i] != '.'
			&& filename[i] != '-' && filename[i] != '_')
		{
			printf("minishell: %s: Invalid file name\n", filename);
			return (0);
		}
		i++;
	}
	return (1);
}

/**
 * Restores the saved input/output file descriptors for a command
 *
 * @param cmd_list Pointer to the command structure containing
 * saved file descriptors
 * 
 * @details
 * This function restores the original file descriptors by:
 * - Closing saved input FD if it's greater than 2 (not stdin/stdout/stderr)
 * - Closing saved output FD if it's greater than 2
 * - Resetting the saved FDs to -1 after closing
 * 
 * @note Prints error message to stderr if close() fails
 * @return None
 */
void	restore_redirections(t_command *cmd_list)
{
	if (!cmd_list)
		return ;
	if (cmd_list->saved_input > 2)
	{
		if (close(cmd_list->saved_input) == -1)
			perror("close error on saved input");
		cmd_list->saved_input = -1;
	}
	if (cmd_list->saved_output > 2)
	{
		if (close(cmd_list->saved_output) == -1)
			perror("close error on saved output");
		cmd_list->saved_output = -1;
	}
}
