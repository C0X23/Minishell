/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:40:16 by cmegret           #+#    #+#             */
/*   Updated: 2024/12/18 13:02:51 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/Minishell.h"

/**
 * @brief Retrieves the value of an environment variable.
 *
 * This function searches for an environment variable in the environment
 * variables array and returns its value.
 *
 * @param envp The environment variables array.
 * @param key The key of the variable to find.
 * @return The value of the variable, or NULL if not found.
 */
char	*get_env_var(char **envp, char *key)
{
	size_t	key_len;
	int		index;

	key_len = ft_strlen(key);
	index = find_var_index(envp, key, key_len);
	if (index != -1)
		return (envp[index] + key_len + 1);
	return (NULL);
}

/**
 * @brief Updates an existing environment variable with a new value.
 *
 * This function updates the value of an existing environment variable.
 * If the variable does not exist, it adds a new variable.
 *
 * @param envp The environment variables array (triple pointer)
 * @param name The name of the variable to update
 * @param value The new value of the variable
 * @note The function handles memory allocation and frees old value
 */
void	update_env_var(char ***envp, char *name, const char *value)
{
	int		index;
	char	*new_var;
	size_t	name_len;

	name_len = ft_strlen(name);
	index = find_var_index(*envp, name, name_len);
	new_var = build_new_var(name, value);
	if (index != -1)
	{
		free((*envp)[index]);
		(*envp)[index] = new_var;
	}
	else
		add_new_var(envp, new_var);
}
