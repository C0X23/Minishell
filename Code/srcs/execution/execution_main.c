/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:37:18 by francis           #+#    #+#             */
/*   Updated: 2025/01/03 08:10:30 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/Minishell.h"

/**
 * @brief Handles the parent process after a fork.
 *
 * This function closes the write end of the pipe,
 * closes the input file descriptor if it is not 0,
 * and waits for the child process to finish.
 *
 * @param pid The PID of the child process.
 * @param in_fd The input file descriptor.
 * @param fd The array of file descriptors for the pipe.
 */
void	handle_parent(int in_fd, int *fd)
{
	if (fd[1] != -1)
	{
		if (close(fd[1]) == -1)
			perror("close fd[1]");
	}
	if (in_fd != 0)
	{
		if (close(in_fd) == -1)
			perror("close in_fd");
	}
}

/**
 * @brief Sets up file descriptors for input and output redirection.
 *
 * This function redirects the input file descriptor to STDIN and the output
 * file descriptor to STDOUT if necessary. It also closes unused
 * file descriptors.
 *
 * @param cmd_list The list of commands to execute.
 * @param in_fd The input file descriptor.
 * @param fd The array of file descriptors for the pipe.
 */
void	setup_file_descriptors(t_command *cmd_list, int in_fd, int *fd)
{
	if (in_fd != 0)
	{
		if (dup2(in_fd, STDIN_FILENO) == -1)
			error_and_exit("dup2 failed", 1);
		close(in_fd);
	}
	if (cmd_list->next)
	{
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			error_and_exit("dup2 failed", 1);
		close(fd[1]);
	}
	if (fd[0] != -1)
		close(fd[0]);
}

/**
* @brief Runs the specified command.
*
* This function checks if the command is a builtin command and executes it.
* If it is not a builtin command, it handles the child process execution.
*
* @param cmd_list The list of commands to execute.
* @param shell_state The current state of the shell.
*/
void	run_command(t_command *cmd_list, t_shell_state *shell_state)
{
	if (cmd_list->cmd_name != NULL || ft_strlen(cmd_list->cmd_name) != 0)
	{
		if (ft_is_builtin(cmd_list->cmd_name) == 0)
			ft_execute_builtin(cmd_list, shell_state);
		else
			handle_child_process(cmd_list, shell_state);
	}
}

/**
 * @brief Executes a command in a child process with proper I/O handling
 *
 * This function handles the execution of a command in a child process by:
 * 1. Setting up file descriptors for input/output
 * 2. Managing heredoc input if present
 * 3. Configuring input/output redirections
 * 4. Executing the command
 * 5. Cleaning up and restoring file descriptors
 *
 * @param cmd_list Pointer to the command structure to execute
 * @param shell_state Current state of the shell environment
 * @param in_fd Input file descriptor for the command
 * @param fd Pipe file descriptors array for pipeline communication
 */
void	execute_child(t_command *cmd_list,
	t_shell_state *shell_state, int in_fd, int *fd)
{
	extern int	rl_done;

	setup_file_descriptors(cmd_list, in_fd, fd);
	shell_state->last_exit_status = 0;
	if (handle_heredoc(cmd_list))
	{
		shell_state->last_exit_status = 1;
		rl_done = 1;
		exit(shell_state->last_exit_status);
	}
	configure_redirections(cmd_list, shell_state);
	if (shell_state->last_exit_status != 0)
	{
		restore_redirections(cmd_list);
		rl_done = 1;
		exit(shell_state->last_exit_status);
	}
	run_command(cmd_list, shell_state);
	restore_redirections(cmd_list);
	rl_done = 1;
	exit(shell_state->last_exit_status);
}

/**
 * @brief Executes a list of commands in a pipeline
 *
 * This function:
 * 1. Handles special case of parent builtin commands
 * 2. Creates pipeline for multiple commands
 * 3. Tracks child processes with PID array
 * 4. Waits for all processes to complete
 *
 * @param cmd_list The list of commands to execute
 * @param shell_state The current state of the shell
 * @return 0 on success, appropriate error code on failure
 */
int	execute_cmd(t_command *cmd_list, t_shell_state *shell_state)
{
	int		in_fd;
	pid_t	pipeline_pids[1024];
	int		pid_count;

	in_fd = 0;
	pid_count = 0;
	while (cmd_list)
	{
		if (cmd_list->skip_execution)
		{
			shell_state->last_exit_status = 1;
			cmd_list = cmd_list->next;
			continue ;
		}
		if (handle_parent_builtin(cmd_list, shell_state) == 0)
			return (0);
		pipeline_pids[pid_count] = execute_pipeline(cmd_list,
				shell_state, in_fd, &in_fd);
		if (pipeline_pids[pid_count] > 0)
			pid_count++;
		cmd_list = cmd_list->next;
	}
	wait_for_pipeline(pipeline_pids, pid_count, shell_state);
	return (0);
}
