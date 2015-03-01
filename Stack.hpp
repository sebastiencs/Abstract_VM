//
// Stack.hpp for epitech in /home/chapuis_s/rendu/
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Wed Feb 18 06:45:58 2015 chapui_s
// Last update Sun Mar  1 02:08:18 2015 chapui_s
//

#ifndef STACK_H_
# define STACK_H_

# include <list>
# include "avm.hpp"

class		Stack
{
private:
  std::list<IOperand *>	pile;
public:
  Stack() {};
  ~Stack() {};
  int		push(IOperand *);
  int		pop();
  int		dump() const;
  IOperand	*top() const;
  void		erase();
};

#endif // !STACK_H_
