//
// getToken.cpp for epitech in /home/chapuis_s/rendu/
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Tue Feb 17 20:11:52 2015 chapui_s
// Last update Thu Feb 19 20:33:26 2015 chapui_s
//

#include "parser.hpp"

AbstractVm::Token	table_reserved[] = {
  { AbstractVm::KEYWORD, "pop" },
  { AbstractVm::KEYWORD, "add" },
  { AbstractVm::KEYWORD, "mul" },
  { AbstractVm::KEYWORD, "exit" },
  { AbstractVm::KEYWORD, "dump" },
  { AbstractVm::KEYWORD, "sub" },
  { AbstractVm::KEYWORD, "div" },
  { AbstractVm::KEYWORD, "mod" },
  { AbstractVm::KEYWORD, "print" },
  { AbstractVm::KEYWORD, "push" },
  { AbstractVm::KEYWORD, "assert" },
  { AbstractVm::PRECISION, "int8" },
  { AbstractVm::PRECISION, "int16" },
  { AbstractVm::PRECISION, "int32" },
  { AbstractVm::PRECISION, "float" },
  { AbstractVm::PRECISION, "double" },
};

char	Parser::GetNextChar() {
  char	current;

  if (index == 10)
    LoadBuf2();
  else if (index == 20)
    LoadBuf1();
  if (index > 19)
    index = 0;
  current = ((index < 10) ? (buf1[index]) : (buf2[index - 10]));
  index += 1;
  return (current);
}

AbstractVm::Token	Parser::CreateToken(AbstractVm::TokenClass classToken) {
  AbstractVm::Token	token = {classToken, str};
  return (token);
}

int			Parser::isInTable(std::string const &s) const {
  for (size_t i = 0; i < sizeof(table_reserved) / sizeof(table_reserved[0]); ++i) {
    if (table_reserved[i].identifier == s)
      return (i);
  }
  return (-1);
}

AbstractVm::Token	Parser::GetToken() {
  static char		c = ' ';
  State			state = START;
  int			i;

  CleanStr();
  while (1) {
    switch(state) {

    case (START):
      if (c == ' ' || c == '\t') c = GetNextChar();
      else if (isLetter(c)) state = WORD;
      else if (isNumber(c)) state = NUMBER;
      else if (c == ';') state = COMMENT;
      else if (c == '(') state = OPEN;
      else if (c == ')') state = CLOSE;
      else if (c == '-') state = NEG;
      else if (c == '\n') state = NEWLINE;
      else if (c == '\0') return (CreateToken(AbstractVm::END_FILE));
      else throw ExceptionParser((str += c).c_str(), line, "Unknow character ");
      break;

    case (WORD):
      while (isLetter(c) || isNumber(c)) {
	str += c;
	c = GetNextChar();
      }
      if ((i = isInTable(str)) != -1)
	return (CreateToken(table_reserved[i].tokenClass));
      throw ExceptionParser(str.c_str(), line, "Unknow word ");

    case (COMMENT):
      c = GetNextChar();
      if (c == ';' && isStandartInput) {
	str += c;
	return (CreateToken(AbstractVm::KEYWORD));
      }
      while (c != '\n')
	c = GetNextChar();
      state = START;
      break;

    case (OPEN):
      str += c;
      c = GetNextChar();
      return (CreateToken(AbstractVm::OPEN_PAREN));

    case (NUMBER):
      str += c;
      while (isNumber((c = GetNextChar())))
      	str += c;
      if (c != '.')
	return (CreateToken(AbstractVm::INTEGER));
      str += c;
      if (isNumber(c = GetNextChar())) {
	str += c;
	while (isNumber((c = GetNextChar())))
	  str += c;
	return (CreateToken(AbstractVm::FLOAT));
      }
      throw ExceptionParser(str.c_str(), line, "Invalid float/double number ");

    case (CLOSE):
      str += c;
      c = GetNextChar();
      return (CreateToken(AbstractVm::CLOSE_PAREN));

    case (NEWLINE):
      str += c;
      c = GetNextChar();
      line += 1;
      return (CreateToken(AbstractVm::NEW_LINE));

    case (NEG):
      str += c;
      c = GetNextChar();
      if (!isNumber(c))
	throw ExceptionParser("Invalid negativ number", line);
      state = (isNumber(c)) ? (NUMBER) : (ERROR);
      break;

    case (ERROR):
      return (CreateToken(AbstractVm::UNKNOWN));
    }
  }
}