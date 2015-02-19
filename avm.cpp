//
// avm.cpp for epitech in /home/chapui_s/rendu/cpp_abstractvm/avm.cpp
//
// Made by chapui_s
// Login   <chapui_s@epitech.eu>
//
// Started on  Mon Feb 16 03:08:40 2015 chapui_s
// Last update Thu Feb 19 20:08:40 2015 chapui_s
//

#include "parser.hpp"

void	puts(std::string &s) {
  std::cout << s << std::endl;
}

int		main(int argc, char **argv) {
  std::ifstream	file;
  int		i;

  // if (argc == 1)
  //   Parser();
  // else
  // {
    i = 1;
    while (i < argc) {
      file.open(argv[i]);
      if (file.good()) {
	try {
	  AbstractVm avm(file);
	  avm.Run();
	}
	catch (const std::exception &e) {
	  std::cerr << e.what() << std::endl;
	}
      }
      file.close();
      i += 1;
    }
  // }
  return (0);
}
