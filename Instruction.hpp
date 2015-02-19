//
// SyntaxTree.hpp for epitech in /home/chapuis_s/rendu/
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Wed Feb 18 00:52:37 2015 chapui_s
// Last update Thu Feb 19 22:08:37 2015 chapui_s
//

#ifndef SYNTAXTREE_H_
# define SYNTAXTREE_H_

class			Instruction
{
private:
  std::string const	inst;
  eOperandType const	optPrecision;
  std::string const	optNumber;
public:
  Instruction(std::string &i, eOperandType optP, std::string &optN)
    : inst(i), optPrecision(optP), optNumber(optN) {};
  std::string const	&getInstruction() const {return inst;};
  eOperandType const	&getPrecision() const {return optPrecision;};
  std::string const	&getNumber() const {return optNumber;};
};

#endif // !SYNTAXTREE_H_
