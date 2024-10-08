/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:56:57 by cmegret           #+#    #+#             */
/*   Updated: 2024/09/27 14:58:14 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/Minishell.h"

static void	remove_var(char ***envp, int index)
{
	int		i;
	char	**new_envp;

	i = 0;
	while ((*envp)[i] != NULL)
		i++;
	new_envp = (char **)ft_calloc(i, sizeof(char *));
	if (!new_envp)
		error_and_exit("ft_calloc failed");
	i = 0;
	while (i < index)
	{
		new_envp[i] = (*envp)[i];
		i++;
	}
	free((*envp)[index]);
	while ((*envp)[i + 1] != NULL)
	{
		new_envp[i] = (*envp)[i + 1];
		i++;
	}
	free(*envp);
	*envp = new_envp;
}

void	ft_unset(char ***envp, const char *var)
{
	char	*name;
	int		index;

	name = get_var_name(var);
	if (!is_valid_name(name))
	{
		ft_printf("export: '%s': not a valid identifier\n", var);
		free(name);
		return ;
	}
	index = find_var_index(*envp, name, ft_strlen(name));
	if (index != -1)
		remove_var(envp, index);
	free(name);
}
