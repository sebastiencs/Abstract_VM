//
// parser.hpp for epitech in /home/chapui_s/rendu/cpp_abstractvm/parser.hpp
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Mon Feb 16 03:24:00 2015 chapui_s
// Last update Fri Feb 20 01:54:05 2015 chapui_s
//

#ifndef PARSER_HPP_
# define PARSER_HPP_

# include <iostream>
# include <fstream>
# include <map>
# include "avm.hpp"
# include "ExceptionParser.hpp"

# define SIZE_BUFFER	(10)

enum State{
  START = 0, WORD = 2, COMMENT = 3, OPEN = 4,
  NUMBER = 5, CLOSE = 6, NEWLINE = 7, NEG = 8
};

class		Parser
{
protected:
  char		*buf1;
  char		*buf2;
  std::istream	&file;
  int		index;
  int		line;
  std::string	str;
  int		isStandartInput;
  std::map<std::string, eOperandType> precision;

  void			LoadBuf1();
  void			LoadBuf2();
  void			BufferZero(char *);
  AbstractVm::Token	CreateToken(AbstractVm::TokenClass);
  char			GetNextChar();
  void			CleanStr();
  int			isNumber(char const &) const;
  int			isLetter(char const &) const;
  AbstractVm::Token	GetToken();
  int			isInTable(std::string const &s) const;
  Instruction		*ManageKeyword(AbstractVm::Token &);

public:
  Parser(std::istream &file = std::cin);
  virtual ~Parser();

  void		Run();
  Instruction	*GetInstruction();
  int		getLine() const;
  int		getIsStandartInput() const {return isStandartInput;}
};

#endif // !PARSER_HPP_
