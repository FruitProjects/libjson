#include <json/json_value.hpp>

using Json = Fruit::JsonValue;

int main() {

  Json nul = nullptr;
  
  Json bfalse = false;
  Json btrue = true;

  Json inum = 4;
  Json dnum = 4.0;

  Json s = std::string("Hello, World");

  Json l = {{Json{true}, Json{false}, Json{4.0}}};

  Json d = { {{ "key1", Json{true} }, {"key2", Json{false}} }};
  
}
