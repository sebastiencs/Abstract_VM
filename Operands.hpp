//
// Operands.hpp for epitech in /home/chapuis_s/rendu/
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Sun Mar  1 01:16:42 2015 chapui_s
// Last update Sun Mar  1 05:49:49 2015 chapui_s
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

  virtual IOperand		*operator+(const IOperand &rhs) const;
  virtual IOperand		*operator-(const IOperand &rhs) const;
  virtual IOperand		*operator*(const IOperand &rhs) const;
  virtual IOperand		*operator/(const IOperand &rhs) const;
  virtual IOperand		*operator%(const IOperand &rhs) const;

  std::string const		valToString(T const &) const;
};

#endif // !OPERANDS_H_
