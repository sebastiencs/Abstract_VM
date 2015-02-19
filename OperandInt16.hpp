//
// OperandInt16.hpp for epitech in /home/chapuis_s/rendu/
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Thu Feb 19 22:01:50 2015 chapui_s
// Last update Thu Feb 19 22:04:31 2015 chapui_s
//

#ifndef OPERAND16_H_
# define OPERAND16_H_

# include <iostream>
# include <sstream>
# include "avm.hpp"
# include "ExceptionCPU.hpp"

class			OperandInt16 : public IOperand
{
private:
  std::string const	str;
  short			nb;
  int			precision;
  eOperandType		type;

public:
  OperandInt16(std::string const &s);

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

#endif // !OPERAND16_H_
