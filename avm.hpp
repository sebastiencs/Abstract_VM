//
// avm.hpp for epitech in /home/chapui_s/rendu/cpp_abstractvm/avm.hpp
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Tue Feb 17 00:42:05 2015 chapui_s
// Last update Sat Feb 28 18:06:37 2015 chapui_s
//

#ifndef AVM_HPP_
# define AVM_HPP_

# include <map>
# include <sstream>
# include <cmath>
# include "IOperand.hpp"
# include "Instruction.hpp"
# include "CPU.hpp"
# include "Stack.hpp"

# define ABS_NB(x) ((x < 0) ? (-x) : (x))

class		Parser;
class		Stack;
class		CPU;

class		AbstractVm
{
private:
  Parser	*parser;
  Stack		*stack;
  CPU		*cpu;

public:
  enum TokenClass {
    KEYWORD = 0,
    PRECISION = 3,
    INTEGER = 4,
    FLOAT = 6,
    END_FILE = 3,
    OPEN_PAREN = 10,
    CLOSE_PAREN = 12,
    NEW_LINE = 1,
    UNKNOWN = 14
  };

  typedef struct		s_reserved {
    AbstractVm::TokenClass	tokenClass;
    std::string			identifier;
  }				t_reserved;

  typedef struct		s_cpu {
    std::string			instStr;
    int				(CPU::*inst)(Instruction const *);
  }				t_cpu;

  typedef t_reserved		Token;

  AbstractVm(std::istream &file = std::cin);
  ~AbstractVm();

  void		Run();

};

#endif // !AVM_HPP_
