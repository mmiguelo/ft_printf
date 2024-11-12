# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 18:31:55 by mmiguelo          #+#    #+#              #
#    Updated: 2024/11/08 15:03:47 by mmiguelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#==============================================================================#
#                                    NAMES                                     #
#==============================================================================#

NAME = libftprintf.a
CC = cc
CFLAGS = -Werror -Wall -Wextra -g
RM = rm -f


#==============================================================================#
#                                    FILES                                     #
#==============================================================================#

SRCS = ft_printf.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putnbr.c \
	ft_puthex.c \
	ft_putptr.c \
	ft_pututoa.c


OBJ = $(SRCS:.c=.o)

LIBFT_DIR 	= ./libft
LIBFT		= ./libft/libft.a


#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@echo "Compiling $(NAME)"
	@cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)
	
$(LIBFT): $(LIBFT_DIR)
	@echo "Compiling libft"
	@$(MAKE) -C $(LIBFT_DIR)
	
%.o: $(SRC)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $<"

clean:
		@$(MAKE) clean -C $(LIBFT_DIR)
		$(RM) $(OBJ)

fclean: clean
		@$(MAKE) fclean -C $(LIBFT_DIR)
		$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
