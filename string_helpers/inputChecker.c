/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputChecker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:22:30 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/17 12:14:10 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_space(char *string)
{
	int	i;

	i = 0;
	if (string[0] == '\0')
		return (1);
	while (string[i])
	{
		if (string[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

char	*my_join(char *s1, char *s2, int ifree)
{
	size_t	len;
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1)
		s1 = ft_strdup("");
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (s1[k])
		str[i++] = s1[k++];
	k = 0;
	while (s2[k])
		str[i++] = s2[k++];
	str[i] = '\0';
	if (ifree == 0)
		free(s1);
	return (str);
}

char	*to_one_arg(int ac, char **av)
{
	int		i;
	char	*full_arg;
	char	*tmp_char;

	i = 1;
	full_arg = NULL;
	while (i < ac)
	{
		if (check_space(av[i]))
			ft_putstr_fd("Error", 2);
		tmp_char = my_join(av[i], " ", 1);
		full_arg = my_join(full_arg, tmp_char, 0);
		free(tmp_char);
		i++;
	}
	return (full_arg);
}

void	free_2d(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i++]);
	}
	free(array);
}

int	input_checker(int argc, char const *argv[], t_list **stack_a, t_list **tmp)
{
	int		i;
	int		j;
	char	*all_arg;
	char	**splited;

	all_arg = to_one_arg(argc, (char **)argv);
	splited = ft_split(all_arg, ' ');
	i = 0;
	while (splited[i])
	{
		j = 0;
		while (splited[i][j] != '\0')
		{
			if (((splited[i][j] == '-' || splited[i][j] == '+') && j == 0) ||
				ft_isdigit(splited[i][j]) == 1)
				j++;
			else
				return (0);
		}
		if (ft_atol(splited[i]) > INT_MAX || ft_atol(splited[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (initialize_stack(stack_a, (const char **)splited), initialize_stack(
			tmp, (const char **)splited), free_2d(splited), free(all_arg), 1);
}
