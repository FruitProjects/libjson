#include <cassert>
#include <cstring>
#include <iostream>
#include <json/json_value.hpp>

using json = Fruit::JsonValue;

int main() {
  {
    json a;
    std::cout << a.serialize() << std::endl;
    assert(std::strcmp(a.serialize().c_str(), "null") == 0);
    std::cout << "Checkpoint #1" << std::endl;
  }
  {
    json a = nullptr;
    std::cout << a.serialize() << std::endl;
    assert(std::strcmp(a.serialize().c_str(), "null") == 0);
    std::cout << "Checkpoint #2" << std::endl;
  }
  {
    json a = false;
    std::cout << a.serialize() << std::endl;
    assert(std::strcmp(a.serialize().c_str(), "false") == 0);
    std::cout << "Checkpoint #3" << std::endl;
  }
  {
    json a = true;
    std::cout << a.serialize() << std::endl;
    assert(std::strcmp(a.serialize().c_str(), "true") == 0);
    std::cout << "Checkpoint #4" << std::endl;
  }
  {
    json a = 4;
    std::cout << a.serialize() << std::endl;
    assert(std::strcmp(a.serialize().c_str(), "4") == 0);
    std::cout << "Checkpoint #5" << std::endl;
  }
  {
    json a = 4.0;
    std::cout << a.serialize() << std::endl;
    assert(std::strcmp(a.serialize().c_str(), "4.000000") == 0);
    std::cout << "Checkpoint #6" << std::endl;
  }
}
