//
// Operands.hpp for epitech in /home/chapuis_s/rendu/
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Sun Mar  1 01:16:42 2015 chapui_s
// Last update Sun Mar  1 04:38:39 2015 chapui_s
//

#include "Operands.hpp"

template <typename T>
Operands<T>::Operands(eOperandType type, std::string const &s)
  : str(s), type(type)
{
  long double	tmp;

  std::stringstream(s) >> tmp;
  checkLimit(tmp);
}

template <typename T>
void			Operands<T>::checkLimit(long double const &nb) const {
  if (nb > std::numeric_limits<T>::max())
    throw ExceptionCPU("Overflow");
  if (nb < -(std::numeric_limits<T>::max()) - 1)
    throw ExceptionCPU("Underflow");
}

template <typename T>
std::string const	&Operands<T>::toString() const {
  return (str);
}

template <typename T>
eOperandType		Operands<T>::getType() const {
  return (type);
}

template <typename T>
int			Operands<T>::getPrecision() const {
  return ((int)type);
}

template <typename T>
std::string const	Operands<T>::valToString(T const &n) const {
  std::stringstream	ss;

  ss << n;
  return (ss.str());
}

template <>
std::string const	Operands<char>::valToString(char const &n) const {
  std::stringstream	ss;
  int			tmp;

  tmp = n;
  ss << tmp;
  return (ss.str());
}

template <typename T>
IOperand		*Operands<T>::operator+(const IOperand &rhs) const {
  IOperand		*updateType;
  IOperand		*result;

  if (getPrecision() >= rhs.getPrecision())
    return (computeAdd(this, &rhs));
  else {
    updateType = CreateOperand::createOperand(rhs.getType(), this->toString());
    result = *updateType + rhs;
    delete updateType;
    return (result);
  }
}

template <typename T>
IOperand		*Operands<T>::computeAdd(const IOperand *ope1, const IOperand *ope2) const {
  T			n1, n2;

  std::stringstream(ope1->toString()) >> n1;
  std::stringstream(ope2->toString()) >> n2;
  checkLimit(n1 + n2);
  return (new Operands<T>(this->getType(), valToString(n1 + n2)));
}

template <>
IOperand		*Operands<char>::computeAdd(const IOperand *ope1, const IOperand *ope2) const {
  int			n1, n2;

  std::stringstream(ope1->toString()) >> n1;
  std::stringstream(ope2->toString()) >> n2;
  checkLimit(n1 + n2);
  return (new Operands<char>(this->getType(), valToString(n1 + n2)));
}

template <typename T>
IOperand		*Operands<T>::operator-(const IOperand &rhs) const {
  IOperand		*updateType;
  IOperand		*result;

  if (getPrecision() >= rhs.getPrecision())
    return (computeSub(this, &rhs));
  else {
    updateType = CreateOperand::createOperand(rhs.getType(), this->toString());
    result = *updateType - rhs;
    delete updateType;
    return (result);
  }
}

template <typename T>
IOperand		*Operands<T>::computeSub(const IOperand *ope1, const IOperand *ope2) const {
  T			n1, n2;

  std::stringstream(ope1->toString()) >> n1;
  std::stringstream(ope2->toString()) >> n2;
  checkLimit(n1 - n2);
  return (new Operands<T>(this->getType(), valToString(n1 - n2)));
}

template <>
IOperand		*Operands<char>::computeSub(const IOperand *ope1, const IOperand *ope2) const {
  int			n1, n2;

  std::stringstream(ope1->toString()) >> n1;
  std::stringstream(ope2->toString()) >> n2;
  checkLimit(n1 - n2);
  return (new Operands<char>(this->getType(), valToString(n1 - n2)));
}

template <typename T>
IOperand		*Operands<T>::operator*(const IOperand &rhs) const {
  IOperand		*updateType;
  IOperand		*result;

  if (getPrecision() >= rhs.getPrecision())
    return (computeMul(this, &rhs));
  else {
    updateType = CreateOperand::createOperand(rhs.getType(), this->toString());
    result = *updateType * rhs;
    delete updateType;
    return (result);
  }
}

