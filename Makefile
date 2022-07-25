# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 13:49:50 by ahhammou          #+#    #+#              #
#    Updated: 2022/07/25 15:55:05 by ahhammou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Temps
SRCS		=  ./main.cpp 
OBJS		= $(SRCS:.cpp=.o)
RM			= rm -f
#CXXFLAGS		= -Wall -Wextra -Werror -std=c++98
OS	= $(shell uname)
ifeq ($(OS), Linux)
	C++			= g++
else
	C++			= c++
endif

$(NAME): ${OBJS}
	${C++} $(OBJS) -o $(NAME)
#${C++} ${CXXFLAGS} $(OBJS) -o $(NAME)

all: $(NAME)
    
fclean: clean
	$(RM) $(NAME)
    
clean:
	$(RM) -f $(OBJS) $(OBJS_B)
    
re: fclean all

.PHONY: all clean fclean re .cpp.o test
