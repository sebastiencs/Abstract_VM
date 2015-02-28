//
// OperandInt32.cpp for Abstract_VM-master in /home/denel-_l/rendu/Abstract_VM-master
//
// Made by denel-_l
// Login   <denel-_l@epitech.net>
//
// Started on  Sun Feb 22 13:43:34 2015 denel-_l
// Last update Sat Feb 28 20:26:31 2015 chapui_s
//

#include "OperandInt32.hpp"
#include <limits>

OperandInt32::OperandInt32(std::string const &s) : str(s) {
  long	tmp;

  std::stringstream(s) >> tmp;
  nb = tmp;
  if (nb != tmp)
    throw ExceptionCPU("Overflow/Underflow on Int32 creation");
  precision = INT32;
  type = Int32;
}

std::string const	&OperandInt32::toString() const {
  return (str);
}

int			OperandInt32::getPrecision() const {
  return (precision);
}

eOperandType		OperandInt32::getType() const {
  return (type);
}

std::string const	OperandInt32::valToString(long const& n) const {
  std::stringstream	ss;

  ss << n;
  return (ss.str());
}

long			OperandInt32::stringToValue(std::string const &s) const {
  std::stringstream	ss(s);
  long			val;

  ss >> val;
  return (val);
}

IOperand		*OperandInt32::operator+(const IOperand &rhs) const {
  long			tmp;

  if (rhs.getPrecision() > precision)
    return (rhs + *this);
  tmp = this->nb + stringToValue(rhs.toString());
  if (tmp - this->nb != stringToValue(rhs.toString()))
    throw ExceptionCPU("Overflow Int32 + Int32");
  return (new OperandInt32(valToString(tmp)));
}

IOperand		*OperandInt32::operator-(const IOperand &rhs) const {
  long			tmp;

  if (rhs.getPrecision() > precision)
    return (rhs - *this);
  tmp = this->nb - stringToValue(rhs.toString());
  if (tmp + stringToValue(rhs.toString()) != static_cast<long>(this->nb))
    throw ExceptionCPU("Underflow Int32 - Int32");
  return (new OperandInt32(valToString(tmp)));
}

IOperand		*OperandInt32::operator*(const IOperand &rhs) const {
  long			tmp;

  if (rhs.getPrecision() > precision)
    return (rhs * *this);
  tmp = stringToValue(rhs.toString()) * this->nb;
  return (new OperandInt32(valToString(tmp)));
}

IOperand		*OperandInt32::operator/(const IOperand &rhs) const {
  int			result;

  if (rhs.getPrecision() > precision)
    return (rhs / *this);
  if (stringToValue(rhs.toString()) == 0)
    throw ExceptionCPU("Division by zero (Int32)");
  result = this->nb / stringToValue(rhs.toString());
  return (new OperandInt32(valToString(result)));
}

IOperand		*OperandInt32::operator%(const IOperand &rhs) const {
  int			result;

  if (rhs.getPrecision() > precision)
    return (rhs % *this);
  if (stringToValue(rhs.toString()) == 0)
    throw ExceptionCPU("Modulo by zero (Int32)");
  result = this->nb % stringToValue(rhs.toString());
  return (new OperandInt32(valToString(result)));
}
