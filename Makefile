# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 11:20:33 by otait-ta          #+#    #+#              #
#    Updated: 2022/12/17 12:22:45 by otait-ta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
LIB_HEADR	=	./libft/libft.h
PS_HEADR	=	./push_swap.h
AR		=	ar rc
CC		=	CC
FLAGS	= 	-Wall -Werror -Wextra 
RM		=	rm -rf
CHECKER = checker

CFILES	=	./libft/ft_isalpha.c ./libft/ft_isdigit.c ./libft/ft_isalnum.c  ./libft/ft_strlen.c  \
	   		./libft/ft_atoi.c ./libft/ft_strdup.c ./libft/ft_split.c \
	   		./libft/ft_putchar_fd.c ./libft/ft_putstr_fd.c ./libft/ft_strtrim.c ./libft/ft_substr.c\
	   		 ./libft/ft_itoa.c ./libft/ft_strchr.c ./libft/ft_strlcpy.c ./libft/ft_strcmp.c\
			./doubly_lst_helpers/d_lstadd_back.c ./doubly_lst_helpers/d_lstnew.c ./doubly_lst_helpers/d_lstadd_front.c\
			./doubly_lst_helpers/ft_lstclear.c ./doubly_lst_helpers/ft_lstiter.c ./doubly_lst_helpers/ft_lstlast.c \
			./doubly_lst_helpers/ft_lstsize.c \
			./stack_helpers/initialize_stack.c ./stack_helpers/op_ra.c ./stack_helpers/op_rra.c ./stack_helpers/op_pb.c \
			./stack_helpers/op_rb.c ./stack_helpers/op_rrb.c ./stack_helpers/op_pa.c ./stack_helpers/op_rr.c ./stack_helpers/op_rrr.c \
			./stack_helpers/op_sa.c  ./stack_helpers/op_sb.c ./stack_helpers/op_ss.c\
			./stack_helpers/put_in_correct_position.c  ./stack_helpers/list_to_array.c ./stack_helpers/max_of_array.c \
			./stack_helpers/apply_moves.c ./stack_helpers/positive_moves.c ./stack_helpers/negative_moves.c ./stack_helpers/min_moves.c \
			./stack_helpers/is_sorted.c\
			./stack_helpers/min_of_array.c \
			./string_helpers/inputChecker.c ./string_helpers/min_max.c ./string_helpers/absolute_value.c  string_helpers/ft_atol.c\
			./string_helpers/myprint.c ./string_helpers/check_duplicates.c\
			
MANDA   =	./LIS/lis.c ./LIS/filter_lis.c \
			./sort_three/sort_three.c \
			./main.c \

BONUS_CFILES  =   ./bonus/checker.c ./bonus/get_next_line.c ./bonus/get_next_line_utils.c ./bonus/perform_move.c \

OBJ = $(CFILES:.c=.o)
MANDA_OBJ = $(MANDA:.c=.o)
BONUS_OBJS = $(BONUS_CFILES:.c=.o)

all: $(NAME)

bonus : $(OBJ) ${PS_HEADR} ${LIB_HEADR} ${BONUS_OBJS}
	$(CC) $(FLAGS) $(BONUS_OBJS) $(OBJ) -o $(CHECKER)

$(NAME): $(OBJ) ${PS_HEADR} ${LIB_HEADR} ${MANDA_OBJ}
	$(CC) $(FLAGS) $(OBJ) ${MANDA_OBJ} -o $(NAME)

%.o: %.c $(LIB_HEADR) $(PS_HEADR)
	$(CC) $(FLAGS) -c $< -o $@

clean: 
		$(RM) $(OBJ) $(BONUS_OBJS)

fclean: clean
		$(RM) $(NAME) $(CHECKER)

re:	fclean all

.PHONY: all bonus clean fclean re