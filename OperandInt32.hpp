//
// OperandInt32.hpp for Abstract_VM in /home/denel-_l/rendu/git/Abstract_VM
//
// Made by denel-_l
// Login   <denel-_l@epitech.net>
//
// Started on  Sun Feb 22 22:05:09 2015 denel-_l
// Last update Sun Feb 22 22:05:30 2015 denel-_l
//

#ifndef OPERAND32_H_
# define OPERAND32_H_

# include <iostream>
# include <sstream>
# include "avm.hpp"
# include "ExceptionCPU.hpp"

class			OperandInt32 : public IOperand
{
private:
  std::string const	str;
  int			nb;
  int			precision;
  eOperandType		type;

public:
  OperandInt32(std::string const &s);

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

#endif // !OPERAND32_H_
