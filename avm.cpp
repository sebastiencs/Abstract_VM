//
// avm.cpp for epitech in /home/chapui_s/rendu/cpp_abstractvm/avm.cpp
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Mon Feb 16 03:08:40 2015 chapui_s
// Last update Tue Feb 24 18:06:11 2015 chapui_s
//

#include "parser.hpp"

int		main(int argc, char **argv) {
  std::ifstream	file;
  int		i;

  if (argc == 1) {
    AbstractVm avm;
    avm.Run();
  }
  else
  {
    i = 1;
    while (i < argc) {
      file.open(argv[i]);
      if (argc > 2)
	std::cout << "=== BEGIN FILE: " << argv[i] << " ===" << std::endl;
      if (file.good()) {
	try {
	  AbstractVm avm(file);
	  avm.Run();
	}
	catch (const std::exception &e) {
	  std::cerr << e.what() << std::endl;
	}
      }
      if (argc > 2)
	std::cout << "===  END FILE:  " << argv[i] << " ===" << std::endl;
      file.close();
      i += 1;
    }
  }
  return (0);
}