template <typename T>
IOperand		*Operands<T>::computeMul(const IOperand *ope1, const IOperand *ope2) const {
  T			n1, n2;

  std::stringstream(ope1->toString()) >> n1;
  std::stringstream(ope2->toString()) >> n2;
  checkLimit(n1 * n2);
  return (new Operands<T>(this->getType(), valToString(n1 * n2)));
}

template <>
IOperand		*Operands<char>::computeMul(const IOperand *ope1, const IOperand *ope2) const {
  int			n1, n2;

  std::stringstream(ope1->toString()) >> n1;
  std::stringstream(ope2->toString()) >> n2;
  checkLimit(n1 * n2);
  return (new Operands<char>(this->getType(), valToString(n1 * n2)));
}

template <typename T>
IOperand		*Operands<T>::operator/(const IOperand &rhs) const {
  IOperand		*updateType;
  IOperand		*result;

  if (getPrecision() >= rhs.getPrecision())
    return (computeDiv(this, &rhs));
  else {
    updateType = CreateOperand::createOperand(rhs.getType(), this->toString());
    result = *updateType / rhs;
    delete updateType;
    return (result);
  }
}

template <typename T>
IOperand		*Operands<T>::computeDiv(const IOperand *ope1, const IOperand *ope2) const {
  T			n1, n2;

  std::stringstream(ope1->toString()) >> n1;
  std::stringstream(ope2->toString()) >> n2;
  if (n2 == 0)
    throw ExceptionCPU("Division by zero");
  return (new Operands<T>(this->getType(), valToString(n1 / n2)));
}

template <>
IOperand		*Operands<char>::computeDiv(const IOperand *ope1, const IOperand *ope2) const {
  int			n1, n2;

  std::stringstream(ope1->toString()) >> n1;
  std::stringstream(ope2->toString()) >> n2;
  if (n2 == 0)
    throw ExceptionCPU("Division by zero");
  return (new Operands<char>(this->getType(), valToString(n1 / n2)));
}

template <typename T>
IOperand		*Operands<T>::operator%(const IOperand &rhs) const {
  IOperand		*updateType;
  IOperand		*result;

  if (getPrecision() >= rhs.getPrecision())
    return (computeMod(this, &rhs));
  else {
    updateType = CreateOperand::createOperand(rhs.getType(), this->toString());
    result = *updateType % rhs;
    delete updateType;
    return (result);
  }
}

template <typename T>
IOperand		*Operands<T>::computeMod(const IOperand *ope1, const IOperand *ope2) const {
  T			n1, n2;

  std::stringstream(ope1->toString()) >> n1;
  std::stringstream(ope2->toString()) >> n2;
  if (n2 == 0)
    throw ExceptionCPU("Modulo by zero");
  return (new Operands<T>(this->getType(), valToString(n1 % n2)));
}

template <>
IOperand		*Operands<char>::computeMod(const IOperand *ope1, const IOperand *ope2) const {
  int			n1, n2;

  std::stringstream(ope1->toString()) >> n1;
  std::stringstream(ope2->toString()) >> n2;
  if (n2 == 0)
    throw ExceptionCPU("Modulo by zero");
  return (new Operands<char>(this->getType(), valToString(n1 % n2)));
}

template <>
IOperand		*Operands<float>::computeMod(const IOperand *ope1, const IOperand *ope2) const {
  float			n1, n2;

  std::stringstream(ope1->toString()) >> n1;
  std::stringstream(ope2->toString()) >> n2;
  if (n2 == 0)
    throw ExceptionCPU("Modulo by zero");
  return (new Operands<float>(this->getType(), valToString(fmod(n1, n2))));
}

template <>
IOperand		*Operands<double>::computeMod(const IOperand *ope1, const IOperand *ope2) const {
  double		n1, n2;

  std::stringstream(ope1->toString()) >> n1;
  std::stringstream(ope2->toString()) >> n2;
  if (n2 == 0)
    throw ExceptionCPU("Modulo by zero");
  return (new Operands<double>(this->getType(), valToString(fmod(n1, n2))));
}

template class Operands<int>;
template class Operands<float>;
template class Operands<double>;
template class Operands<short>;
