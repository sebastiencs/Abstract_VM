//
// Stack.cpp for epitech in /home/chapuis_s/rendu/
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Wed Feb 18 06:58:03 2015 chapui_s
// Last update Fri Feb 20 01:20:35 2015 chapui_s
//

#include <iostream>
#include "Stack.hpp"

int		Stack::push(IOperand *ope) {
  pile.push_back(ope);
  return (0);
}

int		Stack::pop() {
  if (pile.size())
    pile.pop_back();
  return (0);
}

int		Stack::dump() const {
  for (std::list<IOperand *>::const_iterator it = pile.end(); it != pile.begin();) {
    --it;
    std::cout << (*it)->toString() << std::endl;
  }
  return (0);
}

IOperand	*Stack::top() const {
  if (pile.size())
    return (pile.back());
  return (NULL);
}

void		Stack::erase() {
  std::list<IOperand *>::iterator it = pile.begin();
  while (pile.size() > 0) {
    delete (*it);
    pile.erase(it);
    it = pile.begin();
  }
}
