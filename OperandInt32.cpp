//
// OperandInt32.cpp for Abstract_VM-master in /home/denel-_l/rendu/Abstract_VM-master
//
// Made by denel-_l
// Login   <denel-_l@epitech.net>
//
// Started on  Sun Feb 22 13:43:34 2015 denel-_l
// Last update Sun Feb 22 20:47:38 2015 denel-_l
//

#include "OperandInt32.hpp"
#include <limits>

OperandInt32::OperandInt32(std::string const &s) : str(s) {
  int	tmp;

  std::stringstream(s) >> tmp;
  nb = tmp;
  if (tmp == std::numeric_limits<int>::max() || tmp == std::numeric_limits<int>::min())
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

std::string const	OperandInt32::valToString(int const& n) const {
  std::stringstream	ss;

  ss << n;
  return (ss.str());
}

int			OperandInt32::stringToValue(std::string const &s) const {
  std::stringstream	ss(s);
  int			val;

  ss >> val;
  return (val);
}

IOperand		*OperandInt32::operator+(const IOperand &rhs) const {
  int			result;
  int			tmp;

  if (rhs.getPrecision() > precision)
    return (rhs + *this);
  tmp = this->nb + stringToValue(rhs.toString());
  tmp = this->nb + stringToValue(rhs.toString());
  result = tmp;
  if (tmp == std::numeric_limits<int>::max() || tmp == std::numeric_limits<int>::min())
    throw ExceptionCPU("Underflow Int32 + Int32");
  return (new OperandInt32(valToString(tmp)));
}

IOperand		*OperandInt32::operator-(const IOperand &rhs) const {
  int			result;
  int			tmp;

  if (rhs.getPrecision() > precision)
    return (rhs - *this);
  tmp = this->nb - stringToValue(rhs.toString());
  result = tmp;
  if (tmp == std::numeric_limits<int>::max() || tmp == std::numeric_limits<int>::min())
    throw ExceptionCPU("Underflow Int32 - Int32");
  return (new OperandInt32(valToString(result)));
}

IOperand		*OperandInt32::operator*(const IOperand &rhs) const {
  int 			result;
  int			tmp;

  if (rhs.getPrecision() > precision)
    return (rhs * *this);
  tmp = stringToValue(rhs.toString()) * this->nb;
  result = tmp;
  if (tmp == std::numeric_limits<int>::max() || tmp == std::numeric_limits<int>::min())
    throw ExceptionCPU("Overflow Int32 * Int32");
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