//
// IOperand.hpp for epitech in /home/chapuis_s/rendu/
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Wed Feb 18 06:48:27 2015 chapui_s
// Last update Sun Mar  1 03:41:30 2015 chapui_s
//

#ifndef IOPERAND_H_
# define IOPERAND_H_

# include <string>

enum eOperandType { Int8, Int16, Int32, Float, Double };

class		IOperand
{
 public:

  virtual std::string const & toString() const = 0;

  virtual int getPrecision() const = 0;
  virtual eOperandType getType() const = 0;

  virtual IOperand * operator+(const IOperand &rhs) const = 0;
  virtual IOperand * operator-(const IOperand &rhs) const = 0;
  virtual IOperand * operator*(const IOperand &rhs) const = 0;
  virtual IOperand * operator/(const IOperand &rhs) const = 0;
  virtual IOperand * operator%(const IOperand &rhs) const = 0;

  virtual ~IOperand() {}
};

#endif // !IOPERAND_H_
