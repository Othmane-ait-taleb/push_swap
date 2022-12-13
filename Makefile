# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 11:20:33 by otait-ta          #+#    #+#              #
#    Updated: 2022/12/13 12:36:30 by otait-ta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
LIB_HEADR	=	./libft/libft.h
PS_HEADR	=	./push_swap.h
AR		=	ar rc
CC		=	CC
FLAGS	= 	-Wall -Werror -Wextra 
RM		=	rm -rf

CFILES	=	./libft/ft_isalpha.c ./libft/ft_isdigit.c ./libft/ft_isalnum.c ./libft/ft_isascii.c ./libft/ft_strlen.c ./libft/ft_toupper.c ./libft/ft_tolower.c \
			./libft/ft_strchr.c ./libft/ft_strrchr.c ./libft/ft_strncmp.c \
	   		./libft/ft_strnstr.c ./libft/ft_strlcpy.c ./libft/ft_strlcat.c ./libft/ft_atoi.c ./libft/ft_strdup.c \
	   		./libft/ft_putchar_fd.c ./libft/ft_putstr_fd.c ./libft/ft_putendl_fd.c ./libft/ft_isprint.c \
	   		./libft/ft_substr.c ./libft/ft_strjoin.c ./libft/ft_split.c ./libft/ft_itoa.c ./libft/ft_strmapi.c \
	   		./libft/ft_putnbr_fd.c ./libft/ft_strtrim.c ./libft/ft_memcpy.c ./libft/ft_memmove.c ./libft/ft_memset.c \
	   		./libft/ft_memcmp.c ./libft/ft_memchr.c ./libft/ft_bzero.c ./libft/ft_calloc.c ./libft/ft_striteri.c\
			./doubly_lst_helpers/d_lstadd_back.c ./doubly_lst_helpers/d_lstnew.c ./doubly_lst_helpers/d_lstadd_front.c\
			./stack_helpers/initialize_stack.c ./stack_helpers/op_ra.c ./stack_helpers/op_rra.c ./stack_helpers/op_pb.c \
			./stack_helpers/op_rb.c ./stack_helpers/op_rrb.c ./stack_helpers/op_pa.c ./stack_helpers/op_rr.c ./stack_helpers/op_rrr.c \
			./stack_helpers/put_in_correct_position.c  ./stack_helpers/list_to_array.c ./stack_helpers/max_of_array.c \
			./stack_helpers/apply_moves.c  ./stack_helpers/min_moves.c  ./stack_helpers/initialize_stack_reverse.c\
			./stack_helpers/put_smallest_number_top.c ./stack_helpers/reverse_stack.c ./stack_helpers/is_sorted.c\
			./string_helpers/inputChecker.c ./string_helpers/min_max.c ./string_helpers/absolute_value.c \
			./LIS/lis.c ./LIS/filter_lis.c \

BONUS_CFILES  = ./libft/ft_lstnew.c ./libft/ft_lstadd_front.c  ./libft/ft_lstsize.c ./libft/ft_lstlast.c \
	   			./libft/ft_lstclear.c ./libft/ft_lstiter.c ./libft/ft_lstmap.c ./libft/ft_lstadd_back.c ./libft/ft_lstdelone.c \

OBJ = $(CFILES:.c=.o)

BONUS_OBJS = $(BONUS_CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)

%.o: %.c $(LIB_HEADR) $(PS_HEADR)
	$(CC) $(FLAGS) -c $< -o $@

clean: 
		$(RM) $(OBJ) $(BONUS_OBJS)

fclean: clean
		$(RM) $(NAME)

re:	fclean all

bonus: $(BONUS_OBJS)
		$(AR) $(NAME) $(BONUS_OBJS)

.PHONY: all bonus clean fclean re