# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 11:20:33 by otait-ta          #+#    #+#              #
#    Updated: 2022/12/05 10:04:01 by otait-ta         ###   ########.fr        #
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
			./doubly_lst_helpers/d_lstadd_back.c ./doubly_lst_helpers/d_lstnew.c\
			./stack_helpers/initialize_stack.c ./stack_helpers/op_ra.c ./stack_helpers/op_rra.c ./stack_helpers/op_pb.c \
			./stack_helpers/put_in_correct_position.c \
			./string_helpers/inputChecker.c \
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