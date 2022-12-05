
CXX		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS = $(addsuffix .cpp, megaphone)
OBJS = $(SRCS:.cpp=.o)

NAME = megaphone

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) -o $@ $^

%.o : %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
