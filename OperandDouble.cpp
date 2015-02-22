//
// OperandDouble.cpp for Abstract_VM-master in /home/denel-_l/rendu/Abstract_VM-master
//
// Made by denel-_l
// Login   <denel-_l@epitech.net>
//
// Started on  Sun Feb 22 14:26:41 2015 denel-_l
// Last update Sun Feb 22 22:10:01 2015 denel-_l
//

#include "OperandDouble.hpp"
#include <limits>

OperandDouble::OperandDouble(std::string const &s) : str(s) {
  double	tmp;

  std::stringstream(s) >> tmp;
  nb = tmp;
  if (tmp ==  std::numeric_limits<double>::max() || tmp == std::numeric_limits<double>::min())
    throw ExceptionCPU("Overflow/Underflow on Double creation");
  precision = DOUBLE;
  type = Double;
}

std::string const	&OperandDouble::toString() const {
  return (str);
}

int			OperandDouble::getPrecision() const {
  return (precision);
}

eOperandType		OperandDouble::getType() const {
  return (type);
}

std::string const	OperandDouble::valToString(int const& n) const {
  std::stringstream	ss;

  ss << n;
  return (ss.str());
}

int			OperandDouble::stringToValue(std::string const &s) const {
  std::stringstream	ss(s);
  double			val;

  ss >> val;
  return (val);
}

IOperand		*OperandDouble::operator+(const IOperand &rhs) const {
  double			result;
  double			tmp;

  if (rhs.getPrecision() > precision)
    return (rhs + *this);
  tmp = this->nb + stringToValue(rhs.toString());
  result = tmp;
  if (tmp ==  std::numeric_limits<double>::max() || tmp == std::numeric_limits<double>::min())
    throw ExceptionCPU("Underflow Double + Double");
  return (new OperandDouble(valToString(tmp)));
}

IOperand		*OperandDouble::operator-(const IOperand &rhs) const {
  double			result;
  double			tmp;

  if (rhs.getPrecision() > precision)
    return (rhs - *this);
  tmp = this->nb - stringToValue(rhs.toString());
  result = tmp;
  if (tmp ==  std::numeric_limits<double>::max() || tmp == std::numeric_limits<double>::min())
    throw ExceptionCPU("Underflow Double - Double");
  return (new OperandDouble(valToString(result)));
}

IOperand		*OperandDouble::operator*(const IOperand &rhs) const {
  double			result;
  double			tmp;

  if (rhs.getPrecision() > precision)
    return (rhs * *this);
  tmp = stringToValue(rhs.toString()) * this->nb;
  result = tmp;
  if (tmp ==  std::numeric_limits<double>::max() || tmp == std::numeric_limits<double>::min())
    throw ExceptionCPU("Overflow Double * Double");
  return (new OperandDouble(valToString(tmp)));
}

IOperand		*OperandDouble::operator/(const IOperand &rhs) const {
  double			result;

  if (rhs.getPrecision() > precision)
    return (rhs / *this);
  if (stringToValue(rhs.toString()) == 0)
    throw ExceptionCPU("Division by zero (Double)");
  result = this->nb / stringToValue(rhs.toString());
  return (new OperandDouble(valToString(result)));
}

IOperand		*OperandDouble::operator%(const IOperand &rhs) const {
  double			result;

  if (rhs.getPrecision() > precision)
    return (rhs % *this);
  if (stringToValue(rhs.toString()) == 0)
    throw ExceptionCPU("Modulo by zero (Double)");
  //  result = this->nb % stringToValue(rhs.toString());
  return (new OperandDouble(valToString(result)));
}
