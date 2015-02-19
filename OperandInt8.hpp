//
// Operand.hpp for epitech in /home/chapuis_s/rendu/
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Wed Feb 18 21:29:51 2015 chapui_s
// Last update Thu Feb 19 20:22:33 2015 chapui_s
//

#ifndef OPERAND_H_
# define OPERAND_H_

# include <iostream>
# include <sstream>
# include "IOperand.hpp"
# include "ExceptionCPU.hpp"

class			OperandInt8 : public IOperand
{
private:
  std::string const	str;
  char			nb;
  int			precision;
  eOperandType		type;

public:
  OperandInt8(std::string const &s);

  virtual std::string const	&toString() const;

  virtual int			getPrecision() const;
  virtual eOperandType		getType() const;

  virtual IOperand * operator+(const IOperand &rhs) const;
  virtual IOperand * operator-(const IOperand &rhs) const;
  virtual IOperand * operator*(const IOperand &rhs) const;
  virtual IOperand * operator/(const IOperand &rhs) const;
  virtual IOperand * operator%(const IOperand &rhs) const;

  std::string const	valToString(int const &) const;
  int			stringToValue(std::string const &) const;
};

#endif // !OPERAND_H_
