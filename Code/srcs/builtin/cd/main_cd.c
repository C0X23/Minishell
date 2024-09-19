/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:00:25 by cmegret           #+#    #+#             */
/*   Updated: 2024/09/19 11:44:51 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../header/Minishell.h"

// Code to test the function:
// printf("initial path: %s\n", getcwd(NULL, 0));
// printf("path changed to: %s (path: %s)\n", getcwd(NULL, 0), path);
void	ft_cd(struct s_command *cmd, struct s_shell_state *shell_state)
{
	char	*path;

	path = cmd->args[0];
	if (!path || ft_strncmp(path, "~", 2) == 0)
		path = getenv("HOME");
	else if (ft_strncmp(path, "-", 2) == 0)
		path = getenv("OLDPWD");
	if (chdir(path) == -1)
	{
		perror("Error with the cd command");
		return ;
	}
	free(shell_state->current_directory);
	shell_state->current_directory = getcwd(NULL, 0);
	if (!shell_state->current_directory)
		error_and_exit("getcwd failed");
	setenv("OLDPWD", getenv("PWD"), 1); // Change later
	setenv("PWD", shell_state->current_directory, 1); // Change later
}
