/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:47:53 by mde-figu          #+#    #+#             */
/*   Updated: 2021/12/12 17:47:54 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	interrupt(int signal)
{
	errno = 128 + signal;
	ft_printf("\n");
}

void	prompt_handler(int signal)
{
	if (isatty(STDIN))
	{
		errno = 128 + signal;
		ft_printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	define_signals(void)
{
	signal(SIGINT, prompt_handler);
	signal(SIGQUIT, SIG_IGN);
}

static void	exec_handler(int signal)
{
	if (signal == SIGINT)
	{
		errno = 130;
		ft_printf("\n");
	}
	if (signal == SIGQUIT)
	{
		errno = 131;
		ft_putendl_fd("Quit (core dumped)", 2);
	}
}

void	define_signals_exec(void)
{
	signal(SIGINT, exec_handler);
	signal(SIGQUIT, exec_handler);
}
