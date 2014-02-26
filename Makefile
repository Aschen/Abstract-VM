##
## Makefile for  in /home/maret_a/Projets/AbstractVM/cpp_abstractvm/sources
## 
## Made by Adrien Maret
## Login   <maret_a@epitech.net>
## 
## 
## Started on  19/02/2014 15:26
##

CC	=	g++

SRCS	=	sources/Exceptions.cpp \
		sources/Lexer.cpp \
		sources/Input.cpp \
		sources/Parser.cpp \
		sources/Factory.cpp \
		sources/Operand.cpp \
		sources/Transform.cpp \
		sources/Limits.cpp \
		sources/VmStack.cpp \
		sources/main.cpp

CXXFLAGS=	-Wall -W -Wextra -Iincludes

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	avm

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clang:
	clang++ $(SRCS) -o $(NAME) -Iincludes

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all