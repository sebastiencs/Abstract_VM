##
## Makefile for epitech in /home/chapuis_s/rendu/
##
## Made by chapui_s
## Login   <chapui_s@epitech.eu>
##
## Started on  Fri Feb 20 02:24:14 2015 chapui_s
## Last update Sat Feb 28 18:24:34 2015 chapui_s
##

NAME		= avm

SRC		= AbstractVm.cpp	\
		  avm.cpp		\
		  CPU.cpp		\
		  lexer.cpp		\
		  lexer_utils.cpp	\
		  OperandFloat.cpp	\
		  OperandDouble.cpp	\
		  OperandInt32.cpp	\
		  OperandInt16.cpp	\
		  OperandInt8.cpp	\
		  parser.cpp		\
		  Stack.cpp

OBJ		= $(SRC:.cpp=.o)

CC		= g++

RM		= rm -rf

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
