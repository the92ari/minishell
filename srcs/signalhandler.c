/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signalhandler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:30:05 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/06/16 13:27:06 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Makes sure that pressing ctrl+c will return back the prompter on a new line
rl_on_new_line() will store everything on the display into the buffer.
rl_redisplay() will display whatever is in the buffer.
rl_replace_line(char *str, int clear_undo) will replace the line (not including
the string passed into readline() function) with str.
*/
void	sigint_handler(int signum)
{
	if (signum == SIGINT)
	{
		rl_on_new_line();
		rl_redisplay();
		ft_putstr_fd("  \n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}