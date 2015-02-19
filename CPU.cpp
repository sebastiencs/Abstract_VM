//
// CPU.cpp for epitech in /home/chapuis_s/rendu/
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Thu Feb 19 15:00:16 2015 chapui_s
// Last update Thu Feb 19 22:58:00 2015 chapui_s
//

#include "CPU.hpp"

CPU::t_ope	tabCreate[] = {
  { Int8, NULL },
  { Int16, NULL },
  { Int32, NULL },
  { Float, NULL },
  { Double, NULL }
};

CPU::CPU(Stack *s) {
  stack = s;
  tabCreate[0].create = &CPU::createInt8;
  tabCreate[1].create = &CPU::createInt16;
  tabCreate[2].create = &CPU::createInt32;
  tabCreate[3].create = &CPU::createFloat;
  tabCreate[4].create = &CPU::createDouble;
}

IOperand	*CPU::createInt8(const std::string &s) {
  std::cout << "Create Int8 " << s << std::endl;
  return (new OperandInt8(s));
}

IOperand	*CPU::createInt16(const std::string &s) {
  std::cout << "Create Int16 " << s << std::endl;
  return (new OperandInt16(s));
}

IOperand	*CPU::createInt32(const std::string &s) {
  (void)s;
  std::cout << "Create 32" << std::endl;
  return (NULL);
}

IOperand	*CPU::createFloat(const std::string &s) {
  (void)s;
  return (NULL);
}

IOperand	*CPU::createDouble(const std::string &s) {
  (void)s;
  return (NULL);
}

IOperand	*CPU::createOperand(eOperandType type, const std::string &value) {
  int		i;

  for (i = 0; type != tabCreate[i].type; ++i);
  return ((this->*(tabCreate[i].create))(value));
}

int		CPU::push(Instruction const *i) {
  IOperand	*value;

  value = createOperand(i->getPrecision(), i->getNumber());
  if (value)
    stack->push(value);
  return (0);
}

int		CPU::assert(Instruction const *i) {
  IOperand	*tmp;

  tmp = stack->top();
  if (!tmp)
    throw ExceptionCPU("Assert: no value on stack");
  if (i->getPrecision() != tmp->getType())
    throw ExceptionCPU("Assert: value on stack is different type");
  if (tmp->toString() != i->getNumber())
    throw ExceptionCPU("Assert: value on stack is different");
  return (0);
}

int		CPU::dump(Instruction const *i) {
  (void)i;
  stack->dump();
  return (0);
}

int		CPU::print(Instruction const *i) {
  IOperand	*tmp;
  int		int_tmp;
  char		c;

  (void)i;
  tmp = stack->top();
  if (!tmp || tmp->getType() != Int8)
    throw ExceptionCPU("print: value on stack is not Int8");
  std::stringstream(tmp->toString()) >> int_tmp;
  c = int_tmp;
  std::cout << c << std::endl;
  return (0);
}

int		CPU::pop(Instruction const *i) {
  (void)i;
  if (!stack->top())
    throw ExceptionCPU("pop: No value on stack");
  stack->pop();
  return (0);
}

int		CPU::add(Instruction const *i) {
  IOperand	*result = NULL, *a = NULL, *b = NULL;

  (void)i;
  a = stack->top();
  stack->pop();
  b = stack->top();
  stack->pop();
  if (!a || !b)
    throw ExceptionCPU("add: There is not 2 values on stack");
  result = (*a) + (*b);
  delete a;
  delete b;
  stack->push(result);
  return (0);
}

int		CPU::sub(Instruction const *i) {
  IOperand	*result, *a, *b;

  (void)i;
  a = stack->top();
  stack->pop();
  b = stack->top();
  stack->pop();
  if (!a || !b)
    throw ExceptionCPU("add: There is not 2 values on stack");
  result = (*b) - (*a);
  delete a;
  delete b;
  stack->push(result);
  return (0);
}

int		CPU::mul(Instruction const *i) {
  IOperand	*result, *a, *b;

  (void)i;
  a = stack->top();
  stack->pop();
  b = stack->top();
  stack->pop();
  if (!a || !b)
    throw ExceptionCPU("add: There is not 2 values on stack");
  result = (*b) * (*a);
  delete a;
  delete b;
  stack->push(result);
  return (0);
}

int		CPU::div(Instruction const *i) {
  IOperand	*result, *a = NULL, *b = NULL;

  (void)i;
  a = stack->top();
  stack->pop();
  b = stack->top();
  stack->pop();
  if (!a || !b)
    throw ExceptionCPU("add: There is not 2 values on stack");
  result = (*b) / (*a);
  delete a;
  delete b;
  stack->push(result);
  return (0);
  return (0);
}

int		CPU::mod(Instruction const *i) {
  IOperand	*result, *a, *b;

  (void)i;
  a = stack->top();
  stack->pop();
  b = stack->top();
  stack->pop();
  if (!a || !b)
    throw ExceptionCPU("add: There is not 2 values on stack");
  result = (*b) % (*a);
  delete a;
  delete b;
  stack->push(result);
  return (0);
}

int		CPU::exit(Instruction const *i) {
  (void)i;
  std::cout << "exit" << std::endl;
  return (0);
}
