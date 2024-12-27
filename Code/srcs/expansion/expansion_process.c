/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:41:45 by cmegret           #+#    #+#             */
/*   Updated: 2024/12/24 10:38:23 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/Minishell.h"

/**
 * Processes a single argument string for variable expansion
 *
 * @param str          The input string to process
 * @param to_expand    Linked list of expansion points indicating where variables
 *                     should be expanded
 * @param shell_state  Current shell state containing environment variables
 *
 * @details
 * Iterates through the input string character by character:
 * 1. When '$' is encountered and expansion is marked:
 *    - Extracts variable name
 *    - Expands variable using shell state
 *    - Appends expanded value to result
 * 2. For non-expansion characters:
 *    - Copies them directly to output
 *
 * @return Newly allocated string with variables expanded
 *         Returns empty string if input is NULL
 *         Caller must free the returned string
 */
char	*process_single_arg(char *str, t_expand *to_expand, t_shell_state *shell_state)
{
	char	*new_arg;
	char	var_name[256];
	int		i;
	int		k;

	new_arg = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && to_expand)
		{
			if (to_expand->check)
			{
				k = 0;
				i++;  // Skip '$' directement
				if (to_expand->size_to_expand >= 1 && str[i])
				{
					while (k < to_expand->size_to_expand - 1 && str[i])
						var_name[k++] = str[i++];
					var_name[k] = '\0';
					new_arg = expand_variable(new_arg, shell_state, var_name);
					i--;  // Ajustement pour le i++ de la boucle principale
				}
				else
				{
					if (!str[i - 1])  // Si c'était le dernier caractère
						new_arg = append_single_char(new_arg, '$');
					else
						i--;  // Retour sur '$'
				}
			}
			else
				new_arg = append_single_char(new_arg, str[i]);
			to_expand = to_expand->next;
		}
		else
			new_arg = append_single_char(new_arg, str[i]);
		i++;
	}
	return (new_arg);
}

/**
 * @brief Processes a heredoc line for variable expansion
 *
 * Scans the input line for variables (starting with $) and expands them
 * using values from the shell state. Non-variable content is copied
 * directly to the output.
 *
 * @param line Input line from heredoc
 * @param shell_state Current shell state with environment variables
 * @return New string with all variables expanded
 */
char	*process_heredoc_line(char *line, t_shell_state *shell_state)
{
	char	*new_line;
	char	var_name[256];
	char	tmp[2];
	int		j;

	new_line = ft_strdup("");
	j = 0;
	while (line[j])
	{
		if (line[j] == '$')
		{
			extract_var_name(line, &j, var_name);
			new_line = expand_variable(new_line, shell_state, var_name);
		}
		else
		{
			tmp[0] = line[j];
			tmp[1] = '\0';
			new_line = ft_strjoin_free(new_line, tmp);
		}
		j++;
	}
	return (new_line);
}
