//
// AbstractVm.cpp for epitech in /home/chapuis_s/rendu/
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Wed Feb 18 06:08:18 2015 chapui_s
// Last update Sat Feb 28 18:01:53 2015 chapui_s
//

#include "avm.hpp"
#include "parser.hpp"

AbstractVm::t_cpu	cpuInstruction[] = {
  { "pop", &CPU::pop },
  { "add", &CPU::add },
  { "sub", &CPU::sub },
  { "mul", &CPU::mul },
  { "div", &CPU::div },
  { "mod", &CPU::mod },
  { "exit", &CPU::exit },
  { "push", &CPU::push },
  { "assert", &CPU::assert },
  { "dump", &CPU::dump },
  { "print", &CPU::print },
  { ";;", &CPU::exit }
};

AbstractVm::AbstractVm(std::istream &f)
  : parser((Parser*)0), stack((Stack*)0), cpu((CPU*)0)
{
  try {
    parser = new Parser(f);
    stack = new Stack();
    cpu = new CPU(stack, parser->getIsStandartInput());
  }
  catch (const std::bad_alloc &) {
    delete parser;
    delete stack;
    throw;
  }
}

AbstractVm::~AbstractVm() {
  stack->erase();
  delete parser;
  delete stack;
  delete cpu;
}

void		AbstractVm::Run() {
  Instruction	*instruction;
  int		i;

  try {
    while ((instruction = parser->GetInstruction())) {
#ifdef DEBUG
      std::cout << instruction->getInstruction() << " line: " << parser->getLine() << std::endl;
#endif // !DEBUG
      for (i = 0; instruction->getInstruction() != cpuInstruction[i].instStr; ++i);
      if (((cpu->*(cpuInstruction[i].inst))(instruction))) {
	delete instruction;
	break;
      }
      delete instruction;
    }
    if (!(parser->getIsStandartInput()) && i != 6)
      throw ExceptionCPU("Last instruction must be 'exit'");
    if (parser->getIsStandartInput() && i != 11)
      throw ExceptionCPU("Last instruction must be ';;'");
  }
  catch (const ExceptionParser &e) {
    std::cerr << e.what() << std::endl;
  }
  catch (const ExceptionCPU &e) {
    std::cerr << e.what() << " line " << parser->getLine() << std::endl;
  }
}
