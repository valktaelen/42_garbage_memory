# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 16:27:10 by aartiges &        #+#    #+#              #
#    Updated: 2022/05/07 16:53:45 by aartiges         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

################################################################################
##                               Présentation                                 ##
################################################################################

COLOR_NORM		=	\033[0m
COLOR_RED		=	\033[31m
COLOR_PURPLE	=	\033[35m

################################################################################
##                               SRCS                                         ##
################################################################################

MK = Makefile

# Headers

DIR_HDS				=	includes

RELATIVE_HDS		=	tracker.h			\
						tracker_private.h

# Code

DIR_GLOBAL						=	srcs
SRC_GLOBAL						=	free.c		\
									free_dim.c	\
									list.c		\
									track.c		\
									utils.c

################################################################################
##                       Compilation Environnement                            ##
################################################################################

NAME	=	libtrack.a
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -O3 
#-g3 -ggdb -fsanitize=address

# Sources

DIRS_SRC			=	$(DIR_GLOBAL)

DIR_OBJ				=	obj

SRCS		=	$(addprefix $(DIR_GLOBAL)/, $(SRC_GLOBAL))

HDS			=	$(addprefix $(DIR_HDS)/, $(RELATIVE_HDS))
OBJS		=	$(addprefix $(DIR_OBJ)/, $(SRCS:.c=.o))

DEPENDS		=	$(HDS) $(MK)

################################################################################
##                                 Règles                                     ##
################################################################################

all		:	$(NAME)

define src2obj
$(DIR_OBJ)/$(1)/%.o:	$(1)/%.c $(2)
	@mkdir -p $(DIR_OBJ)/$(1)
	@printf "\r\033[K\tCompilation of $(COLOR_PURPLE)$$< ==> $$@\$(COLOR_NORM)"
	@$(CC) $(CFLAGS) -c -o $$@ $$< $(INC_INC)
endef

$(foreach dir,$(DIRS_SRC),$(eval $(call src2obj,$(dir), $(DEPENDS))))

$(NAME)	: $(DEPENDS) $(OBJS)
	@printf "\n\tCompilation of $(COLOR_PURPLE)$(NAME)\$(COLOR_NORM)\n"
	@ar rc $(NAME) $(OBJS)

clean:
	@printf "\tDelete $(COLOR_RED)object of $(DIR_OBJ)$(COLOR_NORM) of $(NAME)\n"
	@rm -rf $(DIR_OBJ)

fclean:	clean ftest
	@printf "\tDelete $(COLOR_RED)$(NAME)$(COLOR_NORM)\n"
	@rm -rf $(NAME)

re:	fclean all

norm:
	@norminette	$(HDS) $(SRCS) $(SRCS_BONUS) || true

test: all
	make -C test_src/libft/code
	$(CC) $(CFLAGS) -o test test_src/main.c -Ltest_src/libft/code -lft -L. -ltrack -fsanitize=address

ftest: fclean
	make -C test_src/libft/code fclean
	rm -rf test

retest: ftest test
