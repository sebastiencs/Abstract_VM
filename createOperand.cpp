//
// createOperand.cpp for epitech in /home/chapuis_s/rendu/
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Sun Mar  1 02:13:43 2015 chapui_s
// Last update Sun Mar  1 05:28:42 2015 chapui_s
//

#include "createOperand.hpp"

CreateOperand::t_ope	tabCreate[] = {
  { Int8, NULL },
  { Int16, NULL },
  { Int32, NULL },
  { Float, NULL },
  { Double, NULL }
};

CreateOperand::t_ope	*CreateOperand::getFunc() {
  tabCreate[0].create = &CreateOperand::createInt8;
  tabCreate[1].create = &CreateOperand::createInt16;
  tabCreate[2].create = &CreateOperand::createInt32;
  tabCreate[3].create = &CreateOperand::createFloat;
  tabCreate[4].create = &CreateOperand::createDouble;
  return (&tabCreate[0]);
}

IOperand	*CreateOperand::createOperand(eOperandType type, const std::string &value) {
  int		i;
  t_ope		*tab_func;

  tab_func = getFunc();
  for (i = 0; type != tab_func[i].type; ++i);
  return ((*(tab_func[i].create))(value));
}

#include "Operands.hpp"

IOperand	*CreateOperand::createInt8(const std::string &s) {
#ifdef DEBUG
  std::cout << "Create Int8 " << s << std::endl;
#endif // !DEBUG
  return (new Operands<char>(Int8, s));
}

IOperand	*CreateOperand::createInt16(const std::string &s) {
#ifdef DEBUG
  std::cout << "Create Int16 " << s << std::endl;
#endif // !DEBUG
  return (new Operands<short>(Int16, s));
}

IOperand	*CreateOperand::createInt32(const std::string &s) {
#ifdef DEBUG
  std::cout << "Create Int32 " << s << std::endl;
#endif // !DEBUG
  return (new Operands<int>(Int32, s));
}

IOperand	*CreateOperand::createFloat(const std::string &s) {
#ifdef DEBUG
  std::cout << "Create Float " << s << std::endl;
#endif // !DEBUG
  return (new Operands<float>(Float, s));
}

IOperand	*CreateOperand::createDouble(const std::string &s) {
#ifdef DEBUG
  std::cout << "Create Double " << s << std::endl;
#endif // !DEBUG
  return (new Operands<double>(Double, s));
}
