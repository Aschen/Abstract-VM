##
## Makefile for  in /home/brunne_r/Public/abstract_vm/cpp_abstractvm/includes
## 
## Made by Romain Brunner
## Login   <brunne_r@epitech.net>
## 
## Started on  Fri 21/02/2014 00:00
##

CXX	=	clang++

SRCS	=	Transform.cpp \
		Operand.cpp \
		Factory.cpp \


CXXFLAGS=	-W -Wall -Werror

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	test

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CXX) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

