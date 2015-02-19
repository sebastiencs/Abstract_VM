//
// IOperand.hpp for epitech in /home/chapuis_s/rendu/
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Wed Feb 18 06:48:27 2015 chapui_s
// Last update Thu Feb 19 22:08:01 2015 chapui_s
//

#ifndef IOPERAND_H_
# define IOPERAND_H_

# include <string>
//# include "avm.hpp"

enum eOperandType { Int8, Int16, Int32, Float, Double };
enum eOperandPrecision { INT8 = 8, INT16 = 16, INT32 = 32, FLOAT = 32, DOUBLE = 64 };

class		IOperand
{
 public:

  virtual std::string const & toString() const = 0; // Renvoie une string reprensentant l’instance

  virtual int getPrecision() const = 0; // Renvoie la precision du type de l’instance
  virtual eOperandType getType() const = 0; // Renvoie le type de l’instance. Voir plus bas

  virtual IOperand * operator+(const IOperand &rhs) const = 0; // Somme
  virtual IOperand * operator-(const IOperand &rhs) const = 0; // Difference
  virtual IOperand * operator*(const IOperand &rhs) const = 0; // Produit
  virtual IOperand * operator/(const IOperand &rhs) const = 0; // Quotient
  virtual IOperand * operator%(const IOperand &rhs) const = 0; // Modulo

  virtual ~IOperand() {}
};

#endif // !IOPERAND_H_
