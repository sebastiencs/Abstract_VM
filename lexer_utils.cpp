//
// lexer_utils.cpp for epitech in /home/chapuis_s/rendu/
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Tue Feb 17 20:14:52 2015 chapui_s
// Last update Tue Feb 24 19:00:09 2015 chapui_s
//

#include "parser.hpp"

void	Parser::BufferZero(char *buf) {
  for (size_t i = 0; i < SIZE_BUFFER; ++i)
    buf[i] = 0;
}

void	Parser::LoadBuf1() {
  BufferZero(buf1);
  file.read(buf1, SIZE_BUFFER);
}

void	Parser::LoadBuf2() {
  BufferZero(buf2);
  file.read(buf2, SIZE_BUFFER);
}

void	Parser::CleanStr() {
  str = "";
}

int	Parser::isNumber(char const &c) const {
  return ((c >= '0' && c <= '9') ? (1) : (0));
}

int	Parser::isLetter(char const &c) const {
  return ((c >= 'a' && c <= 'z') ? (1) : (0));
}

char			Parser::readStdin() {
  static std::string	s;
  std::string		tmp;
  static int		i = 0;

  if (!i) {
    while (std::getline(std::cin, tmp)) {
      s += tmp;
      s += '\n';
      if (tmp == ";;")
	break;
    }
  }
  return (s[i++]);
}
