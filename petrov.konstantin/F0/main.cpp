#include <iostream>
#include <set>
#include <functional>
#include <algorithm>
#include <fstream>
#include <iterator>
#include "utils.hpp"

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr << "<BRUH>\n";
    return 1;
  }

  using namespace petrov;
  setType alph(compareNodes);

  std::ifstream in(argv[1], std::ios::in);
  using isIt = std::istream_iterator< char >;
  auto addToAlph = std::bind(&addToSet, std::ref(alph), std::placeholders::_1);
  std::for_each(isIt(in), isIt(), addToAlph);
  in.close();

  using outIt = std::ostream_iterator< Node >;
  std::copy(alph.cbegin(), alph.cend(), outIt(std::cout, "\n"));

  return 0;
}
