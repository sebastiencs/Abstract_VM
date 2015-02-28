//
// Operand.cpp for epitech in /home/chapuis_s/rendu/
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Wed Feb 18 21:33:38 2015 chapui_s
// Last update Sun Mar  1 00:32:15 2015 chapui_s
//

#include "OperandInt16.hpp"

OperandInt16::OperandInt16(std::string const &s) : str(s) {
  int	tmp;

  std::stringstream(s) >> tmp;
  nb = tmp;
  if (nb != tmp)
    throw ExceptionCPU("Overflow/Underflow on Int16 creation");
  precision = INT16;
  type = Int16;
}

std::string const	&OperandInt16::toString() const {
  return (str);
}

int			OperandInt16::getPrecision() const {
  return (precision);
}

eOperandType		OperandInt16::getType() const {
  return (type);
}

std::string const	OperandInt16::valToString(int const& n) const {
  std::stringstream	ss;

  ss << n;
  return (ss.str());
}

int			OperandInt16::stringToValue(std::string const &s) const {
  std::stringstream	ss(s);
  int			val;

  ss >> val;
  return (val);
}

IOperand		*OperandInt16::operator+(const IOperand &rhs) const {
  short			result;
  int			tmp;

  if (rhs.getPrecision() > precision)
    return (rhs + *this);
  tmp = this->nb + stringToValue(rhs.toString());
  result = tmp;
  if (tmp != result)
    throw ExceptionCPU("Overflow Int16 + Int16");
  return (new OperandInt16(valToString(tmp)));
}

IOperand		*OperandInt16::operator-(const IOperand &rhs) const {
  short			result;
  int			tmp;

  if (rhs.getPrecision() > precision)
    return (rhs - *this);
  tmp = this->nb - stringToValue(rhs.toString());
  result = tmp;
  if (result != tmp)
    throw ExceptionCPU("Underflow Int16 - Int16");
  return (new OperandInt16(valToString(result)));
}

IOperand		*OperandInt16::operator*(const IOperand &rhs) const {
  short			result;
  int			tmp;

  if (rhs.getPrecision() > precision)
    return (rhs * *this);
  tmp = stringToValue(rhs.toString()) * this->nb;
  result = tmp;
  if (tmp != result)
    throw ExceptionCPU("Overflow Int16 * Int16");
  return (new OperandInt16(valToString(tmp)));
}

IOperand		*OperandInt16::operator/(const IOperand &rhs) const {
  short			result;

  if (rhs.getPrecision() > precision)
    return (rhs / *this);
  if (stringToValue(rhs.toString()) == 0)
    throw ExceptionCPU("Division by zero (Int16)");
  result = this->nb / stringToValue(rhs.toString());
  return (new OperandInt16(valToString(result)));
}

IOperand		*OperandInt16::operator%(const IOperand &rhs) const {
  short			result;

  if (rhs.getPrecision() > precision)
    return (rhs % *this);
  if (stringToValue(rhs.toString()) == 0)
    throw ExceptionCPU("Modulo by zero (Int16)");
  result = this->nb % stringToValue(rhs.toString());
  return (new OperandInt16(valToString(result)));
}
