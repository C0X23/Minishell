/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:41:42 by cmegret           #+#    #+#             */
/*   Updated: 2024/12/24 10:39:44 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/Minishell.h"

/**
 * Joins two strings and frees the first one
 *
 * @param s1 First string to join (will be freed)
 * @param s2 Second string to join
 *
 * @details
 * Special cases:
 * - If s1 is NULL, returns a copy of s2
 * - If s2 is NULL, frees s1 and returns NULL
 * 
 * @note Memory management:
 * - s1 is always freed
 * - Caller must free the returned string
 * - s2 is not freed
 *
 * @return New allocated string containing joined s1+s2,
 * or NULL if allocation fails
 */
char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
	{
		free(s1);
		return (NULL);
	}
	result = ft_strjoin(s1, s2);
	free(s1);
	if (!result)
		return (NULL);
	return (result);
}

/**
 * @brief Extracts variable name from a command argument
 *
 * Handles two cases:
 * 1. Special variable $? -> returns "?"
 * 2. Regular variables -> extracts alphanumeric and underscore chars
 *
 * @param arg Source string containing the variable
 * @param j Current position in arg (will be updated)
 * @param var_name Buffer to store extracted name
 */
void	extract_var_name(char *arg, int *j, char *var_name)
{
	int	k;

	k = 0;
	(*j)++;
	if (arg[*j] == '?')
	{
		var_name[k++] = '?';
		var_name[k] = '\0';
		return ;
	}
	while (arg[*j] && (ft_isalnum(arg[*j]) || arg[*j] == '_'))
		var_name[k++] = arg[(*j)++];
	var_name[k] = '\0';
	(*j)--;
}

/**
 * @brief Converts exit status to string representation
 *
 * @param status Exit status code
 * @return String containing status number or "0" on failure
 */
char	*convert_exit_status(int status)
{
	char	*result;

	result = ft_itoa(status);
	if (!result)
		return (ft_strdup("0"));
	return (result);
}

/**
 * Appends a single character to a string
 *
 * @param str The string to append to (will be freed)
 * @param c   The character to append
 *
 * @details
 * Creates a temporary string from the character and joins it
 * to the input string using ft_strjoin_free
 *
 * @note Memory management:
 * - Input string is freed internally
 * - Returns newly allocated string
 * - Caller must free the returned string
 *
 * @return New string with character appended, or NULL if allocation fails
 */
char	*append_single_char(char *str, char c)
{
	char	tmp[2];
	char	*result;

	tmp[0] = c;
	tmp[1] = '\0';
	result = ft_strjoin_free(str, tmp);
	return (result);
}

/**
 * @brief Handles expansion of shell variables
 *
 * Extracts variable name and performs expansion using shell state
 *
 * @param new_arg Current argument being built
 * @param shell_state Current shell state
 * @param arg_string Source string containing variable
 * @param i Current position in arg_string
 */
char	*handle_variable_expansion(char *new_arg, t_shell_state *shell_state,
	char *arg_string, int *i)
{
	char	var_name[256];

	extract_var_name(arg_string, i, var_name);
	return (expand_variable(new_arg, shell_state, var_name));
}
