//
// ExceptionParser.hpp for epitech in /home/chapuis_s/rendu/
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Thu Feb 19 19:03:15 2015 chapui_s
// Last update Thu Feb 19 20:14:19 2015 chapui_s
//

#ifndef EXCEPTIONPARSER_H_
# define EXCEPTIONPARSER_H_

# include <exception>

class		ExceptionParser : public std::exception
{
private:
  std::string	msg;

public:

  ExceptionParser(const char *s, int line, const char *s2 = "") {
    std::ostringstream oss;

    if (s[0] == '\n')
      s = "NEWLINE";
    oss << "Parsing error line " << line << ": "  << s2 << "'" << s << "'";
    msg = oss.str();
  }

  virtual ~ExceptionParser() throw() {}

  virtual const char	*what() const throw() {
    return (msg.c_str());
  }
};

#endif // !EXCEPTIONPARSER
