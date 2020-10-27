#include <fstream>
#include <iostream>

#include "interpreter.hxx"

int main(int argc, char** argv)
{
  if (argc<2) {
    std::cerr << "Usage: " << *argv << " [filename]" << std::endl;
    return 1;
  }

  std::ifstream source{argv[1]};
  if (!source.is_open()) {
    std::cerr << "Error: The given file \"" << argv[1] << "\" cannot be opened." << std::endl;
    std::exit(2);
  }

  interpreter{}.interpret(std::istreambuf_iterator<char>{source}, std::istreambuf_iterator<char>{});

  return 0;
}
