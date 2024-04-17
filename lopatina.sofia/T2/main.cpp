#include <iostream>
#include <limits>
#include <vector>
#include <iterator>
#include <algorithm>
#include "data_struct.hpp"

int main()
{
  using namespace lopatina;

  std::vector<DataStruct> data;
  while (!std::cin.eof())
  {
    std::copy(
      std::istream_iterator<DataStruct>{std::cin},
      std::istream_iterator<DataStruct>{},
      std::back_inserter(data)
    );
    if (!std::cin)
    {
      std::cin.clear(std::ios::goodbit);
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
  std::sort(data.begin(), data.end());
  std::copy(
    std::begin(data),
    std::end(data),
    std::ostream_iterator<DataStruct>(std::cout, "\n")
  );
  return 0;
}
