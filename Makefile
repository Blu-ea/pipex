# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 11:24:21 by amiguez           #+#    #+#              #
#    Updated: 2022/05/21 08:44:20 by amiguez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex

# /////////////////////////////////

LST_SRCS	:=	main.c\
				pars.c\
				debug.c
LST_OBJS	:=	$(LST_SRCS:.c=.o)
LST_INCS	:=	pipex.h
LST_LIBFT	:=	libft.a

# /////////////////////////////////

DIR_SRCS	:=	srcs
DIR_OBJS	:=	.objs
DIR_INCS	:=	includes
DIR_LIBFT	:=	libft

# /////////////////////////////////

SRCS	:=	$(addprefix $(DIR_SRCS)/, $(LST_SRCS))
OBJS	:=	$(addprefix $(DIR_OBJS)/, $(LST_OBJS))
INCS	:=	$(addprefix $(DIR_INCS)/, $(LST_INCS))
LIBFT	:=	$(addprefix $(DIR_LIBFT)/, $(LST_LIBFT))

# /////////////////////////////////

CC		:=	gcc
CFLAGS	:=	#-Werror -Wextra -Wall

# /////////////////////////////////

ERASE	=	\033[2K\r
GREY	=	\033[30m
RED		=	\033[31m
GREEN 	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
PINK	=	\033[35m
CYAN	=	\033[36m
WHITE	=	\033[37m
BOLD	=	\033[1m
UNDER	=	\033[4m
SUR		=	\033[7m
END		=	\033[0m

NORMITEST	=
NORMINETTE	= $(shell norminette $(SRCS) | grep -i 'Error')

SANITIZE = -g3 -fsanitize=address

# /////////////////////////////////

all				: $(NAME)

$(NAME)			: $(OBJS) $(INCS) Makefile | $(LIBFT)
	printf "${GREEN}Compiling Pipex :${END}"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	printf "${ERASE}${WHITE}Compiling Pipex : ${GREEN}$(BOLD) Done${END}\n"

ifeq ($(NORMINETTE),$(NORMITEST))
	printf "$(GREEN)Everything is $(BOLD)ok\n$(END)"
else
	printf "$(RED)$(SUR)THERE IS AN ERROR WITH NORMINETTE IN LIBFT FILES !!$(END)\n"
endif

$(DIR_OBJS)/%.o	:	$(DIR_SRCS)/%.c $(INCS) Makefile | $(DIR_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@
	printf "$(ERASE)$(BLUE)$(BOLD)Compiling Pipex : $<$(END)"

$(DIR_OBJS)		:
	mkdir -p $(DIR_OBJS)

$(LIBFT)	:
	make -C libft

# /////////////////////////////////

clean	:
	make -C libft clean
	rm -rf $(DIR_OBJS)
	printf "/!\ Erasing $(DIR_OBJS) in Pipex$(END)\n"

fclean	: clean
	make -C libft fclean
	rm -rf $(NAME)

re		: fclean all

.PHONY	: all clean fclean re $(LIBFT)
.SILENT	: