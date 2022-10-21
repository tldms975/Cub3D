# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdoo <hdoo@student.42.kr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 09:26:57 by hdoo              #+#    #+#              #
#    Updated: 2022/06/17 19:03:40 by hdoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DELETE_ON_ERROR:

MAKEFLAGS		+=	--no-builtin-rules --jobs=6

.DEFAULT_GOAL	:=	mandatory

CFLAGS			:=	-Wall -Wextra -Werror -I. -MMD -MP -g
LDFLAGS			:=
LDLIBS			:=

NAME			:=	libft.a

SRCS			:=	ft_atoi.c							\
					ft_bzero.c              			\
					ft_calloc.c             			\
                    ft_isalnum.c            			\
                    ft_isalpha.c            			\
                    ft_isascii.c            			\
                    ft_isdigit.c            			\
                    ft_isprint.c            			\
                    ft_itoa.c               			\
                    ft_memchr.c             			\
                    ft_memcmp.c             			\
                    ft_memcpy.c             			\
                    ft_memmove.c            			\
                    ft_memset.c             			\
                    ft_putchar_fd.c         			\
                    ft_putendl_fd.c         			\
                    ft_putnbr_fd.c          			\
                    ft_putstr_fd.c          			\
                    ft_split.c              			\
                    ft_strchr.c             			\
                    ft_strdup.c             			\
                    ft_striteri.c           			\
                    ft_strjoin.c            			\
                    ft_strlcat.c            			\
                    ft_strlcpy.c            			\
                    ft_strlen.c             			\
                    ft_strncmp.c            			\
                    ft_strmapi.c            			\
                    ft_strnstr.c            			\
                    ft_strrchr.c            			\
					ft_strtrim.c            			\
					ft_substr.c             			\
					ft_tolower.c            			\
					ft_strtoupper.c         			\
					ft_toupper.c            			\
					ft_sqrt.c               			\
					ft_lstadd_front.c       			\
					ft_lstnew.c             			\
					ft_lstsize.c            			\
					ft_lstdelone.c          			\
					ft_lstclear.c           			\
					ft_lstiter.c            			\
					ft_lstmap.c             			\
					ft_lstlast.c            			\
					ft_lstadd_back.c        			\
					ft_strdel.c							\
					ft_atol.c							\
					ft_abs.c							\
					ft_pow.c							\
					ft_aredigit.c						\
					get_next_line/get_next_line.c		\
					get_next_line/get_next_line_utils.c
					
DEPS			:=	$(SRCS:.c=.d)
OBJS			:=	$(SRCS:.c=.o)

mandatory: OBJS	:=	$(OBJS)
bonus: OBJS		:=	$(OBJS)

.PHONY: all clean fclean re mandatory bonus

all: mandatory

clean:
	$(RM) $(DEPS)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

mandatory bonus: $(NAME)

$(OBJS): %.o: %.c %.d
	$(COMPILE.c) $(OUTPUT_OPTION) $<


%.d: ;

-include $(DEPS)
