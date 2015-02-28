//
// OperandDouble.cpp for Abstract_VM-master in /home/denel-_l/rendu/Abstract_VM-master
//
// Made by denel-_l
// Login   <denel-_l@epitech.net>
//
// Started on  Sun Feb 22 14:26:41 2015 denel-_l
// Last update Sat Feb 28 18:16:46 2015 chapui_s
//

#include "OperandFloat.hpp"
#include <limits>

OperandFloat::OperandFloat(std::string const &s) : str(s) {
  double	tmp;

  std::stringstream(s) >> tmp;
  nb = tmp;
  if (ABS_NB(nb - tmp) > std::numeric_limits<float>::epsilon())
    throw ExceptionCPU("Overflow/Underflow on Float creation");
  precision = FLOAT;
  type = Float;
}

std::string const	&OperandFloat::toString() const {
  return (str);
}

int			OperandFloat::getPrecision() const {
  return (precision);
}

eOperandType		OperandFloat::getType() const {
  return (type);
}

std::string const	OperandFloat::valToString(float const& n) const {
  std::stringstream	ss;

  ss << n;
  return (ss.str());
}

float			OperandFloat::stringToValue(std::string const &s) const {
  std::stringstream	ss(s);
  float		val;

  ss >> val;
  return (val);
}

IOperand		*OperandFloat::operator+(const IOperand &rhs) const {
  float		result, tmp2;
  double		tmp;

  if (rhs.getPrecision() > precision)
    return (rhs + *this);
  tmp = this->nb + stringToValue(rhs.toString());
  result = tmp;
  tmp2 = result;
  if (std::fabs(tmp - tmp2) > std::numeric_limits<float>::epsilon())
    throw ExceptionCPU("Overflow Float + Float");
  return (new OperandFloat(valToString(tmp)));
}

IOperand		*OperandFloat::operator-(const IOperand &rhs) const {
  float		result, tmp2;
  double		tmp;

  if (rhs.getPrecision() > precision)
    return (rhs - *this);
  tmp = this->nb - stringToValue(rhs.toString());
  result = tmp;
  tmp2 = result;
  if (std::fabs(tmp - tmp2) > std::numeric_limits<float>::epsilon())
    throw ExceptionCPU("Underflow Float - Float");
  return (new OperandFloat(valToString(result)));
}

IOperand		*OperandFloat::operator*(const IOperand &rhs) const {
  float		result, tmp2;
  double		tmp;

  if (rhs.getPrecision() > precision)
    return (rhs * *this);
  tmp = stringToValue(rhs.toString()) * this->nb;
  result = tmp;
  tmp2 = result;
  if (std::fabs(tmp - tmp2) > std::numeric_limits<float>::epsilon())
    throw ExceptionCPU("Overflow Float * Float");
  return (new OperandFloat(valToString(tmp)));
}

IOperand		*OperandFloat::operator/(const IOperand &rhs) const {
  float		result;

  if (rhs.getPrecision() > precision)
    return (rhs / *this);
  if (stringToValue(rhs.toString()) == 0)
    throw ExceptionCPU("Division by zero (Float)");
  result = this->nb / stringToValue(rhs.toString());
  return (new OperandFloat(valToString(result)));
}

IOperand		*OperandFloat::operator%(const IOperand &rhs) const {
  float		result;

  if (rhs.getPrecision() > precision)
    return (rhs % *this);
  if (stringToValue(rhs.toString()) == 0)
    throw ExceptionCPU("Modulo by zero (Float)");
  result = std::fmod(this->nb, stringToValue(rhs.toString()));
  return (new OperandFloat(valToString(result)));
}
