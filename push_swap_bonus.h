/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:34:16 by aelsayed          #+#    #+#             */
/*   Updated: 2025/01/30 18:50:45 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "./LIBFT/libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

typedef struct s_arr
{
	int				*arr;
	int				size;
	int				i;

}					t_arr;

typedef struct s_sort5
{
	int				a;
	int				b;
	int				c;
}					t_sort;

typedef struct s_var
{
	int				start;
	int				end;
	int				i;
}					t_var;

// libft functions
t_stack				*ft_new(int content);
void				ft_addback(t_stack **lst, t_stack *new);
void				ft_addfront(t_stack **lst, t_stack *new);
void				ft_clear(t_stack **lst);
t_stack				*ft_last(t_stack *lst);
int					ft_size(t_stack *lst);
int					ft_lstatoi(char const *str, t_stack **lst, char **s);

// Push_Swap operations
void				sa_sb(t_stack **a, int c);
void				ss(t_stack **a, t_stack **b, int c);
void				pa_pb(t_stack **b, t_stack **a, int c);
void				ra_rb(t_stack **a, int c);
void				rr(t_stack **a, t_stack **b);
void				rra_rrb(t_stack **a, int c);
void				rrr(t_stack **a, t_stack **b);

// checker functions
void				ft_isrepeat(t_stack *head);
int					ft_parsing(char **av, int ac, t_stack **head);
void				fill_split(char *s, t_stack **lst);
int					ft_onlydigit(char *str);

// push_swap functions
void				arr_alloc(t_arr *arr, t_stack *a);
void				push_swap_min(t_stack **a, t_stack **b, t_arr arr);
void				push_swap_max(t_stack **a, t_stack **b, t_arr arr);
#endif