#include <cassert>
#include <cstring>
#include <iostream>
#include <json/json_value.hpp>

using json = Fruit::JsonValue;

int main() {
  {
    json::list_t a = {1, 2, 3};
    json j = a;
    std::cout << j.serialize() << std::endl;
    assert(std::strcmp(j.serialize().c_str(), "[1,2,3]") == 0);
    std::cout << "Checkpoint #1" << std::endl;
  }
  {
    json j = json::list_t {
      json::list_t{1, 2}, json::list_t{3, 4},
          5
    };
    std::cout << j.serialize() << std::endl;
    assert(std::strcmp(j.serialize().c_str(), "[[1,2],[3,4],5]") == 0);
    std::cout << "Checkpoint #2" << std::endl;
  }
}
