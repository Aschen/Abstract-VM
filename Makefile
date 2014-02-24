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
		sources/main.cpp

CXXFLAGS=	-Wall -W -Wextra -Iincludes

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	test

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

diff: re
	./$(NAME) > output
	diff --suppress-common-line output diff | colordiff
