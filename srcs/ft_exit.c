/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:19:43 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/06/26 17:52:46 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	printexit(t_shell *shell)
{
	if (shell->cmdgrpcount == 1)
		ft_putendl_fd("exit", 2);
}

void	ft_exit(t_shell *shell, t_cmdgroup *cmd, t_token *tkn, int opt)
{
	int	exitstatus;

	if (opt == 1)
	{
		printexit(shell);
		printerror(shell, "Numeric argument required but exiting still\n", 1);
		clearmemory(shell, cmd);
		exit(255);
	}
	else if (opt == 2)
	{
		exitstatus = ft_atoi(tkn->str);
		ft_putnbr_fd(exitstatus, 2);
		printexit(shell);
		clearmemory(shell, cmd);
		exit(exitstatus % 256);
	}
	else if (opt == 3)
	{
		printexit(shell);
		clearmemory(shell, cmd);
		exit(0);
	}
}

int	exe_exit(t_shell *shell, t_cmdgroup *cmd, t_token *token)
{
	t_token	*tokens;

	tokens = token->next;
	if (tokens != NULL && tokens->next != NULL)
	{
		if (ft_strisnum(tokens->str, 1) == 0)
			ft_exit(shell, cmd, tokens, 1);
		else
			printerror(shell, "Error: Too many arguments\n", SYNTAXERROR);
	}
	else if (tokens != NULL)
	{
		free2d(shell->sh_env);
		if (ft_strisnum(tokens->str, 1) == 0)
			ft_exit(shell, cmd, tokens, 1);
		else
			ft_exit(shell, cmd, tokens, 2);
	}
	else
	{
		free2d(shell->sh_env);
		ft_exit(shell, cmd, tokens, 3);
	}
	return (0);
}
