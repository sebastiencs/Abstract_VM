//
// CPU.cpp for epitech in /home/chapuis_s/rendu/
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Thu Feb 19 15:00:16 2015 chapui_s
// Last update Tue Feb 24 18:09:20 2015 chapui_s
//

#include "CPU.hpp"

CPU::t_ope	tabCreate[] = {
  { Int8, NULL },
  { Int16, NULL },
  { Int32, NULL },
  { Float, NULL },
  { Double, NULL }
};

CPU::CPU(Stack *s, int isSI) {
  stack = s;
  isStandarInput = isSI;
  tabCreate[0].create = &CPU::createInt8;
  tabCreate[1].create = &CPU::createInt16;
  tabCreate[2].create = &CPU::createInt32;
  tabCreate[3].create = &CPU::createFloat;
  tabCreate[4].create = &CPU::createDouble;
}

IOperand	*CPU::createInt8(const std::string &s) {
#ifdef DEBUG
  std::cout << "Create Int8 " << s << std::endl;
#endif // !DEBUG
  return (new OperandInt8(s));
}

IOperand	*CPU::createInt16(const std::string &s) {
#ifdef DEBUG
  std::cout << "Create Int16 " << s << std::endl;
#endif // !DEBUG
  return (new OperandInt16(s));
}

IOperand	*CPU::createInt32(const std::string &s) {
#ifdef DEBUG
  std::cout << "Create Int32 " << s << std::endl;
#endif // !DEBUG
  return (new OperandInt32(s));
}

IOperand	*CPU::createFloat(const std::string &s) {
#ifdef DEBUG
  std::cout << "Create Float " << s << std::endl;
#endif // !DEBUG
  return (new OperandFloat(s));
}

IOperand	*CPU::createDouble(const std::string &s) {
#ifdef DEBUG
  std::cout << "Create Double " << s << std::endl;
#endif // !DEBUG
  return (new OperandDouble(s));
}

IOperand	*CPU::createOperand(eOperandType type, const std::string &value) {
  int		i;

  for (i = 0; type != tabCreate[i].type; ++i);
  return ((this->*(tabCreate[i].create))(value));
}

int		CPU::push(Instruction const *i) {
  register1 = createOperand(i->getPrecision(), i->getNumber());
  if (register1)
    stack->push(register1);
  return (0);
}

int		CPU::assert(Instruction const *i) {
  register1 = stack->top();
  if (!register1)
    throw ExceptionCPU("Assert: no value on stack");
  if (i->getPrecision() != register1->getType())
    throw ExceptionCPU("Assert: value on stack is different type");
  if (register1->toString() != i->getNumber())
    throw ExceptionCPU("Assert: value on stack is different");
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
