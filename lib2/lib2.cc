#include "lib2.hh"

#include <gz/msgs/Factory.hh>

#include <iostream>

void foo()
{
  std::vector<std::string> known_types;
  gz::msgs::Factory::Types(known_types);
  std::cout << "Known types: " << std::endl;
  for (const auto &t: known_types)
  {
      std::cout << t << std::endl;
  }
}
