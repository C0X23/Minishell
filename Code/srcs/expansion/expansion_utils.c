/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:41:42 by cmegret           #+#    #+#             */
/*   Updated: 2024/12/18 12:51:21 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/Minishell.h"

/**
 * @brief Joins two strings and frees the first one
 *
 * Concatenates s1 and s2 into a new string, then frees s1.
 * Similar to ft_strjoin but with automatic memory management for s1.
 *
 * @param s1 First string (will be freed)
 * @param s2 Second string
 * @return New concatenated string or NULL if allocation fails
 */
char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, len1 + 1);
	ft_strlcat(result, s2, len1 + len2 + 1);
	free(s1);
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
 * @brief Appends a single character to an existing string
 *
 * @param str Original string (will be freed)
 * @param c Character to append
 * @return New string with character appended
 */
char	*append_single_char(char *str, char c)
{
	char	tmp[2];

	tmp[0] = c;
	tmp[1] = '\0';
	return (ft_strjoin_free(str, tmp));
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
