/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 01:13:50 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/06/07 16:12:10 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export(t_shell *shell, char *arg)
{
	char	**new_env;
	int		valid;
	int		count;
	int		i;

	valid = ft_strchri(arg, 0, '=');
	if (valid < -1)
		return ;
	if (valid == 0)
	{
		printerror(shell, "Error. Argument is not a valid indentifier\n", 1);
		return ;
	}
	count = ft_2darrlen(shell->sh_env);
	new_env = malloc(sizeof(char *) * (count + 2));
	i = 0;
	while (i < count)
	{
		new_env[i] = ft_strdup(shell->sh_env[i]);
		i++;
	}
	new_env[i] = ft_strdup(arg);
	new_env[++i] = NULL;
	free2d(shell->sh_env);
	shell->sh_env = new_env;
}
