/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:36:39 by cmegret           #+#    #+#             */
/*   Updated: 2024/09/22 17:31:47 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/Minishell.h"

/**
 * @brief Colors a given message with the specified ANSI color code.
 *
 * This function takes a message and a color code as input,
 * and returns the message wrapped with the ANSI color code.
 *
 * @param message The message to be colored.
 * @param color The ANSI color code to apply to the message.
 * @return A new string with the colored message.
 */
static char	*ft_colorize_message(char *message, char *color)
{
	char	*colored_message;
	char	*temp;

	temp = ft_strjoin(color, message);
	colored_message = ft_strjoin(temp, "\033[0m");
	free(temp);
	return (colored_message);
}

/**
 * @brief Creates a colored prompt message for the shell.
 *
 * This function constructs a prompt message by combining
 * various parts of the prompt, each colored differently using ANSI color codes.
 * The prompt includes an arrow, the current directory, and the shell name
 * "Minishell".
 *
 * @param last_folder The name of the last folder in the current
 * working directory.
 * @return A new string with the complete colored prompt message.
 */
static char	*ft_create_message_prompt(char *last_folder)
{
	char	*message;

	message = ft_strjoin(ft_colorize_message("➜  ", "\033[32m"),
			ft_colorize_message(last_folder, "\033[1;36m"));
	message = ft_strjoin(message, ft_colorize_message(" (", "\033[1;34m"));
	message = ft_strjoin(message,
			ft_colorize_message("Minishell", "\033[1;31m"));
	message = ft_strjoin(message, ft_colorize_message(")", "\033[1;34m"));
	message = ft_strjoin(message, ft_colorize_message(" : ", "\033[1;34m"));
	return (message);
}

/**
 * @brief Generates a custom command prompt for the shell.
 *
 * This function creates a command prompt using the last folder
 * of the current working directory (CWD). If the CWD cannot be obtained,
 * it uses a default prompt "Minishell : ".
 *
 * @return A pointer to a string containing the command prompt.
 *         The string must be freed by the caller to avoid memory leaks.
 *
 * @note Uses the getcwd function to obtain the CWD.
 * @note Uses the readline function to read user input.
 * @note On memory allocation error, the function prints an error message and
 *       terminates the program.
 */
char	*ft_prompt(void)
{
	char	*prompt;
	char	*message;
	char	cwd[1024];
	char	*last_folder;

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		last_folder = ft_strrchr(cwd, '/');
		if (last_folder != NULL)
			last_folder++;
		message = ft_create_message_prompt(last_folder);
		if (message == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		prompt = readline(message);
		free(message);
	}
	else
	{
		perror("getcwd");
		prompt = readline("Minishell : ");
	}
	return (prompt);
}

/**
 * @brief Prints an error message and exits the program.
 *
 * This function prints the provided error message using perror and then
 * exits the program with a failure status.
 *
 * @param message A pointer to a string containing the
 * error message to be printed.
 *
 * @note The function uses perror to print the error message, which includes
 *       the string pointed to by message followed by a description of the
 *       current error condition.
 * @note The function then calls exit with EXIT_FAILURE to terminate the program.
 */
void	error_and_exit(const char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}
