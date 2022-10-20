# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 19:39:53 by hdoo              #+#    #+#              #
#    Updated: 2022/10/20 13:08:41 by sielee           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

.DELETE_ON_ERROR:

.DEFAULT_GOAL			:=	mandatory

# CC						:=	/Users/hdoo/works/clang/bin/clang-14
CC						:=	cc
CFLAGS					:=	-Wall -Wextra -Werror -I. -MMD -g -fsanitize=address

LDLIBS					:=	-lft -lmlx

LIBFT					:=	libft/libft.a

NAME					:=	cub3D

MINILIBX				:=	minilibx_mms_20210621/libmlx.dylib

INC_DIR					:=	include
SRCS_DIR				:=	srcs
SRCS					:= $(addsuffix .c,$(addprefix $(SRCS_DIR)/,\
						main))\

DEPS					:=	$(MINILIBX:.dylib=.d) $(LIBFT:.a=.d) $(SRCS:.c=.d)
OBJS					:=	$(SRCS:.c=.o)

mandatory: OBJS			:=	$(OBJS)

.PHONY: all clean fclean re mandatory bonus

all: $(LIBFT) $(MINILIBX)

all: mandatory

clean:
	$(RM) $(DEPS)
	$(RM) $(OBJS)
	$(RM) $(DEPS_MAIN)
	$(RM) $(OBJS_MAIN)
	$(RM) $(DEPS_BONUS)
	$(RM) $(OBJS_BONUS)
	$(MAKE) -C ./libft $(MAKECMDGOALS)
	$(MAKE) -C ./minilibx_mms_20210621 clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(notdir $(MINILIBX))

re: 
	$(MAKE) fclean
	$(MAKE)

mandatory bonus: $(NAME)

$(NAME): $(OBJS) $(OBJS_MAIN) | $(LIBFT) $(MINILIBX)

$(OBJS) $(OBJS_MAIN) $(OBJS_BONUS): %.o: %.c %.d
	$(COMPILE.c) $(OUTPUT_OPTION) $<

$(LIBFT):
	$(MAKE) -C ./libft $(MAKECMDGOALS)

$(MINILIBX):
	$(MAKE) -C ./minilibx_mms_20210621 $(MAKECMDGOALS)
	cd minilibx_mms_20210621 && cp libmlx.dylib ..

%.d: ;

ifneq "$(MAKECMDGOALS)" "clean"
-include $(DEPS)
endif
