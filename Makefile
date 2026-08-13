#		   ________________________________________________        
#  _______|                                               |_______
# \       |             		  NAMES      	          |      /
#  \      |                                               |     /
#  /      |_______________________________________________|     \ 
# /__________)                                        (__________\ 


NAME = libftprintf.a
CC = cc
CFLAGS = -Werror -Wall -Wextra -g
RM = rm -f
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -Imandatory -Ibonus -I.
VAL = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --errors-for-leak-kinds=definite


#		   ________________________________________________
#  _______|                                               |_______
# \       |                SOURCE FILES                   |      /
#  \      |                                               |     /
#  /      |_______________________________________________|     \ 
# /__________)                                        (__________\ 


MANDATORY = ft_printf.c
MANDATORY += ft_putchar.c
MANDATORY += ft_putstr.c
MANDATORY += ft_putnbr.c
MANDATORY += ft_puthex.c
MANDATORY += ft_putptr.c
MANDATORY += ft_pututoa.c

BONUS = bonus.c

SRC = $(MANDATORY)
SRC_BONUS = $(BONUS)

#		   ________________________________________________
#  _______|                                               |_______
# \       |                     PATHS                     |      /
#  \      |                                               |     /
#  /      |_______________________________________________|     \ 
# /__________)                                        (__________\ 


VPATH = mandatory bonus

OBJ_DIR = obj
OBJS = $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS = $(SRC_BONUS:%.c=$(OBJ_DIR)/%.o)
DEPS = $(OBJS:.o=.d) $(OBJS_BONUS:.o=.d)

#          ________________________________________________
# ________|                                               |_______
# \       |                  BUILD RULES                  |      /
#  \      |                                               |     /
#  /      |_______________________________________________|     \ 
# /__________)                                        (__________\ 


all: $(NAME) 

$(LIBFT):
	@echo $(BRED)"Compiling libft"$(RST)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)
	@echo $(BGRN)"✨Libft compilation completed✨"$(RST)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ $(INCLUDES)

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\n"
	@echo " ███████████ ███████████                 ███████████  ███████████   █████ ██████   █████ ███████████ ███████████"
	@echo "▒▒███▒▒▒▒▒▒█▒█▒▒▒███▒▒▒█                ▒▒███▒▒▒▒▒███▒▒███▒▒▒▒▒███ ▒▒███ ▒▒██████ ▒▒███ ▒█▒▒▒███▒▒▒█▒▒███▒▒▒▒▒▒█"
	@echo " ▒███   █ ▒ ▒   ▒███  ▒                  ▒███    ▒███ ▒███    ▒███  ▒███  ▒███▒███ ▒███ ▒   ▒███  ▒  ▒███   █ ▒ "
	@echo " ▒███████       ▒███                     ▒██████████  ▒██████████   ▒███  ▒███▒▒███▒███     ▒███     ▒███████   "
	@echo " ▒███▒▒▒█       ▒███                     ▒███▒▒▒▒▒▒   ▒███▒▒▒▒▒███  ▒███  ▒███ ▒▒██████     ▒███     ▒███▒▒▒█   "
	@echo " ▒███  ▒        ▒███                     ▒███         ▒███    ▒███  ▒███  ▒███  ▒▒█████     ▒███     ▒███  ▒    "
	@echo " █████          █████       █████████    █████        █████   █████ █████ █████  ▒▒█████    █████    █████      "
	@echo "▒▒▒▒▒          ▒▒▒▒▒       ▒▒▒▒▒▒▒▒▒    ▒▒▒▒▒        ▒▒▒▒▒   ▒▒▒▒▒ ▒▒▒▒▒ ▒▒▒▒▒    ▒▒▒▒▒    ▒▒▒▒▒    ▒▒▒▒▒       "
	@echo "\n"
	@echo $(BGRN)"✨Compilation of $(NAME) completed✨"$(RST)                                                                                                                
	@echo $(BYEL)"This project was created by mmiguelo!"$(RST)                                                                                                  
                                                                                                                
val: all
	@$(VAL) ./$(NAME)

