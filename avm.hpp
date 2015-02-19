//
// avm.hpp for epitech in /home/chapui_s/rendu/cpp_abstractvm/avm.hpp
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Tue Feb 17 00:42:05 2015 chapui_s
// Last update Thu Feb 19 22:10:12 2015 chapui_s
//

#ifndef AVM_HPP_
# define AVM_HPP_

# include <map>
# include <sstream>
# include "IOperand.hpp"
# include "Instruction.hpp"
# include "CPU.hpp"
# include "Stack.hpp"

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
    PRECISION = 1,
    INTEGER = 2,
    FLOAT = 3,
    END_FILE = 4,
    OPEN_PAREN = 5,
    CLOSE_PAREN = 6,
    NEW_LINE = 7,
    UNKNOWN = -1
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

  AbstractVm(std::istream &file);
  ~AbstractVm();

  void		Run();

};

#endif // !AVM_HPP_
