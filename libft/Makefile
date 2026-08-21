# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 19:51:11 by mmiguelo          #+#    #+#              #
#    Updated: 2024/10/15 19:51:11 by mmiguelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                    NAMES                                     #
#==============================================================================#

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

#==============================================================================#
#                                    FILES                                     #
#==============================================================================#

SRCS =	ft_bzero.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
 		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

OBJ = $(SRCS:.c=.o)

TOTAL = $(words $(OBJ))
CURRENT = 0


#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval CURRENT=$(shell expr $(CURRENT) + 1))
	@$(eval PERCENT=$(shell expr $(CURRENT) \* 100 / $(TOTAL)))
	@printf "\r\033[K["
	@i=0; while [ $$i -lt $(shell expr $(PERCENT) / 2) ]; do printf "█"; i=$$((i + 1)); done
	@i=$(shell expr $(PERCENT) / 2); while [ $$i -lt 50 ]; do printf "░"; i=$$((i + 1)); done
	@if [ $(PERCENT) -eq 100 ]; then printf "] 100%%\n"; else printf "] %3d%%" $(PERCENT); fi

clean:
		$(RM) $(OBJ) $(BONUS_OBJ)

fclean:
	@printf $(BRED)"Cleaning libft\n"$(RST)
	@i=0; \
	while [ $$i -le 50 ]; do \
		printf "\r\033[K["; \
		j=0; \
		while [ $$j -lt $$i ]; do \
			printf "█"; \
			j=$$((j + 1)); \
		done; \
		while [ $$j -lt 50 ]; do \
			printf "░"; \
			j=$$((j + 1)); \
		done; \
		printf "] %3d%%" $$((i * 2)); \
		sleep 0.02; \
		i=$$((i + 1)); \
	done
	@printf "\n"
	@$(RM) $(OBJ) $(BONUS_OBJ) $(NAME)

re: clean all

PHONY: all clean fclean re


#colors
BRED 	= "\033[31;1m"
RST 	= "\033[0m"