//
// ExceptionCPU.hpp for epitech in /home/chapuis_s/rendu/
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Thu Feb 19 20:13:36 2015 chapui_s
// Last update Thu Feb 19 20:19:30 2015 chapui_s
//

#ifndef EXCEPTIONCPU_H_
# define EXCEPTIONCPU_H_

# include <exception>

class		ExceptionCPU : public std::exception
{
private:
  std::string	msg;

public:

  ExceptionCPU(const char *s) {
    std::ostringstream oss;

    oss << "CPU error: " << s;
    msg = oss.str();
  }

  virtual ~ExceptionCPU() throw() {}

  virtual const char	*what() const throw() {
    return (msg.c_str());
  }
};

#endif // !EXCEPTIONPARSER
