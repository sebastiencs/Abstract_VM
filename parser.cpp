//
// parser.cpp for epitech in /home/chapui_s/rendu/cpp_abstractvm/parser.cpp
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Mon Feb 16 03:23:19 2015 chapui_s
// Last update Sun Mar  1 05:51:20 2015 chapui_s
//

#include "parser.hpp"

Parser::Parser(std::istream &f)
  : file(f)
{
  buf1 = 0;
  try {
    buf1 = new char[SIZE_BUFFER];
    buf2 = new char[SIZE_BUFFER];
  }
  catch (const std::bad_alloc &) {
    delete[] buf1;
    throw;
  }
  index = 0;
  line = 0;
  isStandartInput = (f == std::cin) ? (1) :(0);
  if (!isStandartInput)
    LoadBuf1();
  precision["int8"] = Int8;
  precision["int16"] = Int16;
  precision["int32"] = Int32;
  precision["float"] = Float;
  precision["double"] = Double;
}

Parser::~Parser()
{
  delete[] buf1;
  delete[] buf2;
}

int	Parser::getLine() const {
  return (line);
}

extern AbstractVm::Token table_reserved[];

Instruction		*Parser::ManageKeyword(AbstractVm::Token &token) {
  std::string		key, number;
  std::string		empty = "";
  eOperandType		type;

  key = token.identifier;
  if (token.identifier != table_reserved[9].identifier
      && token.identifier != table_reserved[10].identifier) {
    if (!(GetToken().tokenClass & AbstractVm::NEW_LINE))
      throw ExceptionParser(token.identifier.c_str(), line, "New line expected after ");
    return (new Instruction(key, Int8, empty));
  }

  token = GetToken();
  if (token.tokenClass != AbstractVm::PRECISION)
    throw ExceptionParser(token.identifier.c_str(), line,
			  "int8, int16, int32, float or double expected, no ");
  type = precision[token.identifier];

  token = GetToken();
  if (token.tokenClass != AbstractVm::OPEN_PAREN)
    throw ExceptionParser(token.identifier.c_str(), line, "'(' expected, no ");

  token = GetToken();
  if ((type == Float || type == Double) && token.tokenClass != AbstractVm::FLOAT)
    throw ExceptionParser(token.identifier.c_str(), line, "floating number expected, no ");
  else if (type != Float && type != Double && token.tokenClass != AbstractVm::INTEGER)
    throw ExceptionParser(token.identifier.c_str(), line, "integer number expected, no ");
  number = token.identifier;

  if ((token = GetToken()).tokenClass != AbstractVm::CLOSE_PAREN)
    throw ExceptionParser(token.identifier.c_str(), line, "')' expected, no ");

  if (GetToken().tokenClass != AbstractVm::NEW_LINE)
    throw ExceptionParser(token.identifier.c_str(), line, "New line expected after ");

  return (new Instruction(key, type, number));
}

Instruction		*Parser::GetInstruction() {
  AbstractVm::Token	token;

  token = GetToken();
  switch (token.tokenClass) {
  case (AbstractVm::NEW_LINE):
    return (GetInstruction());
  case (AbstractVm::KEYWORD):
    return (ManageKeyword(token));
  case (AbstractVm::END_FILE):
    return (NULL);
  default:
    throw ExceptionParser(token.identifier.c_str(), line,
			  "Unexpected word ");
  }
  return (NULL);
}
