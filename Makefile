##
## Makefile for epitech in /home/chapuis_s/rendu/
##
## Made by chapui_s
## Login   <chapui_s@epitech.eu>
##
## Started on  Fri Feb 20 02:24:14 2015 chapui_s
## Last update Sun Mar  1 05:42:51 2015 chapui_s
##

NAME		= avm

SRC		= AbstractVm.cpp	\
		  avm.cpp		\
		  CPU.cpp		\
		  lexer.cpp		\
		  lexer_utils.cpp	\
		  Operands.cpp		\
		  parser.cpp		\
		  Stack.cpp		\
		  createOperand.cpp

OBJ		= $(SRC:.cpp=.o)

CC		= g++

CXXFLAGS	+= -Wall -Wextra

RM		= rm -rf

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
