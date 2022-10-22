# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znichola <znichola@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 08:55:24 by znichola          #+#    #+#              #
#    Updated: 2022/10/22 21:59:47 by znichola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# the name of the NAME program
NAME	= libftprintf.a

PART_1	=	itoa_base         p_flags           p_formatted_chunk \
			p_precision       p_specifier       p_str_chunk       \
			p_utils           p_w_char          p_w_int           \
			p_w_ptr           p_w_str           p_w_uin           \
			p_width           p_write_cnv       p_wwrite          \
			p_xfix            printf

SRC		+=	$(addsuffix .c, $(addprefix ft_, $(PART_1)))
OBJ		=	$(SRC:.c=.o)


# # then you can use it as a dependency just like locally built targets
# my-prog: some.o local.o dependencies.o libft/libft.a

# special include directories
INCLUDE = .

# select the compiler and flags
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LIB		= ar rs
RM		= rm -f

# specify how to compile the .c files
.c.o :
		$(CC) $(CFLAGS) -I${INCLUDE} -c $< -o $(@)

# if you type 'make' without arguments, this is the default
all : $(NAME)

# specify how to compile the NAME
$(NAME): $(OBJ)
		${LIB} $(NAME) ${OBJ}

# # specify how to compile the NAME
# $(NAME): $(OBJ) libft/libft.a
# 		${LIB} libftprintf.a ${OBJ}

bonus : $(NAME)

# remove binaries
clean :
		${RM} $(OBJ)

# # remove binaries and other junk
fclean : clean
		${RM} ${NAME}

re : fclean all

# libft/libft.a:
# 	$(MAKE) -C libft/ libft.a
# 	mv libft/libft.a libftprintf.a

.PHONY: $(NAME) all re clean fclean bonus