bonus: $(NAME) $(LIBFT) $(OBJS_BONUS)
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS_BONUS)
	@ranlib $(NAME)
	@echo " ███████████ ███████████                 ███████████  ███████████   █████ ██████   █████ ███████████ ███████████"
	@echo "▒▒███▒▒▒▒▒▒█▒█▒▒▒███▒▒▒█                ▒▒███▒▒▒▒▒███▒▒███▒▒▒▒▒███ ▒▒███ ▒▒██████ ▒▒███ ▒█▒▒▒███▒▒▒█▒▒███▒▒▒▒▒▒█"
	@echo " ▒███   █ ▒ ▒   ▒███  ▒                  ▒███    ▒███ ▒███    ▒███  ▒███  ▒███▒███ ▒███ ▒   ▒███  ▒  ▒███   █ ▒ "
	@echo " ▒███████       ▒███                     ▒██████████  ▒██████████   ▒███  ▒███▒▒███▒███     ▒███     ▒███████   "
	@echo " ▒███▒▒▒█       ▒███                     ▒███▒▒▒▒▒▒   ▒███▒▒▒▒▒███  ▒███  ▒███ ▒▒██████     ▒███     ▒███▒▒▒█   "
	@echo " ▒███  ▒        ▒███                     ▒███         ▒███    ▒███  ▒███  ▒███  ▒▒█████     ▒███     ▒███  ▒    "
	@echo " █████          █████       █████████    █████        █████   █████ █████ █████  ▒▒█████    █████    █████      "
	@echo "▒▒▒▒▒          ▒▒▒▒▒       ▒▒▒▒▒▒▒▒▒    ▒▒▒▒▒        ▒▒▒▒▒   ▒▒▒▒▒ ▒▒▒▒▒ ▒▒▒▒▒    ▒▒▒▒▒    ▒▒▒▒▒    ▒▒▒▒▒       "
	@echo "\n"
	@echo $(BGRN)"✨Bonus compilation completed✨"$(RST)                                                                                                                
	@echo $(BYEL)"This project was created by mmiguelo!"$(RST)

#          ________________________________________________
# ________|                                               |_______
# \       |                  CLEAN RULES                  |      /
#  \      |                                               |     /
#  /      |_______________________________________________|     \ 
# /__________)                                        (__________\ 


#remove .o
clean:
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS) $(OBJS_BONUS) $(DEPS)
	@echo $(BMAG)"✨Objects removed" $(BGRN)"successfully✨"$(RST)

#clean and remove
fclean:
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
	@$(RM) -rf $(OBJ_DIR)
	@echo $(BMAG)"✨Program removed" $(BGRN)"successfully✨"$(RST)

#remake
re: fclean all
	@echo $(BMAG)"✨Re-compile was" $(BGRN)"successful✨"$(RST)

#Phony targets to avoid clashes
.PHONY: all clean fclean re bonus val

-include $(DEPS)

#          ________________________________________________
# ________|                                               |_______
# \       |                    COLORS                     |      /
#  \      |                                               |     /
#  /      |_______________________________________________|     \ 
# /__________)                                        (__________\ 


#color list for foreground
#bash -c 'for c in {0..255}; do tput setaf $c; tput setaf $c | cat -v; echo =$c; done'

RED		= "\033[0;31m"
GRN		= "\033[0;32m"  
YEL		= "\033[0;33m"
BLU		= "\033[0;34m"
BLA		= "\033[0;30m"
CYAN	= "\033[0;36m"
GREY	= "\033[0;90m"
BBLA	= "\033[30;1m"
BRED 	= "\033[31;1m"
BGRN	= "\033[32;1m"
BYEL	= "\033[33;1m"
BBLU	= "\033[34;1m"
BMAG	= "\033[35;1m"
BCYA	= "\033[36;1m"
BWHI	= "\033[37;1m"
RST		= "\033[0m"

# Background colors
BGRED	= "\033[41m"
BGGRN	= "\033[42m"
BGYEL	= "\033[43m"
BGBLU	= "\033[44m"
BGMAG	= "\033[45m"
BGCYA	= "\033[46m"
BGWHI	= "\033[47m"
BGBLA	= "\033[40m"

# Bright (bold/high intensity) background colors
BGBRED	= "\033[101m"
BGBGRN	= "\033[102m"
BGBYEL	= "\033[103m"
BGBBLU	= "\033[104m"
BGBMAG	= "\033[105m"
BGBCYA	= "\033[106m"
BGBWHI	= "\033[107m"

#cc -Wall -Wextra -Werror -Imandatory -Ibonus -I. main.c ./libftprintf.a -o test
#./test