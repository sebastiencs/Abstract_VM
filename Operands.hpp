//
// Operands.hpp for epitech in /home/chapuis_s/rendu/
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Sun Mar  1 01:16:42 2015 chapui_s
// Last update Sun Mar  1 03:56:38 2015 chapui_s
//

#ifndef OPERANDS_H_
# define OPERANDS_H_

# include <limits>
# include "CPU.hpp"
# include "IOperand.hpp"
# include <typeinfo>
# include <sstream>
# include "CPU.hpp"

template <typename T>
class			Operands : public IOperand
{
private:
  std::string const	str;
  // T			nb;
  eOperandType		type;

  IOperand		*computeAdd(const IOperand *ope1, const IOperand *ope2) const;
  IOperand		*computeSub(const IOperand *ope1, const IOperand *ope2) const;
  IOperand		*computeMul(const IOperand *ope1, const IOperand *ope2) const;
  IOperand		*computeDiv(const IOperand *ope1, const IOperand *ope2) const;
  IOperand		*computeMod(const IOperand *ope1, const IOperand *ope2) const;

  void			checkLimit(long double const &) const;

public:
  Operands(eOperandType, std::string const &);

  virtual std::string const	&toString() const;
  virtual int			getPrecision() const;
  virtual eOperandType		getType() const;

  virtual IOperand * operator+(const IOperand &rhs) const;
  virtual IOperand * operator-(const IOperand &rhs) const;
  virtual IOperand * operator*(const IOperand &rhs) const;
  virtual IOperand * operator/(const IOperand &rhs) const;
  virtual IOperand * operator%(const IOperand &rhs) const;

  std::string const	valToString(T const &) const;
};

// template <typename T>
// Operands<T>::Operands(eOperandType type, std::string const &s)
//   : str(s)
// {
//   std::stringstream	ss(s);
//   this->type = type;
//   ss >> nb;
// }

// template <>
// Operands<char>::Operands(eOperandType type, std::string const &s)
//   : str(s)
// {
//   int		tmp;

//   this->type = type;
//   std::stringstream(s) >> tmp;
//   nb = tmp;
// }

// template <typename T>
// std::string const	&Operands<T>::toString() const {
//   return (str);
// }

// template <typename T>
// eOperandType		Operands<T>::getType() const {
//   return (type);
// }

// template <typename T>
// int			Operands<T>::getPrecision() const {
//   return ((int)type);
// }

// template <typename T>
// std::string const	Operands<T>::valToString(T const &n) const {
//   std::stringstream	ss;

//   if (typeid(n).name() == typeid(char).name())
//     ss << (int)n;
//   else
//     ss << n;
//   return (ss.str());
// }

// template <typename T>
// IOperand		*Operands<T>::operator+(const IOperand &rhs) const {
//   IOperand		*updateType;
//   IOperand		*result;

//   if (getPrecision() >= rhs.getPrecision())
//     return (computeAdd(this, &rhs));
//   else {
//     updateType = CreateOperand::createOperand(rhs.getType(), this->toString());
//     result = *updateType + rhs;
//     delete updateType;
//     return (result);
//   }
// }

// template <typename T>
// IOperand		*Operands<T>::computeAdd(const IOperand *ope1, const IOperand *ope2) const {
//   T			n1, n2;

//   std::stringstream(ope1->toString()) >> n1;
//   std::stringstream(ope2->toString()) >> n2;
//   return (new Operands<T>(this->getType(), valToString(n1 + n2)));
// }

// template <>
// IOperand		*Operands<char>::computeAdd(const IOperand *ope1, const IOperand *ope2) const {
//   int			n1, n2;

//   std::stringstream(ope1->toString()) >> n1;
//   std::stringstream(ope2->toString()) >> n2;
//   return (new Operands<char>(this->getType(), valToString(n1 + n2)));
// }

#endif // !OPERANDS_H_
