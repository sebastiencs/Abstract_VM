//
// CPU.hpp for epitech in /home/chapuis_s/rendu/
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Wed Feb 18 06:39:35 2015 chapui_s
// Last update Sun Mar  1 02:19:23 2015 chapui_s
//

#ifndef CPU_H_
# define CPU_H_

# include <iostream>
# include "IOperand.hpp"
# include "Instruction.hpp"
# include "Stack.hpp"
//# include "Operands.hpp"
// # include "OperandInt8.hpp"
// # include "OperandInt16.hpp"
// # include "OperandInt32.hpp"
// # include "OperandDouble.hpp"
// # include "OperandFloat.hpp"

class		Stack;

class		CPU
{
private:
  Stack 	*stack;
  int		isStandarInput;
  IOperand	*register1, *register2, *register3;

  // IOperand	*createInt8(const std::string &);
  // IOperand	*createInt16(const std::string &);
  // IOperand	*createInt32(const std::string &);
  // IOperand	*createFloat(const std::string &);
  // IOperand	*createDouble(const std::string &);

public:
  CPU(Stack *, int);

  // typedef struct	s_ope {
  //   eOperandType	type;
  //   IOperand		*(CPU::*create)(const std::string &);
  // }			t_ope;

  // static IOperand	*createOperand(eOperandType, const std::string &);

  int		push(Instruction const *);
  int		assert(Instruction const *);
  int		dump(Instruction const *);
  int		print(Instruction const *);
  int		pop(Instruction const *);
  int		add(Instruction const *);
  int		sub(Instruction const *);
  int		mul(Instruction const *);
  int		div(Instruction const *);
  int		mod(Instruction const *);
  int		exit(Instruction const *);
};

#endif // !CPU_H_
