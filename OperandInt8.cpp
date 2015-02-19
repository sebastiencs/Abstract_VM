//
// Operand.cpp for epitech in /home/chapuis_s/rendu/
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Wed Feb 18 21:33:38 2015 chapui_s
// Last update Thu Feb 19 22:40:53 2015 chapui_s
//

#include "OperandInt8.hpp"

OperandInt8::OperandInt8(std::string const &s) : str(s) {
  int	tmp;

  std::stringstream(s) >> tmp;
  nb = tmp;
  if (nb != tmp)
    throw ExceptionCPU("Overflow/Underflow on Int8 creation");
  precision = INT8;
  type = Int8;
}

std::string const	&OperandInt8::toString() const {
  return (str);
}

int			OperandInt8::getPrecision() const {
  return (precision);
}

eOperandType		OperandInt8::getType() const {
  return (type);
}

std::string const	OperandInt8::valToString(int const& n) const {
  std::stringstream	ss;

  ss << n;
  return (ss.str());
}

int			OperandInt8::stringToValue(std::string const &s) const {
  std::stringstream	ss(s);
  int			val;

  ss >> val;
  return (val);
}

IOperand		*OperandInt8::operator+(const IOperand &rhs) const {
  char			result;
  int			tmp;

  if (rhs.getPrecision() > precision)
    return (rhs + *this);
  tmp = this->nb + stringToValue(rhs.toString());
  result = tmp;
  if (tmp != result)
    throw ExceptionCPU("Overflow Int8 + Int8");
  return (new OperandInt8(valToString(tmp)));
}

IOperand		*OperandInt8::operator-(const IOperand &rhs) const {
  char			result;
  int			tmp;

  if (rhs.getPrecision() > precision)
    return (rhs - *this);
  tmp = this->nb - stringToValue(rhs.toString());
  result = tmp;
  if (result != tmp)
    throw ExceptionCPU("Underflow Int8 - Int8");
  return (new OperandInt8(valToString(result)));
}

IOperand		*OperandInt8::operator*(const IOperand &rhs) const {
  char			result;
  int			tmp;

  if (rhs.getPrecision() > precision)
    return (rhs * *this);
  tmp = stringToValue(rhs.toString()) * this->nb;
  result = tmp;
  if (tmp != result)
    throw ExceptionCPU("Overflow Int8 * Int8");
  return (new OperandInt8(valToString(tmp)));
}

IOperand		*OperandInt8::operator/(const IOperand &rhs) const {
  char			result;

  if (rhs.getPrecision() > precision)
    return (rhs / *this);
  if (stringToValue(rhs.toString()) == 0)
    throw ExceptionCPU("Division by zero (Int8)");
  result = this->nb / stringToValue(rhs.toString());
  return (new OperandInt8(valToString(result)));
}

IOperand		*OperandInt8::operator%(const IOperand &rhs) const {
  char			result;

  if (rhs.getPrecision() > precision)
    return (rhs % *this);
  if (stringToValue(rhs.toString()) == 0)
    throw ExceptionCPU("Modulo by zero (Int8)");
  result = this->nb % stringToValue(rhs.toString());
  return (new OperandInt8(valToString(result)));
}
