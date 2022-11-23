# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 07:59:01 by hdoo              #+#    #+#              #
#    Updated: 2022/11/23 09:42:29 by hdoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
NAME_BONUS = cub3D_bonus

all : $(NAME)

$(NAME):
	@$(MAKE) -C srcs $(MAKECMDGOALS)
	@cd srcs && cp $(NAME) ..

$(NAME_BONUS):
	@$(MAKE) -C srcs $(MAKECMDGOALS)
	@cd srcs && cp $(NAME) ..

bonus : $(NAME_BONUS)

clean :
	@$(MAKE) -C srcs $(MAKECMDGOALS)

fclean :
	@$(MAKE) -C srcs $(MAKECMDGOALS)
	@rm $(NAME)

re :
	@$(MAKE) -C srcs $(MAKECMDGOALS)
	@cd srcs && cp $(NAME) ..

dev :
	@$(MAKE) -C srcs $(MAKECMDGOALS)
	@echo "Test & compile_commands.json created"

test :
	@$(MAKE) -C srcs $(MAKECMDGOALS)
