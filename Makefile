# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdoo <hdoo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 07:59:01 by hdoo              #+#    #+#              #
#    Updated: 2022/10/24 05:11:15 by hdoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

all : $(NAME)

$(NAME):
	@$(MAKE) -C srcs $(MAKECMDGOALS)
	@cd srcs && cp $(NAME) ..

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
