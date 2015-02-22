//
// OperandDouble.hpp for Abstract_VM-master in /home/denel-_l/rendu/Abstract_VM-master
//
// Made by denel-_l
// Login   <denel-_l@epitech.net>
//
// Started on  Sun Feb 22 14:25:07 2015 denel-_l
// Last update Sun Feb 22 14:26:34 2015 denel-_l
//

#ifndef OPERANDDOUBLE_H_
# define OPERANDDOUBLE_H_

# include <iostream>
# include <sstream>
# include "avm.hpp"
# include "ExceptionCPU.hpp"

class			OperandDouble : public IOperand
{
private:
  std::string const	str;
  double       		nb;
  int			precision;
  eOperandType		type;

public:
  OperandDouble(std::string const &s);

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

#endif // !OPERANDDOUBLE_H_
