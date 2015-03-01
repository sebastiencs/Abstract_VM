//
// createOperand.hpp for epitech in /home/chapuis_s/rendu/
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Sun Mar  1 02:11:25 2015 chapui_s
// Last update Sun Mar  1 05:32:38 2015 chapui_s
//

#ifndef CREATEOPERAND_H_
# define CREATEOPERAND_H_

# include "IOperand.hpp"

class		CreateOperand
{
public:

  typedef struct	s_ope {
    eOperandType	type;
    IOperand		*(*create)(const std::string &);
  }			t_ope;

private:

  static IOperand		*createInt8(const std::string &);
  static IOperand		*createInt16(const std::string &);
  static IOperand		*createInt32(const std::string &);
  static IOperand		*createFloat(const std::string &);
  static IOperand		*createDouble(const std::string &);

  static CreateOperand::t_ope	*getFunc();

public:

  static IOperand		*createOperand(eOperandType, const std::string &);
};

#endif // !CREATEOPERAND
