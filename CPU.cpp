//
// CPU.cpp for epitech in /home/chapuis_s/rendu/
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Thu Feb 19 15:00:16 2015 chapui_s
// Last update Sun Mar  1 04:39:12 2015 chapui_s
//

#include "CPU.hpp"

CPU::CPU(Stack *s, int isSI) {
  stack = s;
  isStandarInput = isSI;
}

int		CPU::push(Instruction const *i) {
  register1 = CreateOperand::createOperand(i->getPrecision(), i->getNumber());
  if (register1)
    stack->push(register1);
  return (0);
}

int		CPU::assert(Instruction const *i) {
  long		int_tmp1, int_tmp2;
  double	double_tmp1, double_tmp2;

  register1 = stack->top();
  if (!register1)
    throw ExceptionCPU("Assert: no value on stack");
  if (i->getPrecision() != register1->getType())
    throw ExceptionCPU("Assert: value on stack is different type");
  if (i->getPrecision() == Float || i->getPrecision() == Double) {
    std::stringstream(register1->toString()) >> double_tmp1;
    std::stringstream(i->getNumber()) >> double_tmp2;
    if (double_tmp1 != double_tmp2)
      throw ExceptionCPU("Assert: value on stack is different");
  }
  else {
    std::stringstream(register1->toString()) >> int_tmp1;
    std::stringstream(i->getNumber()) >> int_tmp2;
    if (int_tmp1 != int_tmp2)
      throw ExceptionCPU("Assert: value on stack is different");
  }
  return (0);
}

int		CPU::dump(Instruction const *i) {
  (void)i;
  stack->dump();
  return (0);
}

int		CPU::print(Instruction const *i) {
  int		int_tmp;
  char		c;

  (void)i;
  register1 = stack->top();
  if (!register1 || register1->getType() != Int8)
    throw ExceptionCPU("print: value on stack is not Int8");
  std::stringstream(register1->toString()) >> int_tmp;
  c = int_tmp;
  std::cout << c << std::endl;
  return (0);
}

int		CPU::pop(Instruction const *i) {
  (void)i;
  if (!(register1 = stack->top()))
    throw ExceptionCPU("pop: No value on stack");
  delete register1;
  stack->pop();
  return (0);
}

int		CPU::add(Instruction const *i) {
  (void)i;
  register1 = stack->top();
  stack->pop();
  register2 = stack->top();
  stack->pop();
  if (!register1 || !register2) {
    delete register1;
    throw ExceptionCPU("add: There is not 2 values on stack");
  }
  register3 = (*register1) + (*register2);
  delete register1;
  delete register2;
  stack->push(register3);
  return (0);
}

int		CPU::sub(Instruction const *i) {
  (void)i;
  register1 = stack->top();
  stack->pop();
  register2 = stack->top();
  stack->pop();
  if (!register1 || !register2) {
    delete register1;
    throw ExceptionCPU("sub: There is not 2 values on stack");
  }
  register3 = (*register2) - (*register1);
  delete register1;
  delete register2;
  stack->push(register3);
  return (0);
}

int		CPU::mul(Instruction const *i) {
  (void)i;
  register1 = stack->top();
  stack->pop();
  register2 = stack->top();
  stack->pop();
  if (!register1 || !register2) {
    delete register1;
    throw ExceptionCPU("mul: There is not 2 values on stack");
  }
  register3 = (*register2) * (*register1);
  delete register1;
  delete register2;
  stack->push(register3);
  return (0);
}

int		CPU::div(Instruction const *i) {
  (void)i;
  register1 = stack->top();
  stack->pop();
  register2 = stack->top();
  stack->pop();
  if (!register1 || !register2) {
    delete register1;
    throw ExceptionCPU("div: There is not 2 values on stack");
  }
  register3 = (*register2) / (*register1);
  delete register1;
  delete register2;
  stack->push(register3);
  return (0);
}

int		CPU::mod(Instruction const *i) {
  (void)i;
  register1 = stack->top();
  stack->pop();
  register2 = stack->top();
  stack->pop();
  if (!register1 || !register2) {
    delete register1;
    throw ExceptionCPU("mod: There is not 2 values on stack");
  }
  register3 = (*register2) % (*register1);
  delete register1;
  delete register2;
  stack->push(register3);
  return (0);
}

int		CPU::exit(Instruction const *i) {
  return ((i->getInstruction() == "exit" && isStandarInput == 1) ? (0) : (1));
}
