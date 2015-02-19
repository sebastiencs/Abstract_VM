//
// Stack.cpp for epitech in /home/chapuis_s/rendu/
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Wed Feb 18 06:58:03 2015 chapui_s
// Last update Thu Feb 19 23:20:21 2015 chapui_s
//

#include <iostream>
#include "Stack.hpp"

int		Stack::push(IOperand *ope) {
  pile.push_back(ope);
  return (0);
}

int		Stack::pop() {
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
  if (pile.size() > 0)
    return (pile.back());
  return (NULL);
}
