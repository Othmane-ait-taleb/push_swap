/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:24:35 by otait-ta          #+#    #+#             */
/*   Updated: 2022/12/17 13:08:12 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int			input_checker(int argc, char const *argv[], t_list **stack_a,
				t_list **tmp);
long long	ft_atol(const char *str);
t_list		*d_lstnew(void *content);
void		initialize_stack(t_list **head, char const *argv[]);
void		d_lstadd_back(t_list **lst, t_list *new);
t_list		*op_ra(t_list **stack);
t_list		*op_rb(t_list **stack);
void		op_rr(t_list **stack_a, t_list **stack_b);
t_list		*op_rra(t_list **stack);
t_list		*op_rrb(t_list **stack);
void		op_rrr(t_list **stack_a, t_list **stack_b);
t_list		*op_pb(t_list **stack_a, t_list **stack_b);
t_list		*op_pa(t_list **stack_a, t_list **stack_b);
t_list		*op_sa(t_list **stack_a);
t_list		*op_sb(t_list **stack_b);
void		op_ss(t_list **stack_a, t_list **stack_b);

int			**lis(t_list *list);
void		filter_lis(int **array_and_size, t_list **stack_a, t_list **stack_b,
				t_list **op_list);
int			**put_in_correct_position(t_list **stack_a, int size_a,
				t_list **stack_b, int size_b);
int			*list_to_array(t_list *list, int size);
int			max_of_array(int *array_a, int size_a);
int			min_of_array(int *array_a, int size_a);
int			min(int a, int b);
int			max(int a, int b);
void		apply_moves(int **pos_tab, t_list **stack_a, t_list **stack_b,
				t_list **op_list);
int			*min_moves(int **tab, int size_b);
int			absolute_value(int a);
void		put_smallest_number_top(t_list **stack, t_list **op_list);
void		reverse_stack(t_list **stack);
void		d_lstadd_front(t_list **lst, t_list *new);
int			is_sorted(t_list *stack);
void		sort_three(t_list **stack_a, t_list **op_list);
void		positive_moves(int *moves, t_list **stack_a, t_list **stack_b,
				t_list **op_list);
void		negative_moves(int *moves, t_list **stack_a, t_list **stack_b,
				t_list **op_list);
void		pr(void *a);
int			check_duplicates(t_list *stack);

char		*get_next_line(int fd);
char		*ft_strchr(const char *s, int c);
size_t		ft_gnl_strlen(const char *s);
char		*ft_gnl_strjoin(char *s1, char *s2);
char		*find_new_line(int fd, char *line);
char		*get_new_line(char *str);
char		*find_rest(char *str);
void		perform_move(t_list **stack_a, t_list **stack_b, int move);

#endif