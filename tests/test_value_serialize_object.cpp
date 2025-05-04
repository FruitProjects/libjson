#include <cassert>
#include <cstring>
#include <iostream>
#include <json/json_value.hpp>

using json = Fruit::JsonValue;

int main() {
  {
    json j = json::object_t {
      {"foo", std::string("bar")}, {"bar", std::string("foo")} };
    std::cout << j.serialize() << std::endl;
    assert(std::strcmp(j.serialize().c_str(), "{\"bar\": \"foo\",\"foo\": \"bar\"}") == 0);
    std::cout << "Checkpoint #1" << std::endl;
  }
}
