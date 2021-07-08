/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 17:16:32 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/04 14:06:23 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_cmd_r(char *cmd)
{
	int	flag;

	flag = 0;
	if (ft_strcmp(cmd, "ra") == 0)
		flag = 1;
	else if (ft_strcmp(cmd, "rb") == 0)
		flag = 1;
	else if (ft_strcmp(cmd, "rr") == 0)
		flag = 1;
	else if (ft_strcmp(cmd, "rra") == 0)
		flag = 1;
	else if (ft_strcmp(cmd, "rrb") == 0)
		flag = 1;
	else if (ft_strcmp(cmd, "rrr") == 0)
		flag = 1;
	return (flag);
}

int	ft_check_cmd_sp(char *cmd)
{
	int	flag;

	flag = 0;
	if (ft_strcmp(cmd, "sa") == 0)
		flag = 1;
	else if (ft_strcmp(cmd, "sb") == 0)
		flag = 1;
	else if (ft_strcmp(cmd, "ss") == 0)
		flag = 1;
	else if (ft_strcmp(cmd, "pa") == 0)
		flag = 1;
	else if (ft_strcmp(cmd, "pb") == 0)
		flag = 1;
	else
		flag = ft_check_cmd_r(cmd);
	return (flag);
}

void	ft_process_cmd_sub(char *cmd, t_stack *a, t_stack *b)
{
	if (ft_strcmp(cmd, "pa") == 0)
		ft_process_p(a, b, "pa");
	else if (ft_strcmp(cmd, "pb") == 0)
		ft_process_p(a, b, "pb");
	else if (ft_strcmp(cmd, "ra") == 0)
		ft_process_r(a);
	else if (ft_strcmp(cmd, "rb") == 0)
		ft_process_r(b);
	else if (ft_strcmp(cmd, "rr") == 0)
		ft_process_r_all(a, b);
	else if (ft_strcmp(cmd, "rra") == 0)
		ft_process_rr(a);
	else if (ft_strcmp(cmd, "rrb") == 0)
		ft_process_rr(b);
	else if (ft_strcmp(cmd, "rrr") == 0)
		ft_process_rrr(a, b);
}

void	ft_process_cmd(t_stack *a, t_stack *b)
{
	char	*line;

	line = 0;
	while (get_next_line(STDIN_FILENO, &line))
	{
		if (!ft_check_cmd_sp(line))
		{
			free(line);
			ft_print_error_cmd(a, b);
		}
		if (ft_strcmp(line, "sa") == 0)
			ft_process_s(a);
		else if (ft_strcmp(line, "sb") == 0)
			ft_process_s(b);
		else if (ft_strcmp(line, "ss") == 0)
			ft_process_ss(a, b);
		else
			ft_process_cmd_sub(line, a, b);
		free(line);
	}
	if (line)
		free(line);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	a = ft_init_stack('a');
	ft_set_stack(a, argc, argv);
	ft_check_stack(a);
	b = ft_init_stack('b');
	ft_process_cmd(a, b);
	if (b->size == 0 && ft_check_sort_a(a, a->size))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_free_stack(a);
	ft_free_stack(b);
	return (0);
}
